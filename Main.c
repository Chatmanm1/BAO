
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
    


Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);  // Attach servo to pin 9
  servo2.attach(10); // Attach servo to pin 10
  servo3.attach(11); //attach servo 3 to pin 11
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  if (Serial.available() > 0) {
    int angle1 = Serial.parseInt(); // Read angle for servo 1
    int angle2 = Serial.parseInt(); // Read angle for servo 2
    int angle3 = Serial.parseInt(); // read angle for servo 3. 

    if (Serial.read() == '\n') {
      if (angle1 >= 0 && angle1 <= 180 && angle2 >= 0 && angle2 <= 180) {
        servo1.write(angle1); // Set position for servo 1
        servo2.write(angle2); // Set position for servo 2
        servo3.write(angle3); //set position servo 3
        delay(15); // Allow servos to reach their positions


      }//end writing to servo angeles.

    }///end serial read
  }//end if serial available
}





////emotions section. 
//  Happiness
/* lights yello, 


*/
//	Sadness
//	Anger
//	Surprise
//	Fear
//	Disgust
//	Excitement

