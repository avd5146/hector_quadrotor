/*
 *  File name : 2dnav.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Mar 11, 2017 @ 12:02:26 PM
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
#include <std_msgs/String.h>
#include <sensor_msgs/PointCloud.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <hector_uav_msgs/Altimeter.h>

void PointCloudReceived(const sensor_msgs::PointCloud::ConstPtr& pc)
{
	float pointCloud[50][50][50]={};
//	pointCloud=pc->points;
	ROS_INFO_STREAM("Point cloud "<<pc);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "alt_comm");
	ros::NodeHandle nh;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
	ros::Subscriber sub=nh.subscribe("scan_cloud", 1000, &PointCloudReceived);
	ros::spin();
}
