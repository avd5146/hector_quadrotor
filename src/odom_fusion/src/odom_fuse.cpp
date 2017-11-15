/*
 *  File name : odom_fuse.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Oct 22, 2017 @ 12:35:43 AM
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

#include "odom_fusion/odom_fuse.h"

Fuse::Fuse()
{

};

Fuse::~Fuse()
{

};

void Fuse::start_fusion(int rate){

	ROS_INFO("f_start");

	nh1.setCallbackQueue(&queue1);
	nh2.setCallbackQueue(&queue2);

	boost::shared_ptr<ros::AsyncSpinner> spinner1; // https://gist.github.com/bgromov/45ebeced9e8067d9f13cceececc00d5b
	boost::shared_ptr<ros::AsyncSpinner> spinner2;

	ros::Subscriber encoder = nh1.subscribe<geometry_msgs::Pose>("encoder_odom", 1, &Fuse::get_encoder, this); // IMP must have "this" and "&"
	ros::Subscriber zed = nh2.subscribe<geometry_msgs::Pose>("zed_odom", 1, &Fuse::get_ZED, this);

	spinner1.reset(new ros::AsyncSpinner(1, &queue1));
	spinner2.reset(new ros::AsyncSpinner(2, &queue1));

	ros::Rate loop_rate(100);

	while (ros::ok())
	{
		spinner1->start();
		spinner2->start();
		ros::spinOnce();
		loop_rate.sleep();
	}
	spinner1.reset();
	spinner2.reset();

	ROS_INFO("2_start");
}

void Fuse::get_encoder(const geometry_msgs::Pose msg){
	ROS_INFO("thread 1 - encoder");
}

void Fuse::get_ZED(const geometry_msgs::Pose msg){
	ROS_INFO("thread 2 - ZED");
}
#ifdef TESTING
void Fuse::test()
{
	ROS_INFO("Hello");
}
#endif

// int main(int argc,char **argv)
// {
// 	ros::init(argc,argv,"odom_fusion_node");
// 	ros::NodeHandle nh;
// 	ROS_INFO("main");
// 	Fuse fuse;
// 	int rate;
// 	nh.getParam("rate",rate);
// 	fuse.start_fusion(rate);
// }
