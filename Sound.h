//==============================================================================
//
// Title:		Sound.h
// Purpose:		Interface for sound play functions.
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

#include "ActiveX_WMP.h"
//==============================================================================
// Constants
#define ThemeSong "Sounds\\ha_ha_youre_dead_lyrics_green_day.mp3"
#define ShootingSFX "Sounds\\Tank_Shooting.mp3"
#define ExplosionSFX "Sounds\\Explosion.mp3"
#define InitialVolume 50

//==============================================================================
// External variables
extern int wmp_Panel;
//==============================================================================
// Global functions

void Create_WMP_Handle ();
void PlaySound(char* path);		//plays a sound effect specified by path
void StopSound();				//stops all sound
void SetVolume(long volume);
void ToggleMute();				//mutes\unmutes sound


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Sound_H__ */
