// Created on Fri March 6 2015
#include "smallBot_camera.h"
#include "config.h"
#include <stdlib.h>
#include <math.h>
int getNumVisiblePingPongBalls(void)
{
	//camera_open();
	camera_update();
	int count = get_object_count(PING_PONG_BALL_CHANNEL_RED);
	//camera_close();
	return count;
	
}

Coordinate getCoordinateOfPingPongBall(int PingPongBallNumber)
{
	//camera_open();
	Coordinate cood = *((Coordinate*)malloc(sizeof(Coordinate)));
	camera_update();
	msleep(100);
	cood.x = get_object_center_x(PING_PONG_BALL_CHANNEL,PingPongBallNumber);
	cood.y = get_object_center_y(PING_PONG_BALL_CHANNEL,PingPongBallNumber);
	//camera_close();
	return cood;
}

Coordinate* getAllPingPongCoordinates(int* placeToStoreLength)
{
	int numberOfObjects = getNumVisiblePingPongBalls();
	Coordinate* returnArray = (Coordinate*)malloc(numberOfObjects*sizeof(Coordinate));
	int i = 0;
	for(i;i<numberOfObjects; i++)
	{
		returnArray[i] = getCoordinateOfPingPongBall(i);
	}
	*placeToStoreLength = numberOfObjects;
	return returnArray;
}

