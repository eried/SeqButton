/*
  Callbacks Example
  Toggle a LED at each push on button 1 and at each release on button 2

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  created 20 March 2017
  by SMFSW
 */

#include <SeqButton.h>

SeqButton	but1, but2;				// Declare buttons

void ToggleLED(void)
{
	static boolean LEDState = LOW;	// State HIGH/LOW
	
	LEDState = !LEDState;			// Change LED
	digitalWrite(13, LEDState);		// turn the LED into LEDState
}

// the setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);

	// initialize the button with callback on push (no repeat)
	but1.init(2, &ToggleLED);
	// initialize the button with callback only on release (no repeat)
	but2.init(3, NULL, &ToggleLED);
}

// the loop function runs over and over again forever
void loop() {
	but1.handler();
	but2.handler();
}
