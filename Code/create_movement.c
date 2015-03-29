#include "create_movement.h"
void rotateLeft(void)
{
		//Turn 90 degrees 
	create_drive_direct(-100,100);
	msleep(2100);
}
void rotateRight(void)
{
		//Turn 90 degrees 
	create_drive_direct(100,-100);
	msleep(2100);
}