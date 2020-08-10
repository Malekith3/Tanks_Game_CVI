#include "Tank_Game.h"
#include <ansi_c.h>
#include "Tank_Object.h"

extern int gamePanel;

POSITION* new_POSITION(double x,double y)
{
	POSITION* position=calloc(1,sizeof(POSITION));
	position->x=x;
	position->y=y;
	
	return position;
}

TANK* new_TANK(POSITION* position,double angle,int* image)
{
	TANK* tank=calloc(1,sizeof(TANK));
	tank->position=position;
	tank->angle=angle;
	tank->image=image;
	tank->Move_PosX=&Move_PosX;
	tank->Move_NegX=&Move_NegX;
	tank->LowerBarrel=&LowerBarrel;
	tank->UpperBarrel=&UpperBarrel;
	tank->Draw_Tank=&Draw_Tank;
	
	return tank;
}
int* new_Image(char* path)
{
	int* image = calloc(1 , sizeof(int));
	GetBitmapFromFile(path,image);
	return image;
}
void Move_PosX(TANK* tank)		//moving in the positive direction of x axis
{
	tank->position->x+=2;
}

void Move_NegX(TANK* tank)		//moving in the negative direction of x axis
{
	tank->position->x-=2;
}

void LowerBarrel(TANK* tank)
{
	tank->angle-=2;
}

void UpperBarrel(TANK* tank)
{
	tank->angle+=2;
}

void Draw_Tank(TANK* tank)
{
	CanvasStartBatchDraw (gamePanel, Game_Panel_CANVAS);
	CanvasDrawBitmap (gamePanel, Game_Panel_CANVAS, *(tank->image), VAL_ENTIRE_OBJECT, MakeRect (tank->position->y, tank->position->x, 150, 200));
}


