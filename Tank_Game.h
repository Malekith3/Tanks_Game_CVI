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
#define  Controls_Quit_String             13      /* control type: string, callback function: (none) */
#define  Controls_LeftTank_Up_String      14      /* control type: string, callback function: (none) */
#define  Controls_RightTank_Up_String     15      /* control type: string, callback function: (none) */
#define  Controls_ArrowDownPic            16      /* control type: picture, callback function: (none) */
#define  Controls_ArrowRightPic           17      /* control type: picture, callback function: (none) */
#define  Controls_PICTURE_2               18      /* control type: picture, callback function: (none) */
#define  Controls_W_Key_Pic               19      /* control type: picture, callback function: (none) */
#define  Controls_PICTURE                 20      /* control type: picture, callback function: (none) */
#define  Controls_SpaceBarPic             21      /* control type: picture, callback function: (none) */
#define  Controls_S_Key_Pic               22      /* control type: picture, callback function: (none) */
#define  Controls_D_Key_Pic               23      /* control type: picture, callback function: (none) */
#define  Controls_Back_Button             24      /* control type: command, callback function: Back_To_Main */
#define  Controls_A_Key_Pic               25      /* control type: picture, callback function: (none) */
#define  Controls_Esc_Pic                 26      /* control type: picture, callback function: (none) */

#define  Game_Panel                       2
#define  Game_Panel_CANVAS                2       /* control type: canvas, callback function: (none) */

#define  Menu_Panel                       3
#define  Menu_Panel_Start_Game            2       /* control type: command, callback function: Start_Game */
#define  Menu_Panel_Controls_Button       3       /* control type: command, callback function: Show_Controls */
#define  Menu_Panel_QUITBUTTON            4       /* control type: command, callback function: QuitCallback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Back_To_Main(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Show_Controls(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start_Game(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif