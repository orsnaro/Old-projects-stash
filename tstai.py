import cv2
import numpy as np
import pytesseract as tsr

# TODO : the car_plate reader function
# TODO : the simple id card reader function
# TODO : feature and object  matching to detect if this is not an id and retry
# if second time failed add option in gui to enter id manually
# #(if we could add auto id complete in input would be nice )
# TODO : change stop video by key press to fixed time shown by a timer



def read_simple_card( id_dimension : tuple = (410 , 276) ) -> str :
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
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
	"""
 #_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#


	#make capture object and pass camera index
	vid = cv2.VideoCapture(0) 
 	#you change video backends used by adding argument cv2.CAP_DSHOW (changes video backend to direct show library)
  
  	#change default video object dimension  (height_Y : 480 , width_X : 640)
	vid.set(cv2.CAP_PROP_FRAME_WIDTH , 1366) 
	vid.set(cv2.CAP_PROP_FRAME_HEIGHT, 768)
 
	#make rectangle specs . coordinates are in ( x,y) color in BGR format
	rec_spec = {'color' : (0,255,0) , 'thickness' : 2 , 'top_left_coordinate' : tuple , 'bot_right_coordinate' : tuple  }

	i = 0 #TESTING
	while (True) : #start capture camera at 100fps

   
		is_error , frame =  vid.read()
  
		if i == 0 : #TESTING
			print ( frame.shape ) #TESTING

		i += 1 #TESTING
		cv2.imwrite(f"C:/Users/OmarPc/repo_Old_projects_stash/id_snapshots/last_id_snapshot{i}.jpg" , frame) #TESTING

		#get points to position helper rectangle in center
			#shape() returns height_frame , width_frame , channels
   
		print ( frame.shape ) #TESTING
  
		y_center , x_center , _ = [ int(x) // 2 for x in frame.shape ]
			#top left 
		x1 , y1 = x_center - id_dimension[0] // 2 , y_center - id_dimension[1] // 2
			#bot_right
		x2 , y2 = x_center + id_dimension[0] // 2 , y_center + id_dimension[1] // 2	
			#make rec_in_center
		rec_spec['top_left_coordinate'] , rec_spec['bot_right_coordinate'] = (x1 , y1) , (x2 , y2)
  

		#make rectangle object to help position ID card when scanning
		img = frame # frame copy with out the rectangle is what we will process
		cv2.rectangle(frame , rec_spec['top_left_coordinate'] , rec_spec['bot_right_coordinate'] , rec_spec['color'] , rec_spec['thickness']) #pass all what in rec_spect dict to the function


		#show live video  100fps ( user visual aid )
		cv2.imshow("Camera", frame)

 		# '& 0xFF' takes only least significant byte -> (pressed key ascii code)
		if cv2.waitKey(10) & 0xff == ord('q'): # ord() converts char to its int ascii code
			break

	vid.release()
	cv2.destroyAllWindows()

	final_value = None
	# img = cv2.imread(r"./test_id_yousef_salah.jpg", cv2.IMREAD_GRAYSCALE)
	# # img = cv2.resize(img, (600, 400))
	# img = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)[1] # returns  (thresh type , threshed_image)
	# imgstr = tsr.image_to_string(img, lang='eng')
	# # for loop to check isnumeric() and only save numeric char then join them in one string
	# imgstr = imgstr.split()
	# print(imgstr[1])
	id = final_value

	return id

if __name__ == "__main__":
	# your test code
	# tst = {"omar" : (3,4,4)}
	# print ( tst['omar'])
	read_simple_card()