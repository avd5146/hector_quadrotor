/*
 *  File name : subvel_stamp.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Sep 11, 2017 @ 8:03:26 PM
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
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>

#include <publ.h>

Publ::Publ()
{
//	s = nh.subscribe("navigation/cmd_vel",1,Publ::callback);
	s = nh.subscribe("navigation/cmd_vel",1,&Publ::pub,this); // FIXME Why does eclipse show error here?
	p = nh.advertise<geometry_msgs::TwistStamped>("/navigation/cmd_vel_stamped",100);
}
Publ::~Publ()
{

}

void Publ::callback(const geometry_msgs::Twist::ConstPtr msg)
{
	ROS_INFO("Entered cb.");

	pubm.header.stamp=ros::Time::now();
//	pub_msg.twist.angular=msg->angular;
//	pub_msg.twist.linear=msg->linear;
//	p = n.advertise<geometry_msgs::TwistStamped>("/navigation/cmd_vel_stamped",100);
//	ROS_INFO("Started publisher.");
//	p.publish(pub_msg);
	ROS_INFO("Publishing msg");
}

void Publ::pub(const geometry_msgs::Twist::ConstPtr msg)
{
	ROS_INFO("Entered cb.");

	pub_msg.header.stamp=ros::Time::now();
	pub_msg.twist.angular=msg->angular;
	pub_msg.twist.linear=msg->linear;
	p = nh.advertise<geometry_msgs::TwistStamped>("/navigation/cmd_vel_stamped",100);
	ROS_INFO("Started publisher.");
	p.publish(pub_msg);
	ROS_INFO("Publishing msg");
}

int main(int argc, char** argv)
{
//	Publ publ; // Even the position of this matters. Must be after ros::init as there are subscribers and publishers in it.
	ros::init(argc, argv, "subvel_stamp");
	ros::NodeHandle nh;
	Publ publ;
//	Publ Publ();

//	ros::Subscriber sub_vel = nh.subscribe("navigation/cmd_vel",1,pub);
//	ros::Subscriber sub_vel = nh.subscribe("navigation/cmd_vel",1,&Publ::pub,this);
	ROS_INFO("Started subscriber.");
	ros::spin();
	return 0;
}
