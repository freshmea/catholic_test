#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "my_interface/msg/arithmetic_argument.hpp"
class Calculator : public rclcpp::Node
{
public:
    using ArithmeticArgument = my_interface::msg::ArithmeticArgument;
    Calculator()
    : Node("calculator")
    {
        int8_t qos_depth = 10;
        auto QOS_RKL10V = rclcpp::QoS(rclcpp::KeepLast(qos_depth)).reliable().durability_volatile();
        arithmetic_argument_subscriber_ = this->create_subscription<ArithmeticArgument>(
        "arithmetic_argument", 
        QOS_RKL10V, 
        [this](const ArithmeticArgument::SharedPtr msg) -> void
        {
            argument_a_ = msg->argument_a;
            argument_b_ = msg->argument_b;
            RCLCPP_INFO(
                this->get_logger(),
                "Timestamp of the message: sec %ld nanosec %ld",
                msg->stamp.sec,
                msg->stamp.nanosec);
            RCLCPP_INFO(this->get_logger(), "Subscribed argument a: %.2f", argument_a_);
            RCLCPP_INFO(this->get_logger(), "Subscribed argument b: %.2f", argument_b_);
        });
    }
private:
    rclcpp::Subscription<ArithmeticArgument>::SharedPtr arithmetic_argument_subscriber_;
    double argument_a_;
    double argument_b_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Calculator>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}