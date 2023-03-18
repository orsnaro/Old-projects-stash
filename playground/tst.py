import pytesseract 
import cv2
img = cv2.imread(r'C:\Users\OmarPc\Desktop\145ad8a8af3318681a705f281a44c3a3.jpg')
img = cv2.resize(img, (600, 360))
print (pytesseract.image_to_string(img))
cv2.imshow('Result', img)
cv2.waitKey(0)

# pytesseract.pytesseract.tesseract_cmd = r'C:\Users\USER\AppData\Local\Tesseract-OCR\tesseract.exe'


