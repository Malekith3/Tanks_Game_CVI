//==============================================================================
//
// Title:		Ground_Object.c
// Purpose:		Ground class witn constractor and Draw method .
//
// Created on:	21/08/2020 at 9:03:48 by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <userint.h>
#include <ansi_c.h>
#include "Ground_Object.h"
#include "Tank_Game.h"
//==============================================================================
GROUND* new_Ground(int* image)
{
	GROUND* ground=calloc(1,sizeof(GROUND));
	ground->Draw_Ground=Draw_Ground;
	ground->image = image;
	return ground;
}

void Draw_Ground(struct ground* self )
{
	
	CanvasStartBatchDraw (gamePanel, Game_Panel_CANVAS);
	CanvasDrawBitmap (gamePanel, Game_Panel_CANVAS,*(self->image) , VAL_ENTIRE_OBJECT, MakeRect (0, 0, 1080, 1920));
	CanvasEndBatchDraw (gamePanel, Game_Panel_CANVAS );
	
}