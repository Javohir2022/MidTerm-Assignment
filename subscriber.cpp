#include "ros/ros.h"

#include "std_msgs/String.h"

void subcallback(const std_msgs::StringConstPtr& msg)
{
  std::string msg_str = msg->data;
  
  ROS_INFO("%s", msg_str.c();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ROS_Smart_Mobility");

  ros::NodeHandle node_handle;
  
  ros::Subscriber ROS_Smart_Mobility_sub = node_handle.subscribe("ROS_Smart_Mobility", 10, subCallback);
  
  ros::spin();
  
  return 0;
}
