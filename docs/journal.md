2026-10-03  
   
 Goal:  
   
 Get my tools ready (Git and the ESP32 in Arduino IDE), then run my first experiments.  
   
    
   
 Did:  
- Installed Git and set my name and email.  
- Created the DeskBot repo with folders, README and journal.  
- Made my first commit and pushed it to GitHub.  
- Installed ESP32 board support in Arduino IDE.  
- Blinked the LED with delay() and printed ON/OFF to the Serial Monitor.  
- Rewrote it with millis() so the LED blinks on one schedule while a message prints every 3 seconds.  
   
    
   
 Broke / confusing:  
- The ESP32 board package would not download in Arduino IDE. I uninstalled it and installed it again.  
- Git: touch failed because I had not made the folders first.  
- Git: my files were saved as .txt instead of .md.  
- The Serial Monitor was set to 9600 baud but the code used 115200, so the output was unreadable.  
- The LED pin was set to 4 and the interval to 20 ms, instead of the board's LED pin and 500 ms.  
   
    
   
 Learned:  
- git add . prints nothing when it works. git status shows what Git sees, and git commit saves it.  
- A file can't be created inside a folder that doesn't exist yet.  
- delay() blocks everything else while it waits.  
- millis() lets several tasks run on their own schedules at the same time.  
- The baud rate in Serial.begin() and in the Serial Monitor must match.  
- Check the pin number and the interval value when something looks wrong. Wrong values look like a broken board.  
   
   
   
#  2026-10-04  
   
## **Goals**  
1. Build the first real circuit, calculate the resistor value, and check the math with a multimeter.  
2. Read a button on the ESP32, see contact bounce, and remove it with a millis()-based software debounce.  
## **Circuits**  
- LED: GPIO 18 -> 330 ohm resistor -> LED anode (long leg); LED cathode (short leg) -> ESP32 GND.  
- Button: GPIO 19 -> button -> GND, using INPUT_PULLUP (internal pull-up, no external resistor). Pressed = LOW, released = HIGH.  
## **Part 1: LED, resistor and multimeter**  
**Math (on paper):** I = (3.3 V - 2 V) / R  
- 150 ohm: about 8.7 mA (bright, still safe)  
- 330 ohm: about 3.9 mA (clearly visible)  
- 1 kohm: about 1.3 mA (dim)  
### **Part 2: Button, bounce and debounce**  
- A: Read the button with digitalRead(). The LED followed the button, and the Serial Monitor showed 1s and 0s.  
- Floating-pin test: INPUT without a pull-up gave random readings.   
- B: Counted presses using falling-edge detection only. Out of 20 presses I got [35***] counts, so [***15] extra counts came from bounce.  
- C: Added a millis() debounce with DEBOUNCE_MS = [30]. 20 presses gave [20] counts.  
### **What went wrong / debugging**  
- LED and resistor readings fluctuated. Cause: [fill in: blink sketch running / loose probe contact / auto-range / small normal variation].  
- The Serial Monitor showed garbage characters. Cause: [fill in].  
- A test sketch printed "hello" all at once instead of once a second. Cause: [fill in, e.g. missing delay(1000)].  
-  LED reversed, loose jumper, button orientation, wrong pin.  
### **What I learned**  
- The resistor sets the LED current. Without it the LED can draw too much current from the pin.  
- The voltage across the resistor plus the voltage across the LED adds up to the supply (about 3.3 V).  
- I can find current without opening the circuit: I = V_resistor / R.  
- Small fluctuations in readings come from probe contact, USB noise and meter resolution.  
- A floating input pin reads random values, so a pull-up (or pull-down) is needed.  
- With INPUT_PULLUP the logic is inverted: pressed = LOW.  
- Buttons bounce for a few milliseconds, so one press can look like many.  
- Debounce means ignoring changes until the signal has been stable for a set time. Too short lets bounce through, too long misses fast presses.  
- Detect a press as a change (falling edge), not a level, or a held button counts continuously.  
- For serial problems, check the basics first (baud rate, pin choice, a minimal test sketch) before suspecting the main code.  
