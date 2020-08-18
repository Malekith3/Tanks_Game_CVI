#ifndef Tank_Object_h
#define Tank_Object_h

//------------------------------Objects definition------------------------------------------//
typedef struct position												//includes position in cartesian coordinates
{
	double x;														//X coordinate
	double y;														//Y coordinate
	
}POSITION;

typedef struct tank													//defines a Tank object
{
	POSITION* position;												//position of the tank in cartesian coordinates
	double angle;													//initial angle for the missle
	int health;														//the health of the tank(will be scaled from 0-100)
	int* image;														//pointer which contains the path of the .png image of the tank
	void (*Move_PosX)(struct tank* self);							//pointer to function(which will function as a method implemented in oop)
	void (*Move_NegX)(struct tank* self);
	void (*UpperBarrel)(struct tank* self);	
	void (*LowerBarrel)(struct tank* self);
	void (*Draw_Tank)(struct tank* self);
	void (*BeenHit)(struct tank* self);
	void (*DrawHealthBar)(struct tank* self);
}TANK;
//-------------------------------------------------------------------------------------------//

//--------------------External variables-------------------------------------------------------//
extern int gamePanel;


//----------------------------Functions declaration------------------------------------------//

POSITION* new_POSITION(double x,double y);							//POSITION constructor
TANK* new_TANK(POSITION* position,double angle,int health,int* image);			//TANK constructor
void Move_PosX(TANK* tank); 										// Move tank forward
void Move_NegX(TANK* tank);  										// Move tank backward 
void LowerBarrel(TANK* tank); 										// Lower angle of barrel 
void UpperBarrel(TANK* tank); 										// Increase angle of barrel
void Draw_Tank(TANK* tank); 										// Draw tank on canvas
void BeenHit(TANK* tank);
void DrawHealthBar(TANK* tank);
int* new_Image(char* path); 										// It's a constructor for image pointer 
#endif 
//-------------------------------End of File-----------------------------------------------//
