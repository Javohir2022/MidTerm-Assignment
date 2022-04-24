#include "ros/ros.h"
#include "MidTerm-Assignment/WeatherStatus.h"

bool endbackWeatherstatus(MidTerm-Assignment::WeatherStatus::Request &req,
                      MidTerm-Assignment::WeatherStatus::Response &res)
{
  int weather_status = req.number % 4;

  if(weather_status == 0)
  {
    res.answer = "cloudy";
  }
  else if (weather_status == 2)
  {
    res.answer = "sunny";
  }
  else
  {
    return false;
  }

  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "weather_status_service_server_node");

  ros::NodeHandle node_handle;

  ros::ServiceServer service = node_handle.advertiseService("weather_status_check", sendbackWeatherstatus);

  ROS_INFO("Weather Status Server is Running...");

  ros::spin();

  return 0;
}
