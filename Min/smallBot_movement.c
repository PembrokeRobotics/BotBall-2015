#include "smallBot_movement.h"
#include "config.h"
void smallBot_driveForwardForTime(float time, int power)
{
	//Time is multiples of 10
	do
	{
		msleep(10);
		motorm(LEFT_WHEEL_PORT,power);
		motorm(RIGHT_WHEEL_PORT,power);
		time-=10;
	}while(time>10);
	smallBot_HALT();
}
void smallBot_driveBackwardsForTime(float time, int power)
{
	smallBot_driveForwardForTime(time,-1*power);
}
void motorm(int port, int power)
{
	if(port == LEFT_WHEEL_PORT) 
	{
		motor(port,power*SKEW_MOVEMENT_ADJUSTER);
	} 
	else 
	{
		motor(port, power);
	}
}

void smallBot_turnLeftForTime(float time, int power)
{
	do
	{
		msleep(10);
		motorm(LEFT_WHEEL_PORT,-1 * power);
		motorm(RIGHT_WHEEL_PORT,power);
		time-=10;
	}while(time>10);
	smallBot_HALT();
}
void smallBot_turnRightForTime(float time, int power)
{
	smallBot_turnLeftForTime(time, -1* power);
}
//These drive functions DO NOT cancel themselves
//Please call smallBot_HALT to stop the robit
void smallBot_driveBackwards(int power)
{	
	smallBot_HALT();
	motorm(LEFT_WHEEL_PORT,-1*power);
	motorm(RIGHT_WHEEL_PORT,-1*power);
}
void smallBot_driveForwards(int power)
{
	smallBot_HALT();
	motorm(LEFT_WHEEL_PORT,power);
	motorm(RIGHT_WHEEL_PORT,power);
}
void smallBot_turnLeft(int power)
{
	smallBot_HALT();
	motorm(LEFT_WHEEL_PORT,-1*power);
	motorm(RIGHT_WHEEL_PORT,power);
}
void smallBot_turnRight(int power)
{
	smallBot_HALT();
	motorm(LEFT_WHEEL_PORT,power);
	motorm(RIGHT_WHEEL_PORT,-1*power);
}
void smallBot_HALT(void)
{
	ao();
	//motorm(LEFT_WHEEL_PORT,0);
	//motorm(RIGHT_WHEEL_PORT,0);
	//msleep(50);
}
