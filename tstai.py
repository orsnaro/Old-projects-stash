"""
								  Coder : Omar
								  Version : v---
								  Date :  9 / 4 / 2023
								  Code Type :  CV | OCR => smart_parking_project
								  Title : Smart Parking System
								  Interpreter : cPython  v3.11.0 [Compiler : MSC v.1933 AMD64]
"""

import cv2
import numpy as np
import pytesseract as tsr
import garage_db as db

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
# TODO : use cuda and umat for frames and imaged instead of normal matrices when GPU accel is active
# TODO : show a  timer in  video ( 5 ~ 10 sec )  use cv2.puttext()
# TODO : add audio feedback 
# TODO : car plate / license id simple  template detection
# TODO : feature and object  matching/tracking 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#


 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def render_timer ( frame : np.ndarray , timer : int ) -> np.ndarray : ... 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def make_rectangle_obj( frame : np.ndarray  , id_dimension : tuple  , color : str ) -> np.ndarray : 
	"""
		1. specs of rectangle to be rendered in live video for guiding end user
  
		2. get points to position helper rectangle in center
  
		3. define rectangle object to be rendered on video frame

		* Returns:
			 rectangle_obj , [(x1,y1) , (x2 , y2)]
	"""
	#specs of rectangle to be rendered in live video for guiding end user
	blue  = (255 , 0 , 0)
	green = ( 0  , 255 , 0)
	red   = ( 0  , 0 , 255)
	x1 , x2 , y1 , y2 = [None for i in range(4)]
 
	rec_spec = {
    'top_left_coordinate'  : tuple , 
    'bot_right_coordinate' : tuple  ,
    'color' : (red if color == 'red' else green ), 
    'thickness' : 2 ,
    }
	
	#get points to position helper rectangle in center
	y_center , x_center , _ = [ int(x) // 2 for x in frame.shape ]
		#top left 
	x1 , y1 = x_center - id_dimension[0] // 2 , y_center - id_dimension[1] // 2
		#bot_right
	x2 , y2 = x_center + id_dimension[0] // 2 , y_center + id_dimension[1] // 2	
		#make rec_in_center
	rec_spec['top_left_coordinate'] , rec_spec['bot_right_coordinate'] = (x1 , y1) , (x2 , y2)
	
	
	frame_rect_obj = cv2.rectangle ( frame , *rec_spec.values() )
    
    
	pos = [(x1 , y1 ) , (x2 , y2)]
	return frame_rect_obj , pos
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
	
 

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def check_gpu_accl () -> tuple :
	"""
	* use only  inside video_settings()

	* NOTE 1: 
 				this fuctntion gets exactly whose api  enabled  cuda or opencl
				and prefers opencl if both are enbaled 
				due to it being opensource and was writtern in an PC using AMD GPU
    

	* NOTE 2:
 				depending on used GPU acceleration main function will call
				the appropriate ocr reader function
    

	* NOTE 3: 
 				if OpenCL enabled use cv2.UMat to save frames in and then process them
				after that convert them back to cv2.Mat
				if cuda is enabled use cv2.cudaGpuMat instead of cv2.UMat 
				and cv2.cuda.foo() instead of cv2.foo() in some opencv-python functions
    
    
  
	* Returns:
 		tuple (is_enabled? , gpu_type 2== cuda 1==opencl)
  
	"""

	#check if cuda / opencl is enabled  
	cuda_available : bool = cv2.cuda.getCudaEnableDeviceCount() > 0
	cuda_enabled   : bool = 'CUDA'	in cv2.getBuildInformation()
	
	opencl_enabled : bool = cv2.ocl.haveOpenCl()
	cv2.ocl.setUseOpenCl(True) if opencl_enabled else False

	#alternative check for opencl 
	# opencl_enabled : bool = 'OpenCL' in cv2.getBuildInformation()
 
 
 	#list 1st indx = true if any api is enabled  , 2nd indx is to specify the enabled api -> 1 = cuda , 2 = opencl
	gpu_accel_enabled : list = [False  , None]
 
	if cuda_enabled and cuda_available : 
		gpu_accel_enabled [:] = True , 1
  
	if opencl_enabled :
		gpu_accel_enabled [:] = True , 2
	
	return tuple ( gpu_accel_enabled ) 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def enable_multithreading () : ... #in case gpu acceleration is not enough to maintain stable 30fps

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def video_settings_setup (cam_indx : int  = 0, fps : int = 30 , vid_time_sec : int = 10, res : tuple = (1366 , 768)) -> tuple :
	"""
	* This function does set up the video objects
 
		* gpu_accel == 0  no GPU acceleration found 
 
		* gpu_accel == 1  Cuda GPU acceleration found
 
		* gpu_accel == 2  OpenCl GPU acceleration found
 
	* Returns :
		vid , fps , frametime , vid_time_sec , active_gpu_api
  
	* NOTE 1:
		* active_gpu_api == 0 (no active accel api)
		* active_gpu_api == 1 (OpenCL)
		* active_gpu_api == 2 (Cuda)

	"""
	#set the path to the tesseract dir ( not needed if you added it to win. env. variables)
	tsr.pytesseract.tesseract_cmd =  r'C:\Program Files\Tesseract-OCR\tesseract.exe'
	
	is_gpu_accel_enabled  , gpu_api = check_gpu_accl () 
	if is_gpu_accel_enabled :
		if gpu_api == 2 : #use Cuda video object
			#you can change video I/O backends used by adding  the argument :
			#cv2.CAP_DSHOW  (Dshow is the default in my omar-pc)
			vid = cv2.cuda.VideoCapture(cam_indx , cv2.CAP_DSHOW)
		else : #opencl
			vid = cv2.VideoCapture(cam_indx , cv2.CAP_DSHOW)
	else : #DEFAULT 
		vid = cv2.VideoCapture(cam_indx , cv2.CAP_DSHOW)

	#set custom res
	vid.set(cv2.CAP_PROP_FRAME_WIDTH , res[0]) 
	vid.set(cv2.CAP_PROP_FRAME_HEIGHT, res[1])
   # default res on omarpc obs vritual cam plugin -> (height_Y : 480 , width_X : 640)
	
 
	#frametime is needed to put as cv2.waitkey() argument 
	frametime = 1000 // fps 

	return vid , fps , frametime , vid_time_sec , gpu_api
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def proccess_vid_frame( _frame : np.ndarray ) -> np.ndarray :
		"""
		1. threshold frame
		2. blur frame
		3. erode/dilate frame by one itteration
		4. deskew frame (soon)

		Returns:
			final_img
	"""
		#original video frame with out the rectangle and timer is what we will process
		img = frame 
		#make the rectangle object to help position ID card when scanning (initially RED)
		frame , pos = make_rectangle_obj( frame , id_dimension , ('red' if is_valid == 0 else 'green'))
		#show camera at  fps ( end user visual aid )
		cv2.imshow("Camera", frame)

		#crop image to get the id card only (with + 5px than actuall id size)
		img = img[ pos[2]:pos[3] , pos[0]:pos[1] ]

		#change image to gray scal cuz THRESH OTSU Needs that
		img = cv2.cvtColor(img , cv2.COLOR_BGR2GRAY)

		#cv2.threshold() -> returns  (thresh type , threshed_image)
		img_threshed  = cv2.threshold( img , 0 , 255, cv2.THRESH_BINARY |  cv2.THRESH_OTSU  )[1] 
		#NOTE : search why they use binary with otsu threshold hold not otsu only 

		# median blur to remove noise
		img_threshed_blured = cv2.medianBlur(img_threshed, 3) 

		# dilation to make the text thicker
		kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3,3))
		img_final = cv2.erode(img_threshed_blured, kernel, iterations=1) 
		# use cv2.dilate() instead if you want to expand the white pixels 
  		# (look up dilation and erosion)

		# TESTING BLOCK #
		cv2.imshow("TESTING : show image before edit" , img)
		cv2.imshow("TESTING : show image after edit" , img_final)
		# cv2.destroyAllWindows()
  
		# END OF TESTING BLOCK #
  
		#TODO :  deskew algorithm ( to keep ocr accurate with rotated id photoes)
  
		return img_final 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def search_id( id_char_type : str , scanned_image : str , valid_ids_freq : dict ) -> bool :
   
	id_values_type : str =  id_char_type #always 'numeric' for type 0 id (default)
	scanned_image = scanned_image.split()

	print ( f" {scanned_image}  {type(scanned_image)} ") #TESTING
  
	for id_obj in scanned_image	:

		print ( f'obj before strip and replace : {id_obj} ' )#TESTING

		id_obj = id_obj.strip().replace(" " , "")
		sz = len(id_obj)
		ok_type : bool = id_obj.isnumeric()

		print (f'scanned_image size : {len(scanned_image)} ')#TESTING
		print (f' id_obj: {id_obj}  is numeric? {ok_type} ') #TESTING
	
		#NOTE: add condition  for scanned_image sz to make it more restrict ( ex: must equal 4*2 in default id type)
		if id_char_type == 'numeric' and ok_type ==  True and sz == 14 : 
			extracted_id_val = id_obj

			#NOTE: its more safer to return id found in db then make freq array to record most accured id then thats the one
			# this makes sure  that for one second OCR will read the same right id 
			#(cuz ocr may not be accurate and generate fault id which is also present in DB not the right one)

			db_ok : bool =  db.db_check_ai_id(id_obj)
			if db_ok == True :
				is_valid = True
				valid_ids_freq[extracted_id_val] += 1
			else :
				continue
	
		else : continue
   
 		# '& 0xFF' takes only least significant byte -> (pressed key ascii code)
		if cv2.waitKey(0) & 0xff == ord('q'): #TESTING
			return False , extracted_id_val #this must be used in debug only


	return is_valid 	
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def read_simple_card_cuda ( vid : cv2.VideoCapture , vid_specs : list , id_card_specs : dict , is_valid : bool = False) -> str :
	#gpu index to use in acceleration
	cv2.cuda.setDevice(0) 


	vid = cv2.VideoCapture(0, cv2.CAP_CUDA)

	# Check if the camera is successfully opened
	return False if not vid.isOpened() else True
    

#use cuda functions and cuda matrices

 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def read_simple_card_opencl( vid : cv2.VideoCapture , vid_specs : list , id_card_specs : dict , is_valid : bool = False ) -> str : #NOTE: also use it when no GPU
   #TODO : use UMat 
	"""
	* Args:
 
		vid
  
		vid_specs : fps , frametime(1000 ms / fps) , vid_time_sec , active_gpu_api
  
		id_dimension
  
		is_valid

	* Returns:
 
		final_status 
  
  		scanned_id_string
    
    status is 'False' when error reading frame or scan id
	"""
	valid_cnt = 0
	valid_ids_freq = {}
	vid_time_cnt = vid_specs[2]
	id_dimension = id_card_specs['dimension']
	while vid_time_cnt > 0: #start capture camera at fps for 10seconds
   
		no_error , frame =  vid.read()
 
		if not no_error :
			return False #Fail error reading frame
	
		img_final = proccess_vid_frame(frame)
  
		imgstr = tsr.image_to_string(img_final, lang='eng')
  
		is_valid, *_ = search_id ( id_card_specs['id_char'] , imgstr , valid_ids_freq) #edits valid_ids_freq inside
		if is_valid :
			#render a green rectangle + must stay green for one second
			valid_cnt += 1
		else : 
			#render a red rectangle
			valid_cnt = 0

		print ( 'valid counter ' , valid_cnt)#TESTING 
  
		fps = vid_specs[0]
		vid_time_cnt -= 1
		if valid_cnt >= fps :  #if still valid for whole one sec accepted 
			all_success = True
			#get only one id -> the higest freq ( if two has same freq choose the first to be inputed in freq_arr)
			final_value = max ( valid_ids_freq ,  key= valid_ids_freq.get ) 
			return all_success , final_value 
		
		frametime = vid_specs[1]
		cv2.waitKey( frametime )  

	return False #fail
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
		

  
		
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
def ocr_main (id_dimension : tuple = (405 , 271) , id_type_indx : int = 0 ) -> str : 
	"""
	* this function does following (until now):
 
		0. enables gpu acceleration if available (cuda or opencl)
   
		1. starts video capture
 
		2. provide rectangle at video center to help user scan id + timer 
	
		4. proccess taken frame for better ocr ( threshold , smooth , dialate/erode , deskew(soon)) 
 
		5. ocr 
 
		6. parse the text to take only id for now ( 14numeric digits )
 
		3. save either by clicking key 'q' or when timer stops
	
 
		7. return the ocr(ed) ID carn number
 
	* Default id shape is : ( 405 x 271 ) (x,y) (later this will ocr car plates and license)
	actual size of our test id card image is 400x266
		
	* id_type_inx -> default id == 0 , lisence id  == 1  , car plate id == 2
  
	* returns id string    -> if succeeded 
 
		* returns False bool   -> if Failed
	"""
	#simple ids templates
	# this is good for future if wanted to extend code to scan car plates ofقdiffز id types
	default_id_specs = {'id_type' : (0 , "default")  , 'id_char' : "numeric"      , 'id_length' : 14 , 'id_objects_ordered' : ["name" , "gender" , "birthDate" , "id_num" ] , 'dimension' : (400 , 266)  }
	lisence_specs    = {'id_type' : (1 , "lisence")  , 'id_char' : "numeric"      , 'id_length' : 14 , 'id_objects_ordered' : ["name" , "vehicle_type" ,  "id_num" ] , 'dimension' : (400 , 266)}
	car_plate_specs  = {'id_type' : (2 , "carPlate") , 'id_char' : "Alphanumeric" , 'id_length' : 7  , 'id_objects_ordered' : ["egyEng" , "egyArb"  , "nums" , "alpha"] , 'dimension' : (300 , 266)}
	# NOTE : car_plate length may not be always 7 , 7 is tha mx_len so find solution to that
	ids_specs = [default_id_specs , lisence_specs , car_plate_specs ]  #0 is the default id
 
 
   #needed later
	final_value = None , None
	vid, *vid_specs = video_settings_setup()
	active_gpu_api = vid_specs[3]
 
	if active_gpu_api == 2 : #Cuda
		if id_type_indx == 0 : #default id card
			final_status , scanned_id = read_simple_card_cuda(vid , vid_specs , ids_specs[0])
		elif id_type_indx == 1 : #TODO: lisence card
			pass
		elif id_type_indx == 2 : #TODO: car plate id
			pass
	else : #OpenCL or no Gpu
		if id_type_indx == 0 : #default id card
			final_status , scanned_id = read_simple_card_opencl(vid , vid_specs , ids_specs[0])
		elif id_type_indx == 1 : #TODO: lisence card
			pass
		elif  id_type_indx == 2 : #TODO: car plate id 
			pass

	vid.release()
	cv2.destroyAllWindows()

	print ("did we found correct id ? " , final_status)#TESTING
 
	if final_status : 
		id = scanned_id
		return id 
	else : 
		return False #FAIL
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#



if __name__ == "__main__": 
	ocr_main()