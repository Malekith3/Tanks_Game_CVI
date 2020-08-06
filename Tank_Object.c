#include "Tank_Game.h"
#include <ansi_c.h>
#include "Tank_Object.h"

extern int mainPanel;

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
	tank->MoveForward=MoveForward;
	tank->Reverse=Reverse;
	tank->LowerBarrel=LowerBarrel;
	tank->UpperBarrel=UpperBarrel;
	tank->Draw=Draw;
	
	return tank;
}
int* new_Image(char* path)
{
	int* image = calloc(1 , sizeof(int));
	GetBitmapFromFile(path,image);
	return image;
}
void MoveForward(TANK* tank)
{
	tank->position->x+=2;
}

void Reverse(TANK* tank)
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

void Draw(TANK* tank)
{
	CanvasStartBatchDraw (mainPanel, Main_Panel_CANVAS);
	CanvasDrawBitmap (mainPanel, Main_Panel_CANVAS, *(tank->image), VAL_ENTIRE_OBJECT, MakeRect(tank->position->x,tank->position->y,150,200));
}


