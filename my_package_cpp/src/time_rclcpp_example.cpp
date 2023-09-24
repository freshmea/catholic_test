#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time_source.hpp"

#include "std_msgs/msg/header.hpp"

using namespace std::chrono_literals;

class TimePub : public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr time_publisher_;

    void pub_time_msg()
    {
        static rclcpp::Time past = this->now();
        rclcpp::Time now = this->now();
        auto msg = std_msgs::msg::Header();
        RCLCPP_INFO(this->get_logger(), "sec %lf nsec %ld", now.seconds(), now.nanoseconds());
        msg.stamp = this->now();
        time_publisher_->publish(msg);
    }
    
public:
    TimePub()
    : Node("TimePub")
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        time_publisher_ = this->create_publisher<std_msgs::msg::Header>("timepub", qos_profile);
        timer_ = this->create_wall_timer(1s, std::bind(&TimePub::pub_time_msg, this));
    }

};



int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TimePub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}