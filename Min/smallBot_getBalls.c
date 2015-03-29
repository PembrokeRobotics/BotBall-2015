#include "smallBot_getBalls.h"
// Created on Sat March 21 2015
#include "smallBot_movement.h"
#include "smallBot_trapper.h"
#include "debug.h"
#include "smallBot_camera.h"
#include <stdbool.h>
#include "Coordinate.h"
void getBalls(void)
{

    openTrapper();


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
                msleep(200);
                
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
                msleep(250);
            } else if (d.x <= 59) {
                smallBot_turnLeft(power*1.2);
            } else if (d.x >= 99) {
                smallBot_turnRight(power*1.2);
            }
        }
        /*if(analog(3)>600)
            {
                closeTrapper();
            }sateOfPingPongBall(0);
        msleep(200);

        /*
    if(d.x  > 69 && d.x < 89)

    {
        int counter = 0;
        while(!(done)){
            smallBot_driveForwards(50);
            msleep(100);
            //smallBot_turnLeft(5);
            //msleep(10);
            d= getCoordinateOfPingPongBall(0);
            if(!(d.x>0 && d.x<160)){counter++;}
            else{counter=0;}
            if(counter>10){done=true;}
            if(d.y>140){msleep(300);done=true;}
        }

    }
    else
    {
        smallBot_turnLeft(5);
        msleep(100);
    }
            d= getCoordinateOfPingPongBall(0);
        ao(); */
}

    closeTrapper();

}
