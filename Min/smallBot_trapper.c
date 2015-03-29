#include "config.h"
#include "smallBot_trapper.h"
void openTrapper(void)
{
    enable_servos();
    set_servo_position(TRAPPER_PORT, TRAPPER_OPEN_SERVO_POSITION);
    msleep(TIME_REQUIRED_TO_CHANGE_TRAPPER_POSITION);
    disable_servos();

}
void closeTrapper(void)
{
    enable_servos();
    set_servo_position(TRAPPER_PORT, TRAPPER_CLOSED_SERVO_POSITION);
    msleep(TIME_REQUIRED_TO_CHANGE_TRAPPER_POSITION);
    disable_servos();

}
