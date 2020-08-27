/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  Controls                         1
#define  Controls_Both_Tanks_Text         2       /* control type: string, callback function: (none) */
#define  Controls_Left_Tank_Text          3       /* control type: string, callback function: (none) */
#define  Controls_QUITBUTTON2             4       /* control type: command, callback function: QuitCallback */
#define  Controls_Right_Tank_Text         5       /* control type: string, callback function: (none) */
#define  Controls_RightTank_Shoot_Str     6       /* control type: string, callback function: (none) */
#define  Controls_LeftTank_Reverse_Str    7       /* control type: string, callback function: (none) */
#define  Controls_RightTank_Reverse_Str   8       /* control type: string, callback function: (none) */
#define  Controls_LeftTank_Forward_Str    9       /* control type: string, callback function: (none) */
#define  Controls_RightTank_Forward_Str   10      /* control type: string, callback function: (none) */
#define  Controls_LeftTank_Down_String    11      /* control type: string, callback function: (none) */
#define  Controls_RightTank_Down_String   12      /* control type: string, callback function: (none) */
#define  Controls_Mute_String             13      /* control type: string, callback function: (none) */
#define  Controls_Options_String          14      /* control type: string, callback function: (none) */
#define  Controls_LeftTank_Up_String      15      /* control type: string, callback function: (none) */
#define  Controls_RightTank_Up_String     16      /* control type: string, callback function: (none) */
#define  Controls_ArrowDownPic            17      /* control type: picture, callback function: (none) */
#define  Controls_ArrowRightPic           18      /* control type: picture, callback function: (none) */
#define  Controls_PICTURE_2               19      /* control type: picture, callback function: (none) */
#define  Controls_W_Key_Pic               20      /* control type: picture, callback function: (none) */
#define  Controls_PICTURE                 21      /* control type: picture, callback function: (none) */
#define  Controls_SpaceBarPic             22      /* control type: picture, callback function: (none) */
#define  Controls_S_Key_Pic               23      /* control type: picture, callback function: (none) */
#define  Controls_D_Key_Pic               24      /* control type: picture, callback function: (none) */
#define  Controls_Back_Button             25      /* control type: command, callback function: Back_To_Main */
#define  Controls_A_Key_Pic               26      /* control type: picture, callback function: (none) */
#define  Controls_Esc_Pic                 27      /* control type: picture, callback function: (none) */
#define  Controls_CloseControls           28      /* control type: command, callback function: ResumeGame */
#define  Controls_Back_To_Options         29      /* control type: command, callback function: Back_To_Options */
#define  Controls_M_Key_Pic               30      /* control type: picture, callback function: (none) */

#define  Game_Panel                       2
#define  Game_Panel_CANVAS                2       /* control type: canvas, callback function: (none) */
#define  Game_Panel_TIMER                 3       /* control type: timer, callback function: MyTimer */

#define  GameOver                         3
#define  GameOver_New_Game_Button         2       /* control type: command, callback function: Start_Game */
#define  GameOver_QUITBUTTON4             3       /* control type: command, callback function: QuitCallback */
#define  GameOver_Tank_Won_String         4       /* control type: string, callback function: (none) */

#define  Menu_Panel                       4
#define  Menu_Panel_Start_Game            2       /* control type: command, callback function: Start_Game */
#define  Menu_Panel_Controls_Button       3       /* control type: command, callback function: Show_Controls */
#define  Menu_Panel_QUITBUTTON            4       /* control type: command, callback function: QuitCallback */
#define  Menu_Panel_MuteBUTTON            5       /* control type: pictButton, callback function: Mute_Callback */
#define  Menu_Panel_Volume_String2        6       /* control type: string, callback function: (none) */
#define  Menu_Panel_NUMERICSLIDE          7       /* control type: scale, callback function: ChangeVolume */

#define  OptionsScr                       5
#define  OptionsScr_Resume_Button         2       /* control type: command, callback function: ResumeGame */
#define  OptionsScr_Review_Controls       3       /* control type: command, callback function: Show_Controls */
#define  OptionsScr_QUITBUTTON3           4       /* control type: command, callback function: QuitCallback */
#define  OptionsScr_MuteBUTTON2           5       /* control type: pictButton, callback function: Mute_Callback */
#define  OptionsScr_Volume_String         6       /* control type: string, callback function: (none) */
#define  OptionsScr_NUMERICSLIDE          7       /* control type: scale, callback function: ChangeVolume */

#define  WMP_Panel                        6
#define  WMP_Panel_WINDOWSMEDIAPLAYER     2       /* control type: activeX, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back_To_Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Back_To_Options(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ChangeVolume(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Mute_Callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MyTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ResumeGame(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Show_Controls(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start_Game(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif