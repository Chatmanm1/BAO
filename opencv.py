

# Initialize serial communication for controlling servos
ser = serial.Serial('COMX', 9600)  # Replace 'COMX' with your serial port and 9600 with your baud rate

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)  # Access the webcam

while True:
    ret, frame = cap.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=2, minSize=(30, 30))

    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

        # Calculate the midpoint of the face
        face_mid_x = x + w // 2
        face_mid_y = y + h // 2

        # Get the center of the frame
        frame_mid_x = frame.shape[1] // 2
        frame_mid_y = frame.shape[0] // 2

        # Calculate the difference between the face midpoint and frame center
        delta_x = face_mid_x - frame_mid_x
        delta_y = face_mid_y - frame_mid_y

        # You may need to adjust the sensitivity and servo control logic here
        # Send signals over serial to control the servos based on the delta values
        # For example:
        # ser.write(f'X{delta_x}Y{delta_y}\n'.encode())

    cv2.imshow('Face Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
ser.close()  # Close the serial connection at the end