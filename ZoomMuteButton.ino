/* Buttons to USB Keyboard Example
   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>


#include <WS2812Serial.h>

const int numled = 16; // Number of LEDs on the ring
const int pin = 20; // Reference below for usable pins for the neopixel

// Usable pins for neopixels:
//   Teensy LC:   1, 4, 5, 24
//   Teensy 3.2:  1, 5, 8, 10, 31   (overclock to 120 MHz for pin 8)
//   Teensy 3.5:  1, 5, 8, 10, 26, 32, 33, 48
//   Teensy 3.6:  1, 5, 8, 10, 26, 32, 33
//   Teensy 4.0:  1, 8, 14, 17, 20, 24, 29, 39

byte drawingMemory[numled*3];         //  3 bytes per LED
DMAMEM byte displayMemory[numled*12]; // 12 bytes per LED

WS2812Serial leds(numled, displayMemory, drawingMemory, pin, WS2812_GRB);

// see WS2812Serial example for more color codes.

#define RED    0xFF0000
#define GREEN  0x001600




// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
  // most mechanical pushbuttons
Bounce button = Bounce(4, 10);

int LED_status= 0;

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
    
    pinMode(4, INPUT_PULLUP);

    LED_status=0; 
    leds.begin();
      
}





void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button.update();
 int microsec = 1500000 / leds.numPixels();

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  // When you click on a momentary switch this is the pushing "down "
  
  if (button.fallingEdge()) {

     
// for Zoom shortcut to mute/unmute is modifier Key + "A" depending on the operating system.

Keyboard.set_modifier(MODIFIERKEY_GUI | MODIFIERKEY_SHIFT);  // For Mac , Command Key
//  Keyboard.set_modifier(MODIFIERKEY_ALT); // Windows , ALT Key   
     
     
  Keyboard.press(KEY_A);
  Keyboard.release(KEY_A);  
  Keyboard.set_modifier(0); //releasing the modifier key.
  Keyboard.send_now();
  

    
  
  }


  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button.risingEdge()) {
    

        if (LED_status < 1){
   colorWipe(GREEN, microsec);
    LED_status=1;
      
    }

    else if  (LED_status > 0 ){
 
    LED_status=0;
    colorWipe(RED, microsec);
    }

  
  
}
}

void colorWipe(int color, int wait) {
  for (int i=0; i < leds.numPixels(); i++) {
    leds.setPixel(i, color);
    leds.show();
    delayMicroseconds(wait);
  }
}
