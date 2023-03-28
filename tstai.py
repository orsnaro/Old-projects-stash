
import cv2
import pytesseract as tsr
# 	# TODO : the car_plate reader function
# 	# TODO : the simple id card reader function
# 	# TODO : feature matching to detect if this not and id and retry

# vid = cv2.VideoCapture(0)
# while (1) :
# 	ret , frame =  vid.read()

# 	cv2.imwrite("test.jpg" , frame)
# 	cv2.imshow("frame", frame)


# 	if cv2.waitKey(1) & 0xff == ord('q'):
# 		break

# vid.release()
# cv2.destroyAllWindows()

img = cv2.imread(r"./test_id_yousef_salah.jpg", 1)
img = cv2.resize(img, (600, 400))
img = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
imgstr = tsr.image_to_string(img, lang='eng')
# for loop to check isnumeric() and only save numeric char then join them in one string
imgstr = imgstr.split()
print(imgstr[1])


def car_plate_reader(): ...


def simple_id_reader(): ...
# open video camera
# capture frame from camera
# gaussian blur the image
# threshold the image ( binary or smart threshold)
# ocr the result image
# return text ( id )


if __name__ == "__main__":
    ...
    # your test code
