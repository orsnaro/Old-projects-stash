import cv2
import numpy as np
import pytesseract as tsr
import garage_db

# TODO : make an sample id png that matches the specs below
# TODO : make the rectangle red until the code reads id sucesfully and save last sucssefully read id 
# TODO : change stop video by key press to fixed time shown by a timer
# TODO : show a  timer in  video ( 5 ~ 10 sec ) 
# TODO : add audio feedback 
# TODO : the car_plate reader function but for know all in one function
# TODO : feature and object  matching to detect if this is not an id and retry
# if second time failed add option in gui to enter id manually
# #(if we could add auto id complete in input would be nice )

#fille simple ids templates
# this is good for future if wanted to extend code to scan car plates of diff id types
default_id_specs = {'id_type' : (0 , "default")  , 'id_char' : "numeric"      , 'id_length' : 14 , 'id_objects_ordered' : ["name" , "gender" , "birthDate" , "id_num" ] }
lisence_specs    = {'id_type' : (1 , "lisence")  , 'id_char' : "numeric"      , 'id_length' : 14 , 'id_objects_ordered' : ["name" , "vehicle_type" ,  "id_num" ] }
car_plate_specs  = {'id_type' : (2 , "carPlate") , 'id_char' : "Alphanumeric" , 'id_length' : 6  , 'id_objects_ordered' : ["egyEng" , "egyArb"  , "nums" , "alpha"] }
# NOTE : car_plate length may not be always 6  , 6 is tha mx_len so find solution to that
ids_specs = [default_id_specs , lisence_specs , car_plate_specs ]  #0 is the default id

#spec of rectangle to be rendered in live video for guiding end user
rec_spec = {'color' : (0,0,255) , 'thickness' : 2 , 'top_left_coordinate' : tuple , 'bot_right_coordinate' : tuple  }


def read_simple_card( id_dimension : tuple = (400 , 190) ) -> str :
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
	"""
	this function does following (until now):
	1. start video capture
	2. provide rectangle at video center to help user scan id
	3. save camera frame when 'q' key is pressed 
	4.proccess taken frame for better ocr ( threshold , smooth , dialate) 
	5. ocr 
	6. parse the text to take only id for now ( 14 numeric digits )
	7. return the ocr(ed) ID carn number
 
	Default id shape is : ( 410 x 276) (x,y)
	actual size of our test id card image is 400x266
	
	returns id if succeeded 
	returns 'Fail' string is failed
	"""
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
	
 	# default id == 0 , lisence id  == 1  , car plate id == 2
	id_type_indx = 0 
	
   #needed later
	final_value , img , x1 , x2 ,y1 ,y2 = [ None for i in range (6)] #needed later
 
	#make capture object and pass camera index -> by default main cam index is 0
	vid = cv2.VideoCapture(0) 
 	#you can change video backends used by adding argument cv2.CAP_DSHOW 
  	# (changes video backend to direct show library)
  
  	#change default video object dimension . 
   # default  on omarpc obs vritual cam plugin -> (height_Y : 480 , width_X : 640)
	vid.set(cv2.CAP_PROP_FRAME_WIDTH , 1366) 
	vid.set(cv2.CAP_PROP_FRAME_HEIGHT, 768)
	
	timer = 1e3 # 1000 * 10ms = 10s
	valid_cnt = 0
	all_success : bool = False
	while ( timer != 0) : #start capture camera at 100fps for 10seconds

   
		is_error , frame =  vid.read()


		#get points to position helper rectangle in center
		y_center , x_center , _ = [ int(x) // 2 for x in frame.shape ]
			#top left 
		x1 , y1 = x_center - id_dimension[0] // 2 , y_center - id_dimension[1] // 2
			#bot_right
		x2 , y2 = x_center + id_dimension[0] // 2 , y_center + id_dimension[1] // 2	
			#make rec_in_center
		rec_spec['top_left_coordinate'] , rec_spec['bot_right_coordinate'] = (x1 , y1) , (x2 , y2)
  

		#make rectangle object to help position ID card when scanning
		img = frame # frame copy with out the rectangle is what we will process
		#pass all what in rec_spect dict to the function
		cv2.rectangle(frame , rec_spec['top_left_coordinate'] , rec_spec['bot_right_coordinate'] , rec_spec['color'] , rec_spec['thickness']) 


		#show live video  100fps ( user visual aid )
		cv2.imshow("Camera", frame)

		 #crop image to get the id card only
		img = img[ y1:y2 , x1:x2 ]
  
		#change image to gray scal cuz THRESH OTSU Needs that
		img = cv2.cvtColor(img , cv2.COLOR_BGR2GRAY)

		img_threshed  = cv2.threshold( img , 0 , 255, cv2.THRESH_BINARY |  cv2.THRESH_OTSU  )[1] # returns  (thresh type , threshed_image)
		#NOTE : search why they use binary with otsu threshold hold not otsu only 

		# median blur to remove noise
		img_threshed_blured = cv2.medianBlur(img_threshed, 3) 

		# dilation to make the text thicker
		kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3,3))
		img_final = cv2.erode(img_threshed_blured, kernel, iterations=1) 
		# use cv2.dilate() instead if you want to expand the white pixels (look up dilation and erosion)

  
		#TODO :  deskew algorithm ( to keep ocr accurate with rotated id photoes)

		imgstr = tsr.image_to_string(img_final, lang='eng')
		extracted_id_val = None

		#TESTING BLOCK
		cv2.imshow("TESTING : show image before edit" , img)
		cv2.imshow("TESTING : show image after edit" , img_final)
		print(imgstr) 
		cv2.waitKey(0)
		cv2.destroyAllWindows()
		# END OF TESTING BLOCK
  
		is_valid = False 
		
		if id_type_indx == 0 : #0 == default id type
			id_values_type : str =  ids_specs[id_type_indx]['char']     #either Numeric or Alphanumeric 
   
			for id_obj in imgstr	:
				sz = len(id_obj)
				ok_type : bool = id_obj.isnumeric()
    
				if id_values_type == 'numeric' and ok_type ==  True and sz == 14 :	
					extracted_id_val = id_obj.strip().replace()	
					
					#NOTE : its more safer to return id found on db also 
     				# to make sure  that for one second OCR will read the same right id 
					db_ok : bool =  garage_db.db_check_ai_id(id_obj.strip().replace(" ", ""))
					is_valid = True  if db_ok == True else 'not valid id retry or enter manually'
       
				else : continue
    
		elif id_type_indx == 1 :
			... #TODO : in simple license reader function
		elif id_type_indx == 2 :
			... #TODO : in simple car plate reader function
   

		if is_valid :
			#render a green rectangle + must stay green for one second
			rec_spec['color'] = (0 , 255 , 0)
			valid_cnt += 1
		else : 
			#render a red rectangle
			valid_cnt = 0
			rec_spec['color'] = (0 , 0 , 255)


		timer -= 1
		if valid_cnt == 100 :  
			all_success = True
			final_value = extracted_id_val
			break #100 * 10 ms = 1s
    
	
 
 		# '& 0xFF' takes only least significant byte -> (pressed key ascii code)
		if cv2.waitKey(10) & 0xff == ord('q'): # ord() converts char to its int ascii code
			break 

	vid.release()
	cv2.destroyAllWindows()

	if all_success : 
		id = final_value
		return id 
	else : 
		return 'Fail'
		


	


if __name__ == "__main__":
	read_simple_card()