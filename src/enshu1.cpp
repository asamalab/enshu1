#include "myrobot.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "myrobot");
  ros::NodeHandle n;
  ros::Rate rate(MAIN_RATE);
  MyRobot robot;
  while(ros::ok()){

// *********Edit here**********
    int ls = robot.get_ls();
    int rs = robot.get_rs();

    ROS_INFO("Left Sonar %i cm", ls);
    ROS_INFO("Right Sonar %i cm", rs);

    if (ls != 0 && ls <= 10) 
    {
      robot.move(0.0,1.0);
      robot.wait(1.0);
    }
    else if (rs != 0 && rs <= 10)
    {
      robot.move(0.0,-1.0);
      robot.wait(1.0);
    }
    else
    {
      robot.stop();
    }
// ****************************

    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}
