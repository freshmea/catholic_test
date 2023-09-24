#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class HelloworldPublisher : public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle_publisher_;
    size_t count_;
    void publish_helloworld_msg()
    {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = 1.0;
        msg.angular.z = 0.4;
        turtle_publisher_->publish(msg);
    }

public:
    HelloworldPublisher()
    : Node("Helloworld_publisher"), count_(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        turtle_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
            "turtle1/cmd_vel", qos_profile);
        timer_ = this->create_wall_timer(
            0.1s, std::bind(&HelloworldPublisher::publish_helloworld_msg, this));
    }

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HelloworldPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}