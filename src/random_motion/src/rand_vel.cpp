#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Range.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	ros::init(argc, argv, "Send_comm"); // send commanded velocity
	ros::NodeHandle nh;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 10000); // send to topic /cmd_vel
	ros::Rate rate(5);
	geometry_msgs::Twist velz;// velz is the velocity in z-direction
	float count=0; //count. Note: ROS time could be used
	while(ros::ok())
	{
		if(count<5)
		{
			velz.linear.z=.2;
			count=count+0.1;
			ROS_INFO_STREAM("Going up "<<count);
		}
		else if(count>=5 && count<10)
				{
					velz.linear.z=0;
					count=count+0.1;
					ROS_INFO_STREAM("Hold "<<count);
				}
		else if(count>=10 && count<15)
				{
					velz.linear.z=-0.1;
					count=count+0.1;
					ROS_INFO_STREAM("Descending "<<count);
				}
		else
				{
					velz.linear.z=0;
					count=count+0.1;
					ROS_INFO_STREAM("Hovering "<<count);
				}

	pub.publish(velz); // publish the values to topic
		rate.sleep();
}
}
