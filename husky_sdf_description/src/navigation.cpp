#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <sstream>
#include <ros/console.h>
#include <geometry_msgs/Twist.h>

/*
bool manipulate()
{
	std_msgs::Float64 msg;
	char c = getchar();
	switch (c) {
		case 'A':
			ROS_INFO("UP\n");
      break;
    case 'B':
			ROS_INFO("DOWN\n");
			break;
    case 'C':
			ROS_INFO("RIGHT\n");
			break;
    case 'D':
			ROS_INFO("LEFT\n");
		default:
			ROS_WARN("Tecla invalida.");
			return true;
	}
	return true;
}
*/

int main(int argc, char **argv)
{
/*
  Publisher equivalente a la instruccion introducida por terminal

	rostopic pub -1 /pioneer3at_ros/cmd_vel geometry_msgs/Twist "linear:
  x: 10.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0"
*/
	ros::init(argc, argv, "navigation");
	ros::NodeHandle n;
  ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/robot_husky/cmd_vel", 1000);

  geometry_msgs::Twist vel_msg;
  vel_msg.linear.x = 10;
	while (ros::ok())
	{
		vel_pub.publish(vel_msg);
	}

	return 0;
}
