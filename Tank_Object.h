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
	int* image;														//pointer which contains the path of the .png image of the tank
	void* (*MoveForward)(struct tank* self);						//pointer to function(which will function as a method implemented in oop)
	void* (*Reverse)(struct tank* self);
	void* (*UpperBarrel)(struct tank* self);	
	void* (*LowerBarrel)(struct tank* self);
	void* (*Draw)(struct tank* self);
}TANK;
//-------------------------------------------------------------------------------------------//

//----------------------------Functions declaration------------------------------------------//

POSITION* new_POSITION(double x,double y);							//POSITION constructor
TANK* new_TANK(POSITION* position,double angle,int* image);			//TANK constructor
void MoveForward(TANK* tank); 										// Move tank forward
void Reverse(TANK* tank);  											// Move tank backward 
void LowerBarrel(TANK* tank); 										// Lower angle of barrel 
void UpperBarrel(TANK* tank); 										// Increase angle of barrel
void Draw(TANK* tank); 												// Draw tank on canvas
int* new_Image(char* path); 										// Its constructor for image pointer 
#endif 
//-------------------------------End of File-----------------------------------------------//

