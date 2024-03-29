//==============================================================================
//
// Title:		Projectile.h
// Purpose:		Interface for Projectile class.
//
// Created on:	10/08/2020 at 8:48:35 by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

#ifndef __Projectile_H__
#define __Projectile_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "Tank_Object.h"

//==============================================================================
// Types
		


typedef struct projectile
{
	POSITION* position; // Position of projectile 
	
	void (*Draw_Projectile)(struct projectile* self); // Drawing projectile on canvas 
	void (*Fire_Projectile)(struct projectile* self , TANK* tank);
	

}PROJECTILE;


//==============================================================================
// External variables
extern TANK* tanks[2];
extern int gamePanel;
extern double velocityX;
extern double velocityY;
//==============================================================================
// Global functions
PROJECTILE* new_PROJECTILE(POSITION* position); // PROJECTILE constructor
void Draw_Projectile(PROJECTILE* projectile); 
void Fire_Projectile(PROJECTILE* projectile, TANK* tank);
int DrawAllScene();
#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Projectile_H__ */
