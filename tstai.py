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

# TODO : factorise the big function
# TODO : show a  timer in  video ( 5 ~ 10 sec )  use cv2.puttext()
# TODO : add audio feedback 
# TODO : the car_plate reader function but for know all in one function
# TODO : feature and object  matching/tracking 


def render_timer ( frame : np.ndarray , timer : int ) -> np.ndarray : ... 

def make_rectangle_obj( frame : np.ndarray  , id_dimension : tuple  , color : str ) -> np.ndarray : 
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
    
    
	pos = x1 , y1 , x2 , y2
	return frame_rect_obj , pos
	
 

def check_gpu_accl () -> tuple :
	"""
	use only  inside video_settings()

	NOTE 1: this fuctntion gets exactly whose api  enabled  cuda or opencl
	and prefers opencl if both are enbaled 
	due to it being opensource and was writtern in an PC using AMD GPU

	NOTE 2: depending on used GPU acceleration main function will call
	the appropriate ocr reader function

	NOTE 3: if OpenCl enabled use cv2.UMat to save frames in and then process them
	after that convert them back to cv2.Mat
				if cuda is enabled use cv2.cudaGpuMat instead of cv2.UMat 
		and cv2.cuda.foo() instead of cv2.foo() in some opencv-python functions
  
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

def enable_multithreading () : ... #in case gpu acceleration is not enough to maintain stable 30fps

def video_settings_setup (cam_indx : int  = 0, fps : int = 30 , vid_time_sec : int = 10, res : tuple = (1366 , 768) , gpu_accel : int = 0 ) -> tuple :
	"""
	This function does set up the video objects
 
	gpu_accel == 0  no GPU acceleration found
 
	gpu_accel == 1  Cuda GPU acceleration found
 
	gpu_accel == 2  OpenCl GPU acceleration found

	"""
	if gpu_accel == 2 : #use Cuda video object
		#you can change video backends used by adding argument 
  		# cv2.CAP_DSHOW  (Dshow is the default in my pc)
		vid = cv2.cuda.VideoCapture(0 , cv2.CAP_DSHOW)

def read_simple_card_cuda (id_dimension : tuple = (405 , 271)) -> str : ...

def read_simple_card_opencl( id_dimension : tuple = (405 , 271) ) -> str : #NOTE: also use it when no GPU acceleration available
 
	#set the path to the tesseract dir ( not needed if you added it to win. env. variables)
	tsr.pytesseract.tesseract_cmd =  r'C:\Program Files\Tesseract-OCR\tesseract.exe'
	
 	# default id == 0 , lisence id  == 1  , car plate id == 2
	id_type_indx = 0 
   #needed later
	final_value , img  = [ None for i in range (2)] #needed later
 
	
	fps = 30
	timer = mx_time # 1000 * 10ms = 10s
 
			
 	#you can change video backends used by adding argument cv2.CAP_DSHOW 
  	# (changes video backend to direct show library)
  
  	#change default video object dimension . 
   # default  on omarpc obs vritual cam plugin -> (height_Y : 480 , width_X : 640)
	vid.set(cv2.CAP_PROP_FRAME_WIDTH , 1366) 
	vid.set(cv2.CAP_PROP_FRAME_HEIGHT, 768)
 
	
	
	valid_cnt = 0
	all_success : bool = False
	is_valid = False 
	while timer > 0: #start capture camera at fps for 10seconds
   
		is_error , frame =  vid.read()

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

  
		#TODO :  deskew algorithm ( to keep ocr accurate with rotated id photoes)

		imgstr = tsr.image_to_string(img_final, lang='eng')
		extracted_id_val = None

  
		
		if id_type_indx == 0 : #0 == default id type
			id_values_type : str =  ids_specs[id_type_indx]['id_char']#either numeric or alphanumeric 

			imgstr = imgstr.split()
			print ( imgstr ,' ', type(imgstr)) #TESTING
			for id_obj in imgstr	:
				print ( 'obj before strip and replace : ' ,id_obj)#TESTING
				id_obj = id_obj.strip().replace(" " , "")
				sz = len(id_obj)
				ok_type : bool = id_obj.isnumeric()
				print ('imgstr size : ' , len(imgstr))#TESTING
				print (' id_obj: ' , id_obj , ' is numeric? ' , ok_type) #TESTING
    
				if id_values_type == 'numeric' and ok_type ==  True and sz == 14 : 
       			#NOTE: add condition  for imgstr sz to make it more restrict ( ex: must equal 4*2 in default id type)
					extracted_id_val = id_obj
					
					#NOTE: its more safer to return id found on db also 
     				# this makes sure  that for one second OCR will read the same right id 
         		#(cuz ocr may not be accurate and generate fault id which is also present in DB not the right one)
           
					db_ok : bool =  db.db_check_ai_id(id_obj)
					is_valid = True  if db_ok == True else 'not valid id retry or enter manually'
       
				else : continue
    
		elif id_type_indx == 1 :
			... #TODO : in simple license reader function
		elif id_type_indx == 2 :
			... #TODO : in simple car plate reader function
   

		if is_valid :
			#render a green rectangle + must stay green for one second
			valid_cnt += 1
		else : 
			#render a red rectangle
			valid_cnt = 0


		timer -= 1
		print ( 'valid counter ' , valid_cnt)#TESTING
		if valid_cnt >= fps :  
			all_success = True
			final_value = extracted_id_val
			break #fps * (1000/fps) ms = 1s always
    
	
		
		frametime = 1000 // fps
 		# '& 0xFF' takes only least significant byte -> (pressed key ascii code)
		if cv2.waitKey( frametime ) & 0xff == ord('q'): 
			break 
  
	vid.release()

	#TESTING BLOCK
	cv2.imshow("TESTING : show image before edit" , img)
	cv2.imshow("TESTING : show image after edit" , img_final)
	print(imgstr) 
	cv2.waitKey(10*1000)
	# cv2.destroyAllWindows()
	# END OF TESTING BLOCK
 
	cv2.destroyAllWindows()

	 
	print ("did we found correct id ? " , all_success)#TESTING
 
	if all_success : 
		id = final_value
		return id 
	else : 
		return False #FAIL
		
def ocr_main (id_dimension : tuple = (405 , 271) , id_type_indx : int = 0 ) -> str : 
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
	"""
	this function does following (until now):
   0. enables gpu acceleration if available (cuda or opencl)
	1. starts video capture
	2. provide rectangle at video center to help user scan id + timer 
	4.proccess taken frame for better ocr ( threshold , smooth , dialate/erode , deskew(soon)) 
	5. ocr 
	6. parse the text to take only id for now ( 14 numeric digits )
	3. save either by clicking key 'q' or when timer stops
	7. return the ocr(ed) ID carn number
 
	Default id shape is : ( 405 x 271 ) (x,y) (later this will ocr car plates and license)
	actual size of our test id card image is 400x266
	
	returns id string if succeeded 
	returns False bool if Failed
	"""
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
	#simple ids templates
	# this is good for future if wanted to extend code to scan car plates ofقdiffز id types
	default_id_specs = {'id_type' : (0 , "default")  , 'id_char' : "numeric"      , 'id_length' : 14 , 'id_objects_ordered' : ["name" , "gender" , "birthDate" , "id_num" ] }
	lisence_specs    = {'id_type' : (1 , "lisence")  , 'id_char' : "numeric"      , 'id_length' : 14 , 'id_objects_ordered' : ["name" , "vehicle_type" ,  "id_num" ] }
	car_plate_specs  = {'id_type' : (2 , "carPlate") , 'id_char' : "Alphanumeric" , 'id_length' : 6  , 'id_objects_ordered' : ["egyEng" , "egyArb"  , "nums" , "alpha"] }
	# NOTE : car_plate length may not be always 6  , 6 is tha mx_len so find solution to that
	ids_specs = [default_id_specs , lisence_specs , car_plate_specs ]  #0 is the default id
 
   
	


if __name__ == "__main__": 
	read_simple_card()