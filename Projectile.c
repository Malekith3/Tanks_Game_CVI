//==============================================================================
//
// Title:		Projectile.c
// Purpose:		A short description of the implementation.
//
// Created on:	10/08/2020 at 8:48:35 by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <userint.h>
#include <ansi_c.h>
#include "Projectile.h"
#include "Physics_Engine.h"
#include "Tank_Game.h"
#include "Sound.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
PROJECTILE* new_PROJECTILE(POSITION* position)
{
	PROJECTILE* projectile=calloc(1,sizeof(PROJECTILE));
	projectile->position = position;
	projectile->Draw_Projectile = &Draw_Projectile ; 
	projectile->Fire_Projectile = &Fire_Projectile;
	return projectile;


}
void Fire_Projectile(PROJECTILE* projectile , TANK* tank)
{
	PlaySound(ShootingSFX);
	InitVelocety(tank);
	projectile->position->x = tank->position->x +200;
	projectile->position->y = tank->position->y +50;
}
void Draw_Projectile(PROJECTILE* projectile)
{
	
	CalclTrace(projectile->position);
	CanvasStartBatchDraw (gamePanel, Game_Panel_CANVAS);
	CanvasDrawRect (gamePanel, Game_Panel_CANVAS,MakeRect(projectile->position->y,projectile->position->x,5,5), VAL_DRAW_FRAME);
	CanvasEndBatchDraw (gamePanel, Game_Panel_CANVAS );
	
	
}