//==============================================================================
//
// Title:		Ground_Object.c
// Purpose:		Module for drawing Ground (Its not finale)
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

GROUND* new_Ground()
{
	GROUND* ground=calloc(1,sizeof(GROUND));
	ground->Draw_Ground=Draw_Ground;
	return ground;
}

void Draw_Ground(struct ground* self)
{
	SetCtrlAttribute (gamePanel, Game_Panel_CANVAS, ATTR_PEN_COLOR, VAL_DK_GREEN);
	SetCtrlAttribute (gamePanel, Game_Panel_CANVAS, ATTR_PEN_FILL_COLOR, VAL_DK_GREEN);
	
	CanvasStartBatchDraw (gamePanel, Game_Panel_CANVAS);
	CanvasDrawRect (gamePanel, Game_Panel_CANVAS, MakeRect(600,0,500,1920), VAL_DRAW_FRAME_AND_INTERIOR);
	CanvasDrawOval (gamePanel, Game_Panel_CANVAS, MakeRect(300,750,700,300), VAL_DRAW_FRAME_AND_INTERIOR);
	SetCtrlAttribute (gamePanel, Game_Panel_CANVAS, ATTR_PEN_WIDTH, 200);
	CanvasDrawLine (gamePanel, Game_Panel_CANVAS,MakePoint(700,700) ,MakePoint(850,310) );// line is starting at 600px
	CanvasDrawLine (gamePanel, Game_Panel_CANVAS,MakePoint(1300,700) ,MakePoint(900,340) );// line is starting at 1300px
	SetCtrlAttribute (gamePanel, Game_Panel_CANVAS, ATTR_PEN_WIDTH, 3);
	
	CanvasEndBatchDraw (gamePanel, Game_Panel_CANVAS );
	
}