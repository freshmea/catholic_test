#include "rclcpp/rclcpp.hpp"
#include "arithmetic/operator.hpp"

#include "rcutils/cmdline_parser.h"

using namespace std::chrono_literals;

Operator::Operator(const rclcpp::NodeOptions & node_options)
: Node("operator", node_options)
{
    arithmetic_service_client_ = create_client<ArithmeticOperator>("arithmetic_operator");
    while(!arithmetic_service_client_->wait_for_service(1s)){
        if(!rclcpp::ok()){
            RCLCPP_INFO(get_logger(), "Interrupted while waiting for the service.");
            return;
        }
        RCLCPP_INFO(get_logger(), "Service not available, waiting again...");
        
    }
}

Operator::~Operator(){}

void Operator::send_request()
{
    auto request = std::make_shared<ArithmeticOperator::Request>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1,4);
    request->arithmetic_operator = distribution(gen);

    using ServiceResponseFuture = rclcpp::Client<ArithmeticOperator>::SharedFuture;
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto response = future.get();
        RCLCPP_INFO(get_logger(), "Result %.2f", response->arithmetic_result);
        return;
    };
    auto future_result = arithmetic_service_client_->async_send_request(request, response_received_callback);
}

void print_help(){}
bool pull_trigger(){
    return true;
}


int main(int argc, char * argv[])
{
  if (rcutils_cli_option_exist(argv, argv + argc, "-h")) {
    print_help();
    return 0;
  }
  rclcpp::init(argc, argv);
  auto operator_node = std::make_shared<Operator>();

  while (rclcpp::ok()) {
    rclcpp::spin_some(operator_node);
    operator_node->send_request();

    printf("Press Enter for next service call.\n");
    if (pull_trigger() == false) {
      rclcpp::shutdown();
      return 0;
    }
  }
}