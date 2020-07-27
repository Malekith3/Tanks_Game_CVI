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
	POSITION position;												//position of the tank in cartesian coordinates
	double angle;													//initial angle for the missle
	char* image;													//pointer which contains the path of the .png image of the tank
	void* (*MoveForward)(struct tank* self);						//pointer to function(which will function as a method implemented in oop)
	void* (*Reverse)(struct tank* self);
	void* (*UpperBarrel)(struct tank* self);	
	void* (*LowerBarrel)(struct tank* self);
	void* (*Draw)(struct tank* self);
}TANK;
//-------------------------------------------------------------------------------------------//

//----------------------------Functions declaration------------------------------------------//

POSITION* new_POSITION(double x,double y);							//POSITION constructor
TANK* new_TANK(POSITION position,double angle,char* image);			//TANK constructor
#endif 
//-------------------------------End of File-----------------------------------------------//

