/*
 *  File name : gripper_tf_listener.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Jun 7, 2017 @ 12:41:18 AM
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
#include <geometry_msgs/Pose.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "tf_listen");
	ros::NodeHandle nh;
	tf::TransformListener listener;
	ros::Rate rate(10);
	while(nh.ok())
	{
		tf::StampedTransform transform;
//		ros::Time last_transform=transform.stamp_; // FIXME Not working for some reason, gives 0.00 all the time
//		ROS_INFO("Last time = %f",last_transform.toSec());
		try
		{
			listener.waitForTransform("/l_gripper_r_finger_link", "/l_gripper_l_finger_link", ros::Time::now(), ros::Duration(1.0) ); // TODO try the code without this.
			listener.lookupTransform("/l_gripper_r_finger_link", "/l_gripper_l_finger_link", ros::Time(0), transform); // TODO try time::now
		}
		catch(tf::TransformException &ex)
		{
			ROS_ERROR("%s", ex.what());
			ros::Duration(1).sleep();
			continue;
		}
		if(transform.getOrigin().x()<-0.001)
		{
			ROS_INFO("Griper open with %f",transform.getOrigin().x());
		}
		else
			ROS_INFO("Gripper closed. %f",transform.getOrigin().x());
	}
	ros::spin();
	return 0;
}
