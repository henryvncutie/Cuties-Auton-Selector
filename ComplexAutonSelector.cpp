using namespace vex
#include "ComplexAutonSelector.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Complex Auton Selector                                     */
/*    Author:       Henry from 3142C                                          */
/*    Created:      Jan 2 24                                                  */
/*    Description:  Complex version of 3142's Auton selector                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//

//Variables
bool isCloseAuton = false;
bool isFarAuton = true;
bool isSkillsAuton = false;
int autonMode = 0;
int autonModeMin = 0;
int autonModeMax = 2;
int allianceColor = 0;
int allianceColorMin = 0;
int allianceColorMax = 2;
bool matchLoading = false;


//Functions
void updateBrainScreen() {
  Brain.Screen.clearScreen();
  if (!isCloseAuton) {
    Brain.Screen.drawImageFromFile("Close-Off.png", 30, 10);
  } else if (isCloseAuton) {
    Brain.Screen.drawImageFromFile("Close-On.png", 30, 10);
  }
  
  if (!isFarAuton) {
    Brain.Screen.drawImageFromFile("Far-Off.png", 190, 10);
  } else if (isFarAuton) {
    Brain.Screen.drawImageFromFile("Far-On.png", 190, 10);
  }

  if (!isSkillsAuton) {
    Brain.Screen.drawImageFromFile("Skills-Off.png", 350, 10);
  } else if (isSkillsAuton) {
    Brain.Screen.drawImageFromFile("Skills-On.png", 350, 10);
  }

  if (autonMode == 0) {
    Brain.Screen.drawImageFromFile("AutonMode-Safe.png", 30, 130);
  } else if (autonMode == 1) {
    Brain.Screen.drawImageFromFile("AutonMode-Risky.png", 30, 130);
  } else if (autonMode == 2) {
    Brain.Screen.drawImageFromFile("AutonMode-AWP.png", 30, 130);
  }
  
  if (allianceColor == 0) {
    Brain.Screen.drawImageFromFile("Alliance-Off.png", 190, 130);
  } else if (allianceColor == 1) {
    Brain.Screen.drawImageFromFile("Alliance-Red.png", 190, 130);
  } else if (allianceColor == 2) {
    Brain.Screen.drawImageFromFile("Alliance-Blue.png", 190, 130);
  } 

  if (!matchLoading) {
    Brain.Screen.drawImageFromFile("Loading-Off.png", 350, 130);
  } else if (matchLoading) {
    Brain.Screen.drawImageFromFile("Loading-On.png", 350, 130);
  }
  }
    


void updateControllerScreen() {
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.clearLine();
  Controller1.Screen.setCursor(1, 2);
  Controller1.Screen.print(Brain.Battery.capacity());
  Controller1.Screen.setCursor(1, 9);
  if (inertialSensor.installed()) {
    Controller1.Screen.print("I Connected");
  } else {
    Controller1.Screen.print("I Disconnected");
  }
}
void drawGUI() {
  updateBrainScreen();
}
  
void selectAuton() {  
  updateBrainScreen();
  int x = Brain.Screen.xPosition(); // get the x position of last touch of the screen
  int y = Brain.Screen.yPosition(); // get the y position of last touch of the screen
  // check to see if buttons were pressed
  if (x >= 30 && x <= 130 && y >= 10 && y <= 110) // close auton button pressed
    {
      if (!isCloseAuton) {
        isCloseAuton = true;
        isFarAuton = false;
        isSkillsAuton = false;
      } else if (isCloseAuton) {
        isCloseAuton = false;
        isFarAuton = false;
        isSkillsAuton = false;
        matchLoading = false;
      }

    }
  
  if (x >= 190 && x <= 290 && y >= 10 && y <= 110) // far auton button pressed
    {
      if (!isFarAuton) {
        isFarAuton = true;
        isCloseAuton = false;
        isSkillsAuton = false;
        matchLoading = false;
      } else if (isFarAuton) {
        isFarAuton = false;
        isCloseAuton = false;
        isSkillsAuton = false;
        matchLoading = false;
      }

    }
  
  if (x >= 350 && x <= 450 && y >= 10 && y <= 110) // skills auton button pressed
  {
      if (!isSkillsAuton) {
        isSkillsAuton = true;
        isCloseAuton = false;
        isFarAuton = false;
        matchLoading = false;
      } else if (isSkillsAuton) {
        isSkillsAuton = false;
        isCloseAuton = false;
        isFarAuton = false;
        matchLoading = false;
      }

  }

  if (x >= 30 && x <= 130 && y >= 130 && y <= 230) // auton mode button pressed
  {
    autonMode++;
      if (autonMode > autonModeMax) {
        autonMode = autonModeMin;
      }
      if (autonMode == 2) {
        matchLoading = false;
      }
  }

  
  if (x >= 190 && x <= 290 && y >= 130 && y <= 230) // alliance color button pressed
    {
      allianceColor++;
        if (allianceColor > allianceColorMax) {
          if (!isSkillsAuton) {
            allianceColor = (allianceColorMin + 1);
          } else if (isSkillsAuton) {
            allianceColor = (allianceColorMin);
          }
        }
    }

  
  if (x >= 350 && x <= 450 && y >= 130 && y <= 230) // match loading button pressed
    if (isCloseAuton && (autonMode != 2)) {
      if (!matchLoading) {
        matchLoading = true;
      } else if (matchLoading) {
        matchLoading = false;
      } else if (autonMode != 2) {
        matchLoading = false;
      }
    }
updateBrainScreen();
}
