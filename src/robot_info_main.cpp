#include "robot_info_class.cpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "robot_info_node");

    RobotInfo robot;
    robot.setRobotDescription("GenericBot");
    robot.setSerialNumber("123456");
    robot.setIpAddress("192.168.0.10");
    robot.setFirmwareVersion("1.0.0");

    ros::Rate loop_rate(1);  // 1 Hz
    while (ros::ok())
    {
        robot.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
