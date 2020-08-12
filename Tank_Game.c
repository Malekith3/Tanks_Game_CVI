#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Tank_Game.h"
#include "Tank_Object.h"
#include <Windows.h>
#include "toolbox.h"
#include "Projectile.h"


///////////////////////////Functions/////////////////////
void InitializeTanks();
int CVICALLBACK KeyupCallback(int gamePanel, int message,unsigned int* wParam,unsigned int* lParam,void* callbackData);
int menuPanel,gamePanel,controlsPanel;
static int turn;
double velocity;
static PROJECTILE* projectile;
TANK* tanks[2];
static int postinghandle;
enum status {First_Tank_Fire,Second_Tank_Fire,No_One_Fire};
enum status turn;
int cnt = 0;


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((menuPanel = LoadPanel (0, "Tank_Game.uir", Menu_Panel)) < 0)
		return -1;
	if ((gamePanel = LoadPanel (0, "Tank_Game.uir", Game_Panel)) < 0)
		return -1;
	if ((controlsPanel = LoadPanel (0, "Tank_Game.uir", Controls)) < 0)
		return -1;
	InstallWinMsgCallback (gamePanel, WM_KEYUP, KeyupCallback,
							VAL_MODE_IN_QUEUE, NULL, &postinghandle);
	InstallWinMsgCallback (gamePanel, WM_KEYDOWN, KeyupCallback,
							VAL_MODE_IN_QUEUE, NULL, &postinghandle);
	InitializeTanks();
	DisplayPanel (menuPanel);
	RunUserInterface ();
	DiscardPanel (menuPanel);
	DiscardPanel (gamePanel);
	DiscardPanel (controlsPanel);
	return 0;
}


int CVICALLBACK Start_Game (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(menuPanel);					
			DisplayPanel(gamePanel);
			for(int i=0;i<2;i++)
				tanks[i]->Draw_Tank(tanks[i]);
			break;
	}
	return 0;
}

int CVICALLBACK Show_Controls (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(menuPanel);					
			DisplayPanel(controlsPanel);
			break;
	}
	return 0;
}



int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface(0);
			break;
	}
	return 0;
}

int CVICALLBACK Back_To_Main (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			HidePanel(controlsPanel);					
			DisplayPanel(menuPanel);
			break;
	}
	return 0;
}
int CVICALLBACK KeyupCallback(int gamePanel, int message,unsigned int* wParam,unsigned int* lParam, void* callbackData)
{
	
switch ( message)	
{
	case WM_KEYUP:
		
		switch(*wParam)
		{
			case VK_SPACE:
				
				
				if(!turn)
				{
					turn = First_Tank_Fire;
					Fire_Projectile(projectile,tanks[0]);
					SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 1);
					
				}
				else
				{
					turn = Second_Tank_Fire;
					Fire_Projectile(projectile,tanks[1]);
					SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 1);
				}
				turn=!turn;
				velocity = 0.00;
				break;
		}
		
	case WM_KEYDOWN:
		
		switch (*wParam)
		{
			case VK_SPACE:		//space Key 		
				velocity+=5.00;	// When you hold space key velocity will increase 
				break;
				
			case VK_ESCAPE:								//Esc KEY
					if(GenericMessagePopup ("Quit Confirmation", "Are you sure you want to quit?", "Yes", "No", 0, 0, 0, 0, VAL_GENERIC_POPUP_BTN1, VAL_GENERIC_POPUP_BTN1, VAL_GENERIC_POPUP_BTN2)==VAL_GENERIC_POPUP_BTN1)	//Yes
						QuitUserInterface(0);
					break;
			case 0x57:								//'w' Windows Virtual Key Code(it is not case-sensitive of course because it is the same key)
					if(!turn)						//active only at the turn of the left tank
					{
						tanks[0]->UpperBarrel(tanks[0]);
						printf("%lf\n",tanks[0]->angle);	//garbage
					}
					break;
			case 0x53:							//'s' Windows Virtual Key Code
					if(!turn)
					{
						tanks[0]->LowerBarrel(tanks[0]);
						printf("%lf\n",tanks[0]->angle);	//garbage
					}
					break;
		    case 0x41:							//'a' Windows Virtual Key Code
					if(!turn)
					{
						tanks[0]->Move_NegX(tanks[0]);
						tanks[0]->Draw_Tank(tanks[0]);
					}
					break;
			case 0x44:							//'d' Windows Virtual Key Code
					if(!turn)
					{
						tanks[0]->Move_PosX(tanks[0]);
						tanks[0]->Draw_Tank(tanks[0]);
					}
					break;
							
			case 0x26:								//Arrow Up Vkey
					if(turn)
					{
						tanks[1]->UpperBarrel(tanks[1]);
						printf("%lf\n",tanks[1]->angle);	//garbage
					}
					break;
			case 0x28: 							//Arrow Down Vkey
					if(turn)
					{
						tanks[1]->LowerBarrel(tanks[1]);
						printf("%lf\n",tanks[1]->angle);	//garbage
					}
					break;
			case 0x25:								//Arrow Left Vkey
					if(turn)
					{
						tanks[1]->Move_NegX(tanks[1]);
						tanks[1]->Draw_Tank(tanks[1]);
					}
					break;
			case 0x27:								//Arrow Right Vkey
					if(turn)
					{
						tanks[1]->Move_PosX(tanks[1]);
						tanks[1]->Draw_Tank(tanks[1]);
					}
					break;		
		}
}
	return 0;
}
int CVICALLBACK MyTimer (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	 
	switch (event)
	{
		case EVENT_TIMER_TICK:
			Draw_Projectile(projectile);
			cnt++;
			if(cnt == 1000)
			{
				cnt=0;
				SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
			
			}
			break;	
			
						
	}
	return 0;
}

void InitializeTanks()
{
	tanks[0]=new_TANK(new_POSITION(10.00,500.00),50.00,new_Image("Assets//Tank.ico"));
	tanks[1]=new_TANK(new_POSITION(740.00,500.00),130.00,new_Image("Assets//Tank2.ico"));
	projectile = new_PROJECTILE(new_POSITION(0,0));
}


