#include <userint.h>

//==============================================================================
//
// Title:		Sound.c
// Purpose:		This file contains macro definitions of sound files, and also sound functions
//
// Created on:	12/08/2020 at 19:59:41 by Barack Samuni.
// Copyright:	Afeka academic college of engineering. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "Sound.h"
#include "Tank_Game.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
static CAObjHandle WMP_Handle;
static VBOOL mute;
//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

void Create_WMP_Handle ()		
{
	GetObjHandleFromActiveXCtrl (wmp_Panel, WMP_Panel_WINDOWSMEDIAPLAYER, &WMP_Handle);
}

void PlaySound(char* path)
{
	
	//WMPLib_IWMPSettingsGetmute (WMP_Handle, NULL, &mute);
	//if(mute==VFALSE)
	WMPLib_IWMPPlayer4SetURL (WMP_Handle, NULL, path);

}

void StopSound()
{
	WMPLib_IWMPControlsstop (WMP_Handle, NULL);
}

void SetVolume(long volume)
{
	WMPLib_IWMPSettingsGetmute (WMP_Handle, NULL, &mute);
	if(!mute)
		WMPLib_IWMPSettingsSetvolume (WMP_Handle, NULL, volume);
}

void ToggleMute()			//mutes/unmutes the sound
{
	
	WMPLib_IWMPSettingsGetmute (WMP_Handle, NULL, &mute);
	mute=!mute;
	WMPLib_IWMPSettingsSetmute (WMP_Handle, NULL,mute);
	
}






