//==============================================================================
//
// Title:		Animation.c
// Purpose:		includes Animation function
//
// Created on:	26/08/2020 at 20:43:19 by Barack Samuni.
// Copyright:	Afeka academic college of engineering. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <userint.h>
#include <utility.h>
#include "Animation.h"
#include "Tank_Game.h"
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
int* AnimationImage;
//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?

void AnimateExplosion() 
{
	for(int i=0;i<15;i++)
	{
		GetBitmapFromFile(Explosion[i],AnimationImage);
		CanvasStartBatchDraw (gamePanel, Game_Panel_CANVAS);
		CanvasDrawBitmap (gamePanel, Game_Panel_CANVAS, *(AnimationImage), VAL_ENTIRE_OBJECT, MakeRect (projectile->position->y, projectile->position->x, 468, 417));
		Delay(1.0/15.0);
		CanvasEndBatchDraw (gamePanel, Game_Panel_CANVAS);
	}
	
}
void InitilalizeAnimation()
{
	AnimationImage=calloc(1,sizeof(int));
}

void DiscardAnimation()
{
	free(AnimationImage);
}
