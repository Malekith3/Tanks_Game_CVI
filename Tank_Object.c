#include <utility.h>
#include "Tank_Game.h"
#include <ansi_c.h>
#include "Tank_Object.h"

//----------------Varaiables---------------------------------------------------//
 const double deltaAngle=(90-0)/14.0;		//15 images going from 0 to 90 degrees
//----------------------------------------------------------------------------//
POSITION* new_POSITION(double x,double y)
{
	POSITION* position=calloc(1,sizeof(POSITION));
	position->x=x;
	position->y=y;
	
	return position;
}

TANK* new_TANK(POSITION* position,double angle,int health,int* image)
{
	TANK* tank=calloc(1,sizeof(TANK));
	tank->position=position;
	tank->angle=angle;
	tank->health=health;
	tank->image=image;
	tank->Move_PosX=&Move_PosX;
	tank->Move_NegX=&Move_NegX;
	tank->LowerBarrel=&LowerBarrel;
	tank->UpperBarrel=&UpperBarrel;
	tank->Draw_Tank=&Draw_Tank;
	tank->BeenHit=&BeenHit;
	tank->DrawHealthBar=&DrawHealthBar;
	tank->SetBarrelImage=&SetBarrelImage;
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
	  PositionCheck(tank);
	
}

void Move_NegX(TANK* tank)		//moving in the negative direction of x axis
{

		tank->position->x-=2;
		PositionCheck(tank);
}

void LowerBarrel(TANK* tank)
{
	
		tank->angle-=deltaAngle;
		AngleCheck(tank);
	
}

void UpperBarrel(TANK* tank)
{
	
	tank->angle+=deltaAngle;
	AngleCheck(tank);
}

void Draw_Tank(TANK* tank)
{
	CanvasStartBatchDraw (gamePanel, Game_Panel_CANVAS);
	CanvasDrawBitmap (gamePanel, Game_Panel_CANVAS, *(tank->image), VAL_ENTIRE_OBJECT, MakeRect (tank->position->y, tank->position->x, 150, 200));
	CanvasEndBatchDraw (gamePanel, Game_Panel_CANVAS );
}

void BeenHit(TANK* tank)
{
	tank->health-=25;
}

void DrawHealthBar(TANK* tank)
{
																			
	SetCtrlAttribute (gamePanel, Game_Panel_CANVAS, ATTR_PEN_COLOR, VAL_RED);
	SetCtrlAttribute (gamePanel, Game_Panel_CANVAS, ATTR_PEN_FILL_COLOR, VAL_RED);
	CanvasDrawRect (gamePanel, Game_Panel_CANVAS, MakeRect((tank->position->y)+40,(tank->position->x)+40,10,tank->health), VAL_DRAW_FRAME_AND_INTERIOR);
}
static void AngleCheck(TANK* tank)
{
	if (tank->angle < 0)
		tank->angle = 0;
	else if(tank->angle > 180)	
		tank->angle = 180;
	else if (tank->position->x > 700 && tank->angle < 90 )
		tank->angle = 90;
	else if	(tank->position->x < 700 && tank->angle > 90 )
		tank->angle = 90;

}

void SetBarrelImage(TANK* tank,int tankIndex)
{
	free(tank->image);
	if(!tankIndex)
		tank->image=new_Image(LeftBarrel[RoundRealToNearestInteger(tank->angle/deltaAngle)]);
	else
		tank->image=new_Image(RightBarrel[RoundRealToNearestInteger((180-tank->angle)/deltaAngle)]);
}
static void PositionCheck(TANK* tank)
{
	if (tank->position->x > 1730 )
		tank->position->x = 1730;
	else if (tank->position->x < 0)
		tank->position->x = 0;
	else if(tank->position->x > 400 && tank->angle < 90 )
		tank->position->x = 400;
	else if(tank->position->x < 1250 && tank->angle > 90 )
		tank->position->x = 1250;	
}





