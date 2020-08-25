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
#include "toolbox.h"
#include "Physics_Engine.h"
#include <ansi_c.h>
//==============================================================================
// Constants
const double GperFrame = 0.32; //What is G acceleration per frame (9.6/30 =0.32)
//==============================================================================
// Static global variables
double velocityX;
double velocityY;

//==============================================================================
// Static functions
static double CalcAirRessistence(double velocity); // internal function for air resistance calculation .
static void Velocity_Normalization (); // Hard cap for a max speed of the projectile and converting to normolized values . 
static double CalcAirRessistence(double velocity);// Calculate air resistance based on RNGesus 
//==============================================================================
// External variables
extern TANK* tanks[2]; 
extern double velocity;
extern double windPower;
static void Velocity_Normalization () 
{
	if(velocity > 150)
		velocity=75;
	else 
		velocity /= 2;
}

void InitVelocety(TANK* tank)
{
	Velocity_Normalization();
	velocityX = velocity*cos(tank->angle * (Pi() / 180));
	velocityY = velocity*sin(tank->angle * (Pi() / 180));
	
}


void CalclTrace(POSITION* position)
{
	
	velocityY= velocityY - GperFrame  ;
    velocityX -= windPower;
	position->x+= velocityX;
	position->y-= velocityY;
	
}
