#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Tank_Game.h"
#include "Tank_Object.h"
void InitializeTanks();
int menuPanel,gamePanel,controlsPanel;
static int turn=0;
TANK* tanks[2];
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
	DisplayPanel (menuPanel);
	InitializeTanks();
	RunUserInterface ();
	DiscardPanel (menuPanel);
	DiscardPanel (gamePanel);
	DiscardPanel (controlsPanel);
	return 0;
}

int CVICALLBACK Keys (int panel, int event, void *callbackData,  
						   int eventData1, int eventData2)
{
	switch(event)
	{
		case EVENT_KEYPRESS:
			switch(eventData1)
			{
				case 0x20:								//Spacebar ASCII code
					printf("Alla Acbar!!!!!!!!\n");		//of course this is garbage and will be deleted later
					turn=!turn;							//turn ended
					break;
					
				case 0x300:								//Esc VKEY
					if(GenericMessagePopup ("Quit Confirmation", "Are you sure you want to quit?", "Yes", "No", 0, 0, 0, 0, VAL_GENERIC_POPUP_BTN1, VAL_GENERIC_POPUP_BTN1, VAL_GENERIC_POPUP_BTN2)==VAL_GENERIC_POPUP_BTN1)	//Yes
						QuitUserInterface(0);
					break;
					
				case 0x77:							//'w' ASCII code(it is not case-sensitive of course because it is the same key)
					if(!turn)						//active only at the turn of the left tank
					{
						tanks[0]->UpperBarrel(tanks[0]);
						printf("%lf\n",tanks[0]->angle);	//garbage
					}
					break;
					
				case 0x73:							//'s' ASCII code
					if(!turn)
					{
						tanks[0]->LowerBarrel(tanks[0]);
						printf("%lf\n",tanks[0]->angle);	//garbage
					}
					break;
						
				case 0x61:							//'a' ASCII code
					if(!turn)
					{
						tanks[0]->Move_NegX(tanks[0]);
						tanks[0]->Draw(tanks[0]);
					}
					break;
					
				case 0x64:							//'d' ASCII code
					if(!turn)
					{
						tanks[0]->Move_PosX(tanks[0]);
						tanks[0]->Draw(tanks[0]);
					}
					break;
						
				case 0x600:								//Arrow Up Vkey
					if(turn)
					{
						tanks[1]->UpperBarrel(tanks[1]);
						printf("%lf\n",tanks[1]->angle);	//garbage
					}
					break;
				
				case 0x700: 							//Arrow Down Vkey
					if(turn)
					{
						tanks[1]->LowerBarrel(tanks[1]);
						printf("%lf\n",tanks[1]->angle);	//garbage
					}
					break;
				
				case 0x800:								//Arrow Left Vkey
					if(turn)
					{
						tanks[1]->Move_NegX(tanks[1]);
						tanks[1]->Draw(tanks[1]);
					}
					break;
				
				case 0x900:								//Arrow Right Vkey
					if(turn)
					{
						tanks[1]->Move_PosX(tanks[1]);
						tanks[1]->Draw(tanks[1]);
					}
					break;
			}	
					
			
		break;
	}
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
				tanks[i]->Draw(tanks[i]);
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

void InitializeTanks()
{
	tanks[0]=new_TANK(new_POSITION(10.00,100.00),100.00,new_Image("Assets//Tank.ico"));
	tanks[1]=new_TANK(new_POSITION(740.00,100.00),100.00,new_Image("Assets//Tank2.ico"));
	
}
