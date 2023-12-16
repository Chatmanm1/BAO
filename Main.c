
#include <Servo.h>

//neopixel stuff
// taken fro https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/RGBWstrandtest/RGBWstrandtest.ino
#define LEDNum 12
#include <Adafruit_NeoPixel.h>
#define Brightness 50


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
// Declare our NeoPixel strip object:
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
    


Servo servo1;///x
Servo servo2;//y
Servo servo3;//rotation
int servoPos[3];
int state = 1; //set on power up to be in state one.
int input; 

void setup() {
  Serial.begin(9600);
  servo1.attach(9);  // Attach servo to pin 9
  servo2.attach(10); // Attach servo to pin 10
  servo3.attach(11); //attach servo 3 to pin 11
  /// set starting values to int array.
  servoPos[0] = servo1.read();
  servoPos[1] = servo2.read();
  servoPos[2] = servo3.read();
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);

}//end setup.


void loop() {
  
  if (Serial.available() > 0) {
     input = Serial.parseInt(); // Read input from serial to set state.
  

  }//end if serial available getting how to move from PI.
stateMachine();

}///end main loop



void motorMovement(xMove,yMove,rMove){ /// send what to move to handles smoothing.
  int prev[3];
  int desired[3];

  desired[0] = xMove;
  desired[1] = yMove;
  desired[2] = rMove;
 
 for(int i =0; i < 3;i++){
   if(desired[i]!= prev[i]){
  servo1.write((prev[0]*.95)+(desired[0]*.05)); 
  servo2.write((prev[1]*.95)+(desired[1]*.05)); 
  servo3.write((prev[2]*.95)+(desired[2]*.05));

 prev[i]=((prev[i]*.95)+(startPos[i]));
   }//end if
   }
  


  
 ///after loop has reached positions set the Global positions of the servos to read the asked for.
  servoPos[0] = xMove;
  servoPos[1] = yMove;
  servoPos[2] = rMove;

}//end motor movement function




void serialMovement(){
 if(Serial.available() > 0) {  // Check if data is available to read
    char incomingChar = Serial.read();  // Read a character from the serial input
 }/// end keyboard move.
///x axis 
  if(incomingChar == 'w'){
  servo1.write(servo1.read()+5)
  }//keyboard movement
  if(incomingChar == 's'){
      servo1.write(servo1.read()-5)
  //keyboard movement
  }
///y axis
  if(incomingChar == 'q'){
    servo2.write(servo2.read()+5)
  }//keyboard movement
  if(incomingChar == 'e'){
   servo2.write(servo2.read()-5)
  }//keyboard movement
/// pitch back axis
 // servo 3
  if(incomingChar == 'd'){
    servo3.write(servo3.read()+5)
  }//keyboard movement
  if(incomingChar == 'a'){
    servo3.write(servo3.read()-5)
  }//keyboard movement


}//end serial movement



void stateMachine(){
/// four states.

/// 1 just chillen moving. low power. can be changed by closeness of proximity sensor
if(state == 1){
  int x = servoPos[0] + random(5)-5;
  int y = servoPos[1] + random(5)-5;
  int r =  servoPos[2] + random(20)-20;
  motorMovement(x ,y,r); /// sends slight movements to the servos for Random looks
  delay(5000); /// waits five seonds before doing anything else
}

/// 2 responding and facetracking.

/// 3 games.

/// 4 keyboard control for puppeteering.

if(state == 4){
  serialMovement();
  // directly interacts with servos for less latency. ;p
}



}
