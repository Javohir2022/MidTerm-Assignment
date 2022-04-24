

#include "ros/ros.h"

#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ROS_Smart_Mobility");
    ros::NodeHandle node_handle;
    ros::Publisher hello_world_pub = node_handle.advertise<std_msgs::String>("ROS_Smart_Mobility", 100);
    ros::Rate pub_rate(50);
    ROS_INFO("Publisher Node Started");
    int counter = 0;
    while(ros::ok())
    {
        std_msgs::String msg;
        msg.data = "ROS_Smart_Mobility " + std::to_string(counter);
        Ros_smart_mobility_pub.publish(msg);

        counter++;

        pub_rate.sleep();
    }
}S
