
import cv2
import numpy as np
import pytesseract as tsr

# TODO : the car_plate reader function
# TODO : the simple id card reader function
# TODO : feature and object  matching to detect if this is not an id and retry
# if second time failed add option in gui to enter id manually 
# #(if we could add auto id complete in input would be nice )
# TODO : change stop video by key press to fixed time shown by a timer



def simple_card_reader ( id_dimension : tuple = (800 , 400) ) -> str :
	"""
	this function does following (until now):
	1. start video capture
	2. provide rectangle at video center to help user scan id
	3. save camera frame when 'q' key is pressed 
	4.proccess taken frame for better ocr ( threshold , smooth , dialate) 
	5. ocr 
	6. parse the text to take only id for now ( 14 numeric digits )
	7. return the ocr(ed) ID carn number
 
	Default id shape is : ( 800 x 400) (x,y)
	"""
	#make capture object and pass camera index
	vid = cv2.VideoCapture(0)

	#rect obj specs
	color = (0,255,0) #green color in BGR format
	thickness = 2 
	top_left_coordinate : tuple #(x,y) top left most corner is origin (0,0)
	bot_right_coordinate : tuple


	while (1) : #capture camera at 100fps
		
		is_error , frame =  vid.read()
		cv2.imwrite("test.jpg" , frame)
	
	
		#make rectangle object ot position ID card
		cv2.rectangle(frame , )
	
		#center the rectangle in video frame
		
		#show live video ( user visual aid)
		cv2.imshow("Camera", frame) 


		if cv2.waitKey(10) & 0xff == ord('q'):
			break

	vid.release()
	cv2.destroyAllWindows()

	img = cv2.imread(r"./test_id_yousef_salah.jpg", cv2.IMREAD_GRAYSCALE)
	# img = cv2.resize(img, (600, 400))
	img = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)[1] # returns  (thresh type , threshed_image)
	imgstr = tsr.image_to_string(img, lang='eng')
	# for loop to check isnumeric() and only save numeric char then join them in one string
	imgstr = imgstr.split()
	print(imgstr[1])



	return id 




if __name__ == "__main__": ...
	 # your test code