/*
 *  File name : trajectoryClient.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Apr 17, 2017 @ 2:40:55 AM
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
#include<ros/ros.h>
#include<hector_nav_msgs/GetRobotTrajectory.h>
#include<hector_nav_msgs/GetDistanceToObstacle.h>
#include<geometry_msgs/Pose.h>
#include<nav_msgs/Path.h>
int i=0;int j=0;
int main(int argc,char **argv)
{
	ros::init(argc,argv,"trajectory_client");
	ros::NodeHandle nh;
	ros::ServiceClient trajClient = nh.serviceClient<hector_nav_msgs::GetRobotTrajectory>("trajectory",true);
	hector_nav_msgs::GetRobotTrajectory::Request req;
	hector_nav_msgs::GetRobotTrajectory::Response resp;
	bool success=trajClient.call(req,resp);
	float zpos;
	int tm=ros::Time::now().toSec();
	while(j==0)
	{
		if(tm !=resp.trajectory.poses[i].header.stamp.sec)
		{
			i++;
			ROS_INFO_STREAM("i = "<<i);
		}
		else
		{
			j=1;
		}
	}
	for(j=i;j>0;j++)
	{
		bool success=trajClient.call(req,resp);
		zpos=resp.trajectory.poses[j].pose.position.z;
		ROS_INFO_STREAM("Success! z= "<<zpos);
		ROS_INFO_STREAM("Success! ROS time= "<<tm);
		ROS_INFO_STREAM("i = "<<i);
		ros::Duration(0.25).sleep(); // time comes from update rate in server update rate definition.
		tm=ros::Time::now().toSec();
		i++;
	}
	//ros::spin();
}
