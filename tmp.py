import cv2
print( cv2.getBuildInformation())
cap = cv2.VideoCapture(0)
print(cap.getBackendName())