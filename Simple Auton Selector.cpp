"Simple Auton Selector"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Simple Auton Selector                                     */
/*    Author:       Henry from 3142C                                          */
/*    Created:      Jan 2 24                                                  */
/*    Description:  Simple version of 3142's Auton selector                   */
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
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(30, 10, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(40, 30, "Close");
  } else if (isCloseAuton) {
    Brain.Screen.setFillColor(white);
    Brain.Screen.setPenColor(black);
    Brain.Screen.drawRectangle(30, 10, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(40, 30, "Close");
  }
  
  if (!isFarAuton) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(190, 10, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(200, 30, "Far");
  } else if (isFarAuton) {
    Brain.Screen.setFillColor(white);
    Brain.Screen.setPenColor(black);
    Brain.Screen.drawRectangle(190, 10, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(200, 30, "Far");
  }

  if (!isSkillsAuton) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(350, 10, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(360, 30, "Skills");
  } else if (isSkillsAuton) {
    Brain.Screen.setFillColor(white);
    Brain.Screen.setPenColor(black);
    Brain.Screen.drawRectangle(350, 10, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(360, 30, "Skills");
  }

  if (autonMode == 0) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(30, 130, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(40, 150, "Safe ");
  } else if (autonMode == 1) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(30, 130, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(40, 150, "Risky");
  } else if (autonMode == 2) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(30, 130, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(40, 150, "AWP  ");
  }
  
  if (allianceColor == 0) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(190, 130, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(200, 150, "Alliance");*/
  } else if (allianceColor == 1) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(190, 130, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(200, 150, "Red     ");
  } else if (allianceColor == 2) {
    Brain.Screen.setFillColor(blue);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(190, 130, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(200, 150, "Blue    ");
  } 

  if (!matchLoading) {
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(350, 130, 100, 100);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(360, 150, "Loader");
  } else if (matchLoading) {
    Brain.Screen.setFillColor(white);
    Brain.Screen.setPenColor(black);
    Brain.Screen.drawRectangle(350, 130, 100, 100);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(360, 150, "Loader");
  }
  }
    
void brainLicensePlate() {
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  if (allianceColor == 1) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(red);
  } else if (allianceColor == 2) {
    Brain.Screen.setFillColor(blue);
    Brain.Screen.setPenColor(blue);
  }
  Brain.Screen.drawRectangle(0, 0, 480, 240);
  Brain.Screen.setFont(prop60);
  if (allianceColor == 1) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(white);
  } else if (allianceColor == 2) {
    Brain.Screen.setFillColor(blue);
    Brain.Screen.setPenColor(black);
  }
  Brain.Screen.printAt(170, 120, "CUTIES");
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










