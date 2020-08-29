//==============================================================================
//
// Title:		Collison_Module.h
// Purpose:		Collison interface for projectile .
//
// Created on:	8/22/2020 at 3:09:46 PM by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

#ifndef __Collison_Module_H__
#define __Collison_Module_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "Tank_Object.h"
#include "Projectile.h"
#include "Ground_Object.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables
extern TANK* tanks[2];
extern GROUND* ground;
extern int gameOver;
extern int gamePanel;
extern int gameOverPanel;

//==============================================================================
// Global functions
void DetectCollision(PROJECTILE* projectile);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Collison_Module_H__ */
