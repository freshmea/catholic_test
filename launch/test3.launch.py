from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.substitutions import LaunchConfiguration, PythonExpression
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
  param_dir = LaunchConfiguration(
      'param_dir',
      default=os.path.join(
          get_package_share_directory('my_package'),
          'param',
          'turtlesim.yaml'))
  return LaunchDescription([
    DeclareLaunchArgument(
      'param_dir',
      default_value=param_dir,
    ),
    Node(
      package='turtlesim',
      executable='turtlesim_node',
      parameters=[param_dir]
    ),
		Node(
    package='my_package',
    executable='moveturtle2',
    ),
    ExecuteProcess(
        cmd=[[
            'ros2 service call ',
            '/spawn ',
            'turtlesim/srv/Spawn ',
            '"{x: 2, y: 2, theta: 0.2, name: ''turtle2''}"'
        ]],
        shell=True)
	]
  )
