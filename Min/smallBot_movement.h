// Created on Mon March 16 2015

// Replace FILE with your file's name
#ifndef _SMALLBOT_MOVEMENT_H_
#define _SMALLBOT_MOVEMENT_H_

#ifdef __cplusplus
extern "C"
{
#endif

void motorm(int port, int power);

void smallBot_driveForwardForTime(float time, int power);
void smallBot_driveBackwardsForTime(float time, int power);
void smallBot_driveForwardsForTime(float time, int power);
void smallBot_turnLeftForTime(float time, int power);
void smallBot_turnRightForTime(float time, int power);

void smallBot_driveBackwards(int power);
void smallBot_driveForwards(int power);
void smallBot_turnLeft(int power);
void smallBot_turnRight(int power);
void smallBot_HALT(void);
#ifdef __cplusplus
}
#endif

#endif
