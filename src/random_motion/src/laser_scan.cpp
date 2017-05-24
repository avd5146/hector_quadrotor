/*
 *  File name : laser_scan.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: May 22, 2017 @ 7:51:00 PM
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
#include <sensor_msgs/LaserScan.h>

void getScan(const sensor_msgs::LaserScan scanData)
{
	float angle_min=scanData.angle_min;
//	ROS_INFO("Angle minimum = %f",angle_min);
	float angle_max=scanData.angle_max;
	float dalp=scanData.angle_increment;
	float rmin=scanData.range_min;
	float rmax=scanData.range_max;
	int iter2=0;
	float rangeData[10000];	// FIXME try undefined array size
	for(float iter1=angle_min;iter1<=angle_max;iter1=iter1+dalp)
	{
		rangeData[iter2]=scanData.ranges[iter2];
		if(rangeData[iter2]<rmin || rangeData[iter2]>rmax)
		{
			rangeData[iter2]=-1;
		}
		iter2++;
	}
	for(int ct=0;ct<iter2-1;ct++)
	{
		ROS_INFO("Range is %f",rangeData[ct]);
	}
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "laser_scanner");
	ros::NodeHandle nh;
	ros::Subscriber sub=nh.subscribe("/scan",50,getScan);
	ros::spin();
}
