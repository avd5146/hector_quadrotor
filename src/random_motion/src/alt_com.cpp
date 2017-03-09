#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Range.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

float height=0;	// altitude of vehicle
float height_comm=2.5;	// altitude to be held
geometry_msgs::Twist velz;
void heightReceived(const sensor_msgs::Range::ConstPtr& h) //Callback function performs when an input arrives from subscribed topic.
{
	height=h; // converting string to int
	//do
		//{
	if(h>height_comm)
			velz.linear.z=-0.1;
		//}
		//while(height<height_comm);
	
}
int main(int argc,char **argv)
{
	ros::init(argc, argv, "Send_comm");
	ros::NodeHandle nh;
	//ROS_INFO_STREAM("no error in nh");
	ros::Subscriber sub=nh.subscribe("sonar_height",1000,&heightReceived);
	//ROS_INFO_STREAM("no error in sub");
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10000);
	//ROS_INFO_STREAM("no error in sub");
	//geometry_msgs::Twist velz; //velocity
	//pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 10000);
	//sub=nh.subscribe("sonar_height",1000,&heightReceived);
	ros::spin();
}