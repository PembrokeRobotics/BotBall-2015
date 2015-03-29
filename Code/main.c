
#include "create_movement.h"
int main()
{

	wait_for_light(0);
	shut_down_in(119); // shut off the motors and stop the Create after 119 seconds
	printf("hello...");
	create_connect();
	printf("hello...");
	enable_servos();
	printf("hello...");
	//top = 109
	//bottom = 1800
	set_create_total_angle(0);
	set_create_distance(0);
	int x = 0;

	create_full();
	// {{
	rotateRight();
	//Extend servo 
	set_servo_position(3, 1800);
	// }}
	create_drive_direct(0,0);
	//Drive to plank
	create_drive_direct(-300,-300);
	msleep(2000);

	create_drive_direct(50,-50);
	msleep(2300);

	create_drive_direct(-50,50);
	msleep(2300);
	create_drive_direct(0,0);

	rotateRight();

	x = 3;
	while(x>0){
		printf("PARTY HARD!!!111!1");
	create_drive_direct(300,300);
	msleep(1000);
	create_drive_direct(-300,-300);
	msleep(3000);
	create_drive_direct(0,0);
	msleep(5000);
	x--;
	}	

	rotateLeft();

	set_servo_position(3, 109);
	msleep(1000);

	//Drive to other side
	create_drive_direct(-300,-300);
	msleep(2000);


	rotateRight();


	x = 3;
	while(x>0){
		printf("PARTY HARD!!!111!1");
	create_drive_direct(300,300);
	msleep(1000);
	create_drive_direct(-300,-300);
	msleep(3000);
	create_drive_direct(0,0);
	msleep(5000);
	x--;
	}	


	/*
	while(get_create_distance()<999)
	{
		printf("moving forward\n");
	}	*/
	//msleep(1000);
	/*
	create_drive_direct(-100,100);
	while(get_create_total_angle()<89)
	{
		printf("rotating\n");
	}
	*/
	disable_servos();
	create_stop();
	create_disconnect();
	return 0;
}
