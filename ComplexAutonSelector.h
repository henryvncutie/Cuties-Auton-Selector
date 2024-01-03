using namespace vex
#include "vex.h"

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
extern bool isCloseAuton;
extern bool isFarAuton;
extern bool isSkillsAuton;
extern int autonMode;
extern int autonModeMin;
extern int autonModeMax;
extern int allianceColor;
extern int allianceColorMin;
extern int allianceColorMax;
extern bool matchLoading;
extern bool isPreAuton;


//Functions
extern void updateBrainScreen(void);
extern void updateControllerScreen(void);
extern void drawGUI(void);
extern void selectAuton(void);
extern void nothingAuton(void);
