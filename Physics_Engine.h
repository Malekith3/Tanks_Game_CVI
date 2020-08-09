//==============================================================================
//
// Title:		Physics_Engine.h
// Purpose:		A short description of the interface.
//
// Created on:	09/08/2020 at 17:31:08 by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

#ifndef __Physics_Engine_H__
#define __Physics_Engine_H__

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

//==============================================================================
// External variables
extern TANK* tanks[2]; 
extern double velocity;
//==============================================================================
// Global functions
	void InitVelocety();//    Setting Initial speed of projectile based on how long spacebar is pressed 
	void CalclTrace(); // Calculating the next position of a projectile in the next frame 

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Physics_Engine_H__ */
