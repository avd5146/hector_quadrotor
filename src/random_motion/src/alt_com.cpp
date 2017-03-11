#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Range.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <hector_uav_msgs/Altimeter.h>

	float height=0;	// altitude of vehicle
	float height_comm=5;	// altitude to be held
	geometry_msgs::Twist velz;

//void heightReceived(const sensor_msgs::Range::ConstPtr& h) //Callback function performs when an input arrives from subscribed topic.

void heightReceived(const hector_uav_msgs::Altimeter::ConstPtr& h)
{
	ros::NodeHandle nh;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 10000);
	pub.publish(velz);

//	height=h->range;
	height=h->altitude;
	ROS_INFO_STREAM("Current altitude: "<<height);
	velz.linear.z=1;

	if(height<height_comm)
	{
		velz.linear.z=0.2;
		ROS_INFO_STREAM("going up "<<velz.linear.z);
	}
	else
	{
	velz.linear.z=0;
	ROS_INFO_STREAM("Holding altitude steady");
	}
}
int main(int argc,char **argv)
{
	ros::init(argc, argv, "alt_comm");
	ros::NodeHandle nh;
//	ros::Subscriber sub=nh.subscribe("sonar_height",1000,&heightReceived);
//	replacing sonar with altimeter
	ros::Subscriber sub=nh.subscribe("altimeter",1000,&heightReceived);
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 10000);
	pub.publish(velz);
	ros::spin();
}

