/*
 *  File name : obstacle_recog.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Jun 5, 2017 @ 1:47:29 AM
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


/*********************************************************************
 * Software License Agreement 
 *
 *  Copyright (c) 2017, AVD Corp.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are not permitted 
 *
 *  This software is provided by AVD Corp.
 *  Redistribution and use in source and binary forms are not permitted.
 *  Use by authorised group permitted provided that the above copyright 
 *  notice and this paragraph are duplicated in all such forms
 *  and that any documentation, advertising materials, and other
 *  materials related to such distribution and use acknowledge
 *  that the software was developed by AVD Corp.
 *  The name AVD Corp. may not be used to endorse or promote
 *  products derived from this software without specific
 *  prior written permission.
 *  All rights reserved. Ankur Dalal.
*********************************************************************/
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Int16.h>

float x,y,z,th,d;
float lethalR=3.0;
float threshold=0.1;
bool detected=false;
float rangeData[10000];
//	x=rangeData[iter2-1]*sin(angle_max);
//	y=rangeData[iter2-1]*cos(angle_max);
void obstacleDetected(float distance)
{
	x=distance;
	y=distance;
	th=0.0;
	ROS_INFO("Call success.");
	while(detected)
	{
		if(!detected)
		{
			break;
		}
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);
		tf::TransformBroadcaster odom_br;
		//first, we'll publish the transform over tf
		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp = ros::Time::now();
		odom_trans.header.frame_id = "base_link"; //parent frame
		odom_trans.child_frame_id = "obstacle";
		//	//		if(detected)
		//	//		{
		//				obstacleDetected(1);
		//	//		}
		//	//		else
		//	//			ROS_INFO("Not detected");
		//		getVal();
		ROS_INFO("R=%f",rangeData[20]);
		odom_trans.transform.translation.x = x;
		odom_trans.transform.translation.y = y;
		odom_trans.transform.translation.z = 0.0;
		odom_trans.transform.rotation = odom_quat;
		//send the transform

		odom_br.sendTransform(odom_trans);

		ROS_INFO("X=%f Y=%f th=%f",x,y,th);
		detected=false;
		x=0;y=0;th=0;
	}


//	return x,y,th;
}

void getScan(const sensor_msgs::LaserScan scanData)
{
	float angle_min=scanData.angle_min;
//	ROS_INFO("Angle minimum = %f",angle_min);
	float angle_max=scanData.angle_max;
	float dalp=scanData.angle_increment;
	float rmin=scanData.range_min;
	float rmax=scanData.range_max;
	int iter2=0;
//	float rangeData[10000];	// FIXME try undefined array size
	for(float iter1=angle_min;iter1<=angle_max;iter1=iter1+dalp)
	{
		rangeData[iter2]=scanData.ranges[iter2];
		if(rangeData[iter2]<rmin || rangeData[iter2]>rmax)
		{
			rangeData[iter2]=-1;
		}
		if(rangeData[iter2]<lethalR && rangeData[iter2]>threshold)
		{
			detected=true;
			//			d=rangeData[iter2];
			obstacleDetected(rangeData[iter2]);
			ROS_INFO("detected @ %f",rangeData[iter2]);
		}
		else
		{
			detected=false;
			x=0;y=0;th=0;
			ROS_INFO("undetected");
		}

		iter2++;
	}

//	getVal();

//	for(int ct=0;ct<iter2-1;ct++)
//	{
//
//		ROS_INFO("Range is %f",rangeData[ct]);
//	}
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "obstacle_recognition");
	ros::NodeHandle nh;
	ros::Subscriber sub=nh.subscribe("/scan",100,getScan);
//

	ros::spin();
}
