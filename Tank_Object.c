#include "Tank_Object.h"

POSITION* new_POSITION(double x,double y)
{
	Position position=calloc(1,sizeof(POSITION));
	position->x=x;
	position->y=y;
	
	return position;
}

TANK* new_TANK(POSITION position,double angle,char* image)
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

void MoveForward(TANK* tank)
{
	tank->position.x+=2;
}

void Reverse(Tank* tank)
{
	tank->position.x-=2;
}

void LowerBarrel(Tank* tank)
{
	tamk->angle-=2;
}

void UpperBarrel(Tank* tank)
{
	tank->angle+=2;
}

void Draw(Tank* tank)
{
	//implement later
}


