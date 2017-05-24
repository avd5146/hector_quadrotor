/*
 *  File name : rand_nav.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Mar 12, 2017 @ 12:05:14 AM
 *
 *
 *  Copyright (C) 2017 by AVD Corp. DO NOT MISUSE.
 * 
 * 
 * Description: Description about the file goes 
 *				here.
 * 		  Note: Any special instructions for
 *				using the file goes here.
 */
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <hector_uav_msgs/Altimeter.h>
geometry_msgs::Twist vel;
void Callback(const hector_uav_msgs::Altimeter::ConstPtr& h)
{
	ros::NodeHandle nh;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",1000);
	vel.linear.x=0.3;
	vel.linear.y=0.3;
	vel.linear.z=0.3;
	vel.angular.x=0.3;
	vel.angular.y=0.3;
	vel.angular.z=0.3;
	if (h->altitude>2.5)
	{
		vel.linear.x=0;
		vel.linear.y=0;
		vel.linear.z=0;
		vel.angular.x=0;
		vel.angular.y=0;
		vel.angular.z=0;
	}
	pub.publish(vel);
}

int main(int argc,char **argv)
{
	ros::init(argc, argv, "Send_command");
	ros::NodeHandle nh;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",1000);
	ros::Subscriber sub=nh.subscribe("altimeter",1000,&Callback);
	ros::spin();
}
