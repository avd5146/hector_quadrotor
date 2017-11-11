class Publ
{
private:
	ros::NodeHandle nh;
	ros::Publisher p;
	ros::Subscriber s;
	
public:
	geometry_msgs::TwistStamped pubm;
	geometry_msgs::TwistStamped pub_msg;
	Publ();
	~Publ();
	void pub(const geometry_msgs::Twist::ConstPtr msg);
	void callback(const geometry_msgs::Twist::ConstPtr msg);
};