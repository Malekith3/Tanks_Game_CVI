//==============================================================================
//
// Title:		Ground_Object.h
// Purpose:		Interface for creating and drawing ground
//
// Created on:	21/08/2020 at 9:03:48 by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

#ifndef __Ground_Object_H__
#define __Ground_Object_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types
 typedef struct ground
{
	int* image; 
	void (*Draw_Ground)(struct ground* self); // Drawing ground on canvas 
	
}GROUND;

//==============================================================================
// External variables
	extern int gamePanel;
//==============================================================================
// Global functions
void Draw_Ground(struct ground* self); // drawing ground on canvas
GROUND* new_Ground(); // creating ground object

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Ground_Object_H__ */
