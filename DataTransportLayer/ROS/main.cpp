// rosserial_hello_world.cpp : Example of sending command velocities from Windows using rosserial
//

#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <windows.h>

using std::string;

int main(int argc, char* argv[])
{
	ros::NodeHandle nh;
	const char* ros_master = "192.168.2.225";
	int a = 0;

	printf("Connecting to server at %s\n", ros_master);
	nh.initNode((char *)ros_master);

	printf("Advertising cmd_vel message\n");
	geometry_msgs::Twist twist_msg;
	ros::Publisher cmd_vel_pub("cmd_vel", &twist_msg);
	nh.advertise(cmd_vel_pub);

	printf("Go robot go!\n");
	while (1)
	{
		twist_msg.linear.x = a++;
		twist_msg.linear.y = 0;
		twist_msg.linear.z = 0;
		twist_msg.angular.x = 0;
		twist_msg.angular.y = 0;
		twist_msg.angular.z = -1.8;
		cmd_vel_pub.publish(&twist_msg);

		nh.spinOnce();
		Sleep(100);
	}

	printf("All done!\n");
	return 0;
}