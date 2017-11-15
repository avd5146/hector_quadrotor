/*
 *  File name : odom_fuse_nodelet.cpp
 *
 *      Author: Ankur Dalal
 *  Created on: Oct 22, 2017 @ 1:07:17 AM
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

int main(int argc,char **argv)
{
	ros::init(argc,argv,"odom_fusion_node");
	ros::NodeHandle nh;

	Fuse fuse;
	int rate=10;
	// nh.getParam("rate",rate);
	// fuse.test();
	fuse.start_fusion(rate);
	// Fuse::start_fusion(rate);
	
}
