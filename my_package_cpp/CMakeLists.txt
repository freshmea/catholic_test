cmake_minimum_required(VERSION 3.5)
project(my_package_cpp)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(my_interface REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(include)

#build
add_executable(argument src/arithmetic/argument.cpp)
ament_target_dependencies(argument my_interface rclcpp)

add_executable(time_test src/time_rclcpp_example.cpp)
ament_target_dependencies(time_test rclcpp std_msgs)

add_executable(hellow_pub src/helloworld_publisher.cpp)
ament_target_dependencies(hellow_pub rclcpp std_msgs)

add_executable(hellow_sub src/helloworld_subscriber.cpp)
ament_target_dependencies(hellow_sub rclcpp std_msgs)

add_executable(move_turtle src/move_turtle.cpp)
ament_target_dependencies(move_turtle rclcpp geometry_msgs)

add_executable(calculator src/calculator/calculator.cpp)
ament_target_dependencies(calculator rclcpp my_interface)

#install
install(TARGETS 
  argument
  calculator
  time_test
  hellow_pub
  hellow_sub
  move_turtle
  DESTINATION lib/${PROJECT_NAME})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
