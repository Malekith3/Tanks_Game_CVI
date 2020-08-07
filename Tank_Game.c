#include <cvirte.h>		
#include <userint.h>
#include "Tank_Game.h"
#include "Tank_Object.h"

int mainPanel;


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((mainPanel = LoadPanel (0, "Tank_Game.uir", Main_Panel)) < 0)
		return -1;
	DisplayPanel (mainPanel);
	
	
	TANK* tank1 = new_TANK(new_POSITION(10.00,10.00),100.00,new_Image("Assets//Tank.ico"));
	tank1->Draw(tank1);
	
	RunUserInterface ();
	DiscardPanel (mainPanel);
	return 0;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
