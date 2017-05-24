/*
 *  File name : tf_listener.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: May 19, 2017 @ 6:04:09 AM
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
			listener.waitForTransform("/map", "/base_link", ros::Time::now(), ros::Duration(1.0) ); // TODO try the code without this.
			listener.lookupTransform("/map", "/base_link", ros::Time(0), transform); // TODO try time::now
		}
		catch(tf::TransformException &ex)
		{
			ROS_ERROR("%s", ex.what());
			ros::Duration(1).sleep();
			continue;
		}
		ROS_INFO("z = %f",transform.getOrigin().z());
	}
	ros::spin();
	return 0;
}
