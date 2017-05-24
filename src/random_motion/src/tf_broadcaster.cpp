/*
 *  File name : tf_broadcaster.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: May 22, 2017 @ 2:41:42 AM
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
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "tf_broadcast");
	ros::NodeHandle nh;
	static tf::TransformBroadcaster br;
	tf::Transform transform;
}
