//==============================================================================
//
// Title:		Sound.h
// Purpose:		A short description of the interface.
//
// Created on:	12/08/2020 at 19:59:41 by Barack Samuni.
// Copyright:	Afeka academic college of engineering. All Rights Reserved.
//
//==============================================================================

#ifndef __Sound_H__
#define __Sound_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"
#include "ActiveX_WMP.h"
#include "Tank_Game.h"
//==============================================================================
// Constants
#define ThemeSong "Sounds\\ha_ha_youre_dead_lyrics_green_day.mp3"
#define ShootingSFX "Sounds\\Tank_Shooting.mp3"
//==============================================================================
// Types

//==============================================================================
// External variables
extern CAObjHandle WMP_Handle;
extern int wmp_Panel;
//==============================================================================
// Global functions

void Create_WMP_Handle ();
void PlaySound(char* path);		//plays a sound effect specified by path
void StopSound();				//stops all sound
void SetVolume(long volume);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Sound_H__ */
