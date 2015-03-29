// Created on Sat March 21 2015
#include "smallBot_movement.h"
#include "smallBot_trapper.h"
#include "debug.h"
#include "smallBot_camera.h"
#include <stdbool.h>
#include "Coordinate.h"
int main()
{
	camera_open();
	// initialize servo, camera, etc here?.
	// if you are using a Create you should uncomment the next line
	//create_connect();

	wait_for_light(0); // change the port number to match where your robot

	shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	// note that shut_down_in should immediately follow wait_for_light!!
	openTrapper();
	smallBot_driveForwards(100);
	msleep(200);
	smallBot_HALT();
	printf("hello dave\n");
	int x = getNumVisiblePingPongBalls();
	Coordinate d =getCoordinateOfPingPongBall(0);
	printf("%d cood x:%d y:%d\n",x,d.x,d.y);
	bool done = false;
	int counter = 0;
	bool haddetection = false;
	int power = 20;
	while(!(done)){
		printf("x: %d\n",d.x);

		if(d.x == -1 || d.y > 100) {
			if(haddetection){
				closeTrapper();
				smallBot_driveForwards(100);
				msleep(3000);
				openTrapper();
				smallBot_driveBackwards(100);
				msleep(3000);
				smallBot_turnRight(100);
				msleep(700);
			}
			haddetection=false;
			smallBot_turnRight(5);
			msleep(50);
		}
		else
		{
			haddetection = true;
			openTrapper();
			if(d.x > 59 && d.x < 99) {
				smallBot_driveForwards(power*4);
				msleep(500);
			} else if (d.x <= 59) {
				smallBot_turnLeft(power*1.2);
			} else if (d.x >= 99) {
				smallBot_turnRight(power*1.2);
			}
	    }
		msleep(100);
		smallBot_HALT();
		d= getCoordinateOfPingPongBall(0);
		msleep(200);
}
	msleep(300);
	closeTrapper();
	printf("My program should score more points than this template!\n");
	// replace printf above with your code

	camera_close();
	//create_disconnect();
	return 0;
}
