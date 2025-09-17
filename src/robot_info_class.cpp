#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>   // match the .msg file

class RobotInfo {
protected:
  ros::NodeHandle nh_;
  ros::Publisher pub_;
  robotinfo_msgs::RobotInfo10Fields msg_;      // use the correct type

  std::string robot_description_;
  std::string serial_number_;
  std::string ip_address_;
  std::string firmware_version_;

public:
  RobotInfo() {
    // Advertise publisher for our custom message
    pub_ = nh_.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
  }

  virtual ~RobotInfo() {}

  // Setters
  void setRobotDescription(const std::string &desc) {
    robot_description_ = desc;
  }
  void setSerialNumber(const std::string &sn) { serial_number_ = sn; }
  void setIpAddress(const std::string &ip) { ip_address_ = ip; }
  void setFirmwareVersion(const std::string &fw) { firmware_version_ = fw; }

  // Publish the data
  virtual void publish_data() {
    msg_.data_field_01 = "robot_description: " + robot_description_;
    msg_.data_field_02 = "serial_number: " + serial_number_;
    msg_.data_field_03 = "ip_address: " + ip_address_;
    msg_.data_field_04 = "firmware_version: " + firmware_version_;

    pub_.publish(msg_);
    ROS_INFO("Published robot info message");
  }
};
