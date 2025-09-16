#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo
{
private:
    std::string maximum_payload_;

public:
    void setMaximumPayload(const std::string& payload) { maximum_payload_ = payload; }

    void publish_data() override
    {
        msg_.data_field_01 = "robot_description: " + robot_description_;
        msg_.data_field_02 = "serial_number: " + serial_number_;
        msg_.data_field_03 = "ip_address: " + ip_address_;
        msg_.data_field_04 = "firmware_version: " + firmware_version_;
        msg_.data_field_05 = "maximum_payload: " + maximum_payload_;

        pub_.publish(msg_);
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "agv_robot_info_node");

    AGVRobotInfo agv;
    agv.setRobotDescription("Cooper100");
    agv.setSerialNumber("567A359");
    agv.setIpAddress("169.254.5.180");
    agv.setFirmwareVersion("3.5.8");
    agv.setMaximumPayload("100 Kg");

    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        agv.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
