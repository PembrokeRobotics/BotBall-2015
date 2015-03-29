#include "create_movement.h"
void rotateLeftDegrees(double degrees, int speed)
{
	//speed in mm/s
	do{create_drive_direct(-speed,speed);
	}while(get_create_total_angle()<degrees-1);
	create_stop();
	set_create_total_angle(0);
	
	
}
void rotateRightDegrees(double degrees, int speed)
{
	rotateLeftDegrees(degrees,-speed);	
}
void create_drive_distance(int speed, int distance){
	int end;
	if(speed<0 && distance>0) distance*=-1;
	if(speed>0 && distance<0) speed*=-1;
	end=get_create_distance(0)+distance;
	create_drive_straight(speed);
	if(distance>0) while(get_create_distance(0)<end) msleep(10);
	if(distance<0) while(get_create_distance(0)>end) msleep(10);
	create_stop();
}
