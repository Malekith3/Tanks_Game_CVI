//==============================================================================
//
// Title:		Animation.h
// Purpose:		Interface for explosion animation.
//
// Created on:	26/08/2020 at 20:43:19 by Barack Samuni.
// Copyright:	Afeka academic college of engineering. All Rights Reserved.
//
//==============================================================================

#ifndef __Animation_H__
#define __Animation_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "Projectile.h"

//==============================================================================
// External variables
extern char* Explosion[15];
extern int gamePanel , pause;
extern PROJECTILE* ghostProjectiile;
//==============================================================================
// Global functions
int DrawAllScene();
int AnimateExplosion();
void DiscardAnimation();
void InitilalizeAnimation();
#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Animation_H__ */
