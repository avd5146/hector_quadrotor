/*
 *  File name : odom_fuse.h
 *
 *      Author: Ankur Dalal
 *  Created on: Oct 22, 2017 @ 12:36:19 AM
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
#include <ros/callback_queue.h> // TODO: Implement me
#include <geometry_msgs/Pose.h>

class Fuse{
public:
	ros::NodeHandle nh1,nh2;
	ros::CallbackQueue queue1,queue2;
	/*
	 * Subscribe data from encoder topic.
	 */
	void get_encoder(geometry_msgs::Pose);
	/*
	 * Subscribe data from ZED topic.
	 */
	void get_ZED(const geometry_msgs::Pose);
	/*
	 * Start fusion main loop.
	 */
	void start_fusion(int);
private:
protected:

};
