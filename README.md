# zoomButton
Simple emergency mute/unmute for zoom meeting button 
Based on some thrown together code from the  
WS2812Serial example and Button example.

Parts.

1. Teensy 4.0  
2. Button  
3. Neopixels.  


Build steps.

  1.Solder the GND and Pin 4 on the Teensy to the button.  
  2. Solder GND, 5V and Pin 20 on the Teensy to the neopixels.  
  3.Download the Teensy Loader.  
      https://www.pjrc.com/teensy/loader.html  
  4.Flash Teensy with code.  


Stickers by   

1. I void Warranties for a living. by @jilles_com https://twitter.com/jilles_com  
2. Safety Third. by @Stickerum https://twitter.com/Stickerum  

Caveat:  
Start with zoom mic unmuted. for the color codes.  
It just switches states.  

Start zoom muted -> "muted" is Green.  
Start zoom unmuted -> "muted" is Red. 

The button only sends a single key combo. (you can edit it to send more, but zoom only alternates between states and you cannot assing key codes per function. ie: One combination to mute, another to unmute. = both have to be the same key code).

Here are the shortcuts for Zoom Meetings :  
https://support.zoom.us/hc/en-us/articles/205683899-Hot-Keys-and-Keyboard-Shortcuts-for-Zoom  

For keycodes to send via the Teensy:   
https://www.pjrc.com/teensy/td_keyboard.html  

