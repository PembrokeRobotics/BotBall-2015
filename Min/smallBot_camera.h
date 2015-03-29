#include "Coordinate.h"
#ifndef _SMALLBOT_CAMERA_H_
#define _SMALLBOT_CAMERA_H_

#ifdef __cplusplus
extern "C"{
#endif


int getNumVisiblePingPongBalls(void);
Coordinate getCoordinateOfPingPongBall(int PingPongBallNumber);
Coordinate* getClusterCenters(Coordinate* coodArray, int ArrayLength,int* placeToStoreLengthOfReturn);
Coordinate* getAllPingPongCoordinates(int* placeToStoreLength);



#ifdef __cplusplus
 }
#endif

#endif
