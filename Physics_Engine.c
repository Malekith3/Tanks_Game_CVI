//==============================================================================
//
// Title:		Physics_Engine.c
// Purpose:		Physics engine to calculate projectile trajectory and wind resistance .
//
// Created on:	09/08/2020 at 17:31:08 by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files
#include "Physics_Engine.h"
#include <ansi_c.h>
#include "toolbox.h"
//==============================================================================
// Constants
const double GperFrame = 0.32; //What is G acceleration per frame (9.6/30 =0.32)
//==============================================================================
// Static global variables
static double velocityX;
static double velocityY;
static double Wind;
//==============================================================================
// Static functions
static double CalcAirRessistence(double velocity); // internal function for air resistance calculation .
static void Velocity_Normalization (); // Hard cap for a max speed of the projectile and converting to normolized values . 
static double CalcAirRessistence(double velocity);// Calculate air resistance based on RNGesus 
//==============================================================================
// External variables
extern TANK* tanks[2]; 
extern double velocity;

static void Velocity_Normalization () 
{
	if(velocity > 300)
		velocity=150;
	else 
		velocity /= 2;
}

void InitVelocety(TANK* tank)
{
	Velocity_Normalization();
	velocityX = velocity*cos(tank->angle * (Pi() / 180));
	velocityY = velocity*sin(tank->angle * (Pi() / 180));
	Wind = Random (-1, 1);
}

static double CalcAirRessistence(double velocity){ return Random (-1, 1);}

void CalclTrace(POSITION* position)
{
	
	velocityY= velocityY - GperFrame - (velocityY * 0.1) ;
    velocityX -= (velocityX*0.05 + Wind);
	position->x+= velocityX;
	position->y-= velocityY;
	// For debugging purposes 
	//printf("{ %f } { %f }",tanks[0]->position->x, tanks[0]->position->y);
	//printf("{ %f } { %f }", tanks[0]->position->x + velocityX , tanks[0]->position->y - velocityY );
	
}
