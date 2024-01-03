# CutiesAutonSelector
This is 3142C's Autonomous Selector


There are two versions of the auton selector. One is called "Simple Auton Selector" and the other is called "Complex Auton Selector." The simple one runs with the default vexcode brain commands. The complex version runs using custom images for the buttons. Both have the same functionality but the complex version requires more setup, an SD card, and looks prettier.

For the simple version, download both "simpleAutonSelector.cpp" and "simpleAutonSelector.h"
  at the top of your main.cpp file, paste:
  
    #include "simpleAutonSelector.h"
  
  then in your pre_auton function, paste:
  
    drawGUI(); 
    Brain.Screen.pressed(selectAuton);

in your autonomous function paste: 
  
    if (!isCloseAuton && !isFarAuton && !isSkillsAuton){ 
    //nothing 
    } else if (isCloseAuton) { 
    //close auton//
    
    //safe
    if (autonMode == 0) {
      //put your safe close auton code in here
    }
    
    //risky
    if (autonMode == 1) {
      //put your risky close auton code in here
    }
  
    //awp
      //put your auton win point close auton code in here; 
      } else if (isFarAuton) { 
      //far auton//
    
    //safe
    if (autonMode == 0) {
      //put your safe far auton code in here
    }
    
    //risky
    if (autonMode == 1) {
      //put your risky far auton code in here
    }
  
    //awp
      //put your auton win point far auton code in here; 
      } else if (isSkillsAuton) { 
      //skills auton//

      //put your skills code in here
      }


For the complex version, download both "complexAutonSelector.cpp" and "complexAutonSelector.h" also download all of the .png files in this project. Put these png files onto an SD card and plug it into your brain. Make sure to not have anything else on the SD card, and to not put the pngs into a folder on the SD.
  at the top of your main.cpp file, paste:
  
    #include "complexAutonSelector.h"
  
  then in your pre_auton function, paste:
  
    drawGUI(); 
    Brain.Screen.pressed(selectAuton);

in your autonomous function paste: 
  
    if (!isCloseAuton && !isFarAuton && !isSkillsAuton){ 
    //nothing 
    } else if (isCloseAuton) { 
    //close auton//
    
    //safe
    if (autonMode == 0) {
      //put your safe close auton code in here
    }
    
    //risky
    if (autonMode == 1) {
      //put your risky close auton code in here
    }
  
    //awp
      //put your auton win point close auton code in here; 
      } else if (isFarAuton) { 
      //far auton//
    
    //safe
    if (autonMode == 0) {
      //put your safe far auton code in here
    }
    
    //risky
    if (autonMode == 1) {
      //put your risky far auton code in here
    }
  
    //awp
      //put your auton win point far auton code in here; 
      } else if (isSkillsAuton) { 
      //skills auton//

      //put your skills code in here
      }





