# scriptrunner
Stupid little program to run scripts with a gui.

## How it works
After you compile it for your system you can run it as such:
 ```bash
scriptrunner "Window Title" "First Button Text" "./first-button-script-to-run.sh" "Second Button Text" "./second-button-script-to-run.sh"
 ```
 
 The build script included compiles it for Linux Desktop (GLFW). 
 
 ## How it looks
 It creates a button for each Button Text + Script combo provided, stacking them horizontally.  It's set currently to simply be 320x200 because that's the size I need it to be for my application.

![screenshot](https://raw.githubusercontent.com/michaelfiber/scriptrunner/main/files/scriptrunner.png)
