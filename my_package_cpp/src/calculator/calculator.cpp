#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "my_interface/msg/arithmetic_argument.hpp"
#include "calculator/calculator.hpp"

Calculator::Calculator(const rclcpp::NodeOptions & node_options)
: Node("calculator", node_options), argument_a_(0.0), argument_b_(0.0), argument_operator_(0), argument_result_(0.0), argument_formula_("")
{
    RCLCPP_INFO(get_logger(), "Run Calculator");

    operator_.reserve(4);
    operator_.push_back("+");
    operator_.push_back("-");
    operator_.push_back("*");
    operator_.push_back("/");
    
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
    auto get_arithmetic_operator = [this](const std::shared_ptr<ArithmeticOperator::Request> request,
    std::shared_ptr<ArithmeticOperator::Response> response) -> void
    {
        argument_operator_ = request->arithmetic_operator;
        argument_result_ = this->calculate_given_formula(argument_a_, argument_b_, argument_operator_);
        response->arithmetic_result = argument_result_;

        std::ostringstream oss;
        oss << std::to_string(argument_a_) << ' ' << operator_[argument_operator_-1] << ' ' <<
        std::to_string(argument_b_)<< " = " << argument_result_ << std::endl;
        argument_formula_ = oss.str();

        RCLCPP_INFO(this->get_logger(), "%s", argument_formula_.c_str());
    };

    arithmetic_argument_server_ = this->create_service<ArithmeticOperator>("arithmetic_operator", get_arithmetic_operator);
}

Calculator::~Calculator(){}

float Calculator::calculate_given_formula(const float & a, const float & b, const int8_t & operators)
{
    float argument_result = 0.0;
    ArithmeticOperator::Request arithmetic_operator;

    if (operators == arithmetic_operator.PLUS){
        argument_result = a + b;
    } else if (operators == arithmetic_operator.MINUS){
        argument_result = a - b;
    } else if (operators == arithmetic_operator.MULTIPLY){
        argument_result = a * b;
    } else if (operators == arithmetic_operator.DIVISION){
        argument_result = a / b;
        if (b == 0.0){
            RCLCPP_INFO(this->get_logger(), "ZeroDivisionError!");
            argument_result = 0.0;
            return argument_result;
        }
    } else {
        RCLCPP_INFO(this->get_logger(), "Please make sure arithmetic operator.");
        argument_result = 0.0;
    }
    return argument_result;
}


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Calculator>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}