#ifndef CALCULATOR__CALCULATOR_HPP_
#define CALCULATOR__CALCULATOR_HPP_

#include <memory>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "my_interface/msg/arithmetic_argument.hpp"
#include "my_interface/srv/arithmetic_operator.hpp"
#include "my_interface/action/arithmetic_checker.hpp"

class Calculator : public rclcpp::Node
{
public:
    using ArithmeticArgument = my_interface::msg::ArithmeticArgument;
    using ArithmeticOperator = my_interface::srv::ArithmeticOperator;
    explicit Calculator(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions());
    virtual ~Calculator();
    float calculate_given_formula(const float & a, const float & b, const int8_t & operators);

private:
    rclcpp::Subscription<ArithmeticArgument>::SharedPtr arithmetic_argument_subscriber_;
    rclcpp::Service<ArithmeticOperator>::SharedPtr arithmetic_argument_server_;
    float argument_a_;
    float argument_b_;
    int8_t argument_operator_;
    float argument_result_;
    std::string argument_formula_;
    std::vector<std::string> operator_;

};



#endif