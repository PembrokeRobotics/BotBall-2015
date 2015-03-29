// Created on Fri March 6 2015

// Replace FILE with your file's name
#ifndef _CREATE_MOVEMENT_H_
#define _CREATE_MOVEMENT_H_

#ifdef __cplusplus
extern "C"{
#endif

void rotateLeftDegrees(double degrees, int speed);
void rotateRightDegrees(double degrees, int speed);
void create_drive_distance(int speed, int distance);
#ifdef __cplusplus
}
#endif

#endif
