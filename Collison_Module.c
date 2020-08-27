//==============================================================================
//
// Title:		Collison_Module.c
// Purpose:		A short description of the implementation.
//
// Created on:	8/22/2020 at 3:09:46 PM by Alex Bordeaux.
// Copyright:	Student. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files


#include <userint.h>
#include "Collison_Module.h"
#include "Tank_Game.h"
#include <utility.h>
#include "Animation.h"
//==============================================================================
// Constants
const double C_Y = 480,C_X =1280 , A_X =600 ,A_Y = 500 ,B_X =940 , B_Y =120 ;

//==============================================================================
// Types

//==============================================================================
// Static global variables
extern CmtThreadPoolHandle MY_THREAD_POOL , AnimationID;
//==============================================================================
// Static functions
static void CheckCollisionForProjectileAndGround(PROJECTILE* projectile);
static int poinInTriangle(PROJECTILE* projectile); // function to determine if point in triangle
static int TankProjectileCollDitection(PROJECTILE* projectile);//
static void SaveStateOfProjectile(PROJECTILE* projectile);//
//==============================================================================
// Global variables
PROJECTILE* ghostProjectiile;
//==============================================================================
// Global functions
extern int DrawAllScene();

void DetectCollision(PROJECTILE* projectile)
{
	CheckCollisionForProjectileAndGround(projectile);
	//Cheking mounten collision
	if(poinInTriangle(projectile))
	{
		SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
		//DrawAllScene();
		SaveStateOfProjectile(projectile);
		CmtScheduleThreadPoolFunction (MY_THREAD_POOL, AnimateExplosion, NULL, &AnimationID);
		projectile->position->y = 1090;
		SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
		DrawAllScene();
		
	
	}
	//cheking colision projectile and tank
	
		for (int i = 0; i<2; i++)
		{
			if (tanks[i]->position->x -50 < projectile->position->x && tanks[i]->position->x + 250 > projectile->position->x && tanks[i]->position->y+50 < projectile->position->y && tanks[i]->position->y + 150 > projectile->position->y )
			{
				SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
				SaveStateOfProjectile(projectile);
				CmtScheduleThreadPoolFunction (MY_THREAD_POOL, AnimateExplosion, NULL, &AnimationID);
				projectile->position->y = 1090;
				SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
				DrawAllScene();
				tanks[i]->BeenHit(tanks[i]);
				if(tanks[i]->health==0)			//tank is dead
				{
					gameOver=1;
					CanvasClear (gamePanel, Game_Panel_CANVAS, MakeRect (tanks[i]->position->y, tanks[i]->position->x, 313, 417));		//undraw tank
					ground->Draw_Ground(ground);
					tanks[!i]->Draw_Tank(tanks[!i]);
					tanks[!i]->DrawHealthBar(tanks[!i]);
					Delay(1);
					HidePanel(gamePanel);
					DisplayPanel(gameOverPanel);
					if(i==0)
						SetCtrlVal (gameOverPanel, GameOver_Tank_Won_String, "Right Tank won!");
					else
						SetCtrlVal (gameOverPanel, GameOver_Tank_Won_String, "Left Tank won!");
					break;
						
					
				}
				else
					DrawAllScene();
			
			}
		  		 
		}
		
}
static void CheckCollisionForProjectileAndGround(PROJECTILE* projectile)
{
	if(projectile->position->x < 0 || projectile->position->x > 1900)
		velocityX = -velocityX ;
	else	
	if(projectile->position->y > 500 )
	{
		SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
		SaveStateOfProjectile(projectile);
		CmtScheduleThreadPoolFunction (MY_THREAD_POOL, AnimateExplosion, NULL, &AnimationID);
		projectile->position->y = 1090;
		SetCtrlAttribute (gamePanel, Game_Panel_TIMER, ATTR_ENABLED, 0);
		DrawAllScene();

	}
	else if (projectile->position->y < 0)
		velocityY = -velocityY ;
	
	
}

static int poinInTriangle(PROJECTILE* projectile)
{
	//This is some linear algebra voodoo  . If you want munderstand what the hell is this  here link https://www.youtube.com/watch?v=HYAgJN3x4GA .
	double s1 = C_Y - A_Y ;
	double s2 = C_X-A_X;
	double s3 = B_Y - A_Y;
	double s4 = projectile->position->y - A_Y;
	double w1 = (A_X*s1+s4*s2-projectile->position->x*s1)/(s3*s2-(B_X-A_X)*s1);
	double w2 = (s4-w1*s3)/s1;
	if (w1 >=0 && w2>=0 && (w1+w2)<=1)
	{
		return 1;
	}
	else
		return 0;
}
static void SaveStateOfProjectile(PROJECTILE* projectile)
{
	ghostProjectiile = new_PROJECTILE(new_POSITION(projectile->position->x,projectile->position->y));
}