#include "ros/ros.h"
#include "Assignment/LocationCheck.h"

#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Location_Check_service_client_node");

  ros::NodeHandle node_handle;

  ros::ServiceClient client = node_handle.serviceClient<Assignment::LocationCheck>("Location_Check");

  Assignment::LocationCheck Location_Check_srv;

  int input_num;

  std::cout << "Type '0123' if you want to quit" << std::endl;

  while (ros::ok())
  {
    std::cout << "Enter a number: ";
    std::cin >> input_num
    

    if (input_num < 10)
    {
      ROS_INFO("Sending the location...");
      return 0;
    }

    if (client.call(Location_Check_srv))
    {
      std::string resp;
      resp = Location_Check_srv.response.answer;

      std::cout << "Location is ... " << resp << std::endl;
    }
    else
    {
      ROS_ERROR("Service Call Failed");
      return 1;
    }

    std::cin.clear();


  }
}
