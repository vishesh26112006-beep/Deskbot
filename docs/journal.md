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
- Git: `touch` failed because I had not made the folders first.  
- Git: my files were saved as .txt instead of .md.  
- The Serial Monitor was set to 9600 baud but the code used 115200, so the output was unreadable.  
- The LED pin was set to 4 and the interval to 20 ms, instead of the board's LED pin and 500 ms.  
   
Learned:  
- `git add .` prints nothing when it works. `git status` shows what Git sees, and `git commit` saves it.  
- A file can't be created inside a folder that doesn't exist yet.  
- delay() blocks everything else while it waits.  
- millis() lets several tasks run on their own schedules at the same time.  
- The baud rate in Serial.begin() and in the Serial Monitor must match.  
- Check the pin number and the interval value when something looks wrong. Wrong values look like a broken board.  
   
Next:  
- - Move on to the next step in the Week 1 plan.  
