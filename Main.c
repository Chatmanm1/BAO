
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
int startPos[3];
int state;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);  // Attach servo to pin 9
  servo2.attach(10); // Attach servo to pin 10
  servo3.attach(11); //attach servo 3 to pin 11
  /// set starting values to int array.
  startPos[0] = servo1.read();
  startPos[1] = servo2.read();
  startPos[2] = servo3.read();
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);

}//end setup.


void loop() {
  if (Serial.available() > 0) {
    int input = Serial.read(); // Read input from serial to set state.
  

  }//end if serial available getting how to move from PI.
motorMovement();

}///end main loop



void motorMovement(xMove, yMove,rMove){
  int prev[3];
  int current[3];
 
 for(int i =0; i < 2;i++){
 prev[i]=startPos[i];
 }//initialize positions

  if(state == 1){//
  servo1.write((prev[0]*.95)+(startPos[0])); 
  servo2.write((prev[1]*.95)+(startPos[1])); 
  servo3.write((prev[2]*.95)+(startPos[2]));
  // blinking'
  // rainbow light effect.

  for(int i =0; i < 2;i++){
 prev[i]=((prev[i]*.95)+(startPos[i]));
   }
 }//reestablish preveious.


  }//end if state 1

//movement type 1 random looking around.

  if(state == 2){
    // get servo directions over serial. 
    // X, Y, T to denote angle needed from each then write to servo


}//movement type  
  
  if(state == 3){///redlight greenligh
  //get 

}//movement type 

  if(state== 4){
///control servos with keyboard.

  }//end if state 4
}//end movement


void serialMovement(){
if(Serial.available() > 0) {  // Check if data is available to read
    char incomingChar = Serial.read();  // Read a character from the serial input
}/// end keyboard move.

if(incomingChar == 'w'){
  servo1.write(servo1.read()+5)
}//keyboard movement
if(incomingChar == 's'){
  servo1.write(servo1.read()-5)
}//keyboard movement

if(incomingChar == 'q'){
  servo2.write(servo2.read()+5)
}//keyboard movement
if(incomingChar == 'e'){
  servo2.write(servo2.read()-5)
}//keyboard movement


 if(incomingChar == 'd'){
  servo2.write(servo3.read()+5)
}//keyboard movement
if(incomingChar == 'a'){
  servo2.write(servo3.read()-5)
}//keyboard movement
 // get servo directions over serial for facetracking. 
    // X, Y, T to denote angle needed from each then write to servo

}//end serial movement

////emotions section. 
//  Happiness
/* lights yello, 


*/
//	Sadness
//blue and moves down.


//	Anger

//	Surprise
// eyes n-n surprised

//	Fear

//	Excitement/
// lots of quick swmall movements

