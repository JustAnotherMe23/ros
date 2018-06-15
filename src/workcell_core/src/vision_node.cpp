#include <ros/ros.h>
#include <fake_ar_publisher/ARMarker.h>

class Localizer 
{
public:
	Localizer(ros::NodeHandle& nh) 
	{
		ar_sub_ = nh.subscribe<fake_ar_publisher::ARMarker>("ar_pose_marker", 1, &Localizer::vision_callback, this);
	}

	void vision_callback(const fake_ar_publisher::ARMarkerConstPtr& msg)
	{
		last_msg_ = msg;
		ROS_INFO_STREAM(last_msg_->pose.pose);
	}

	ros::Subscriber ar_sub_;
	fake_ar_publisher::ARMarkerConstPtr last_msg_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "vision_node");
	ros::NodeHandle nh;
	Localizer localizer(nh);
	ROS_INFO_STREAM("Vision node starting");
	ros::spin();
	return 0;
}