/*
  Heart Animation Sketch
  
  This is the default sketch that comes
  shipped with every UNO R4 WiFi board,
  but modified to loop!

  The animation loops every 5 seconds, while
  the built-in LED blinks indefinately.

  created 26 Jun 2023
  by Martino Facchin

  updated to loop animation every 5 seconds 14 Aug 2023
  by Patrick Waugh
*/

// include the LED Matrix library from the Uno R4 core:
#include "Arduino_LED_Matrix.h"
// make an instance of the library:
ArduinoLEDMatrix matrix;
//include the "animation.h" header file that stores the frames for the animation
#include "animation.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  matrix.loadSequence(frames);
  matrix.begin();
}

void loop() {
  // Run the animation, then blink during 10 second pause.  Repeat.
  //matrix.autoscroll(300);
  matrix.play(true);

  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}
