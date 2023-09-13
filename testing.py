import numpy as np
import cv2 as cv
import gpiozero as Servo
from time import sleep


## lights on off


# make sure servos are correctly assigned here.
servo1 = Servo(6) #head back and forth.
servo2 = Servo(13) #wing left
servo3 = Servo(19) #wing Right


#camera stuff
cap = cv.VideoCapture(0)
if not cap.isOpened():
    print("Cannot open camera")
    exit()
while True:
 # Capture frame-by-frame
 ret, frame = cap.read()
 # if frame is read correctly ret is True
 if not ret:
    print("Can't receive frame (stream end?). Exiting ...")
break
 # Our operations on the frame come here
 gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
 # Display the resulting frame
 cv.imshow('frame', gray)
 if cv.waitKey(1) == ord('q'):
    break
# When everything done, release the capture
cap.release()
cv.destroyAllWindows()









def setAngle(servo,angle):
    duty = angle / 18 + 3
    servo.ChangeDutyCycle(duty)
 
   