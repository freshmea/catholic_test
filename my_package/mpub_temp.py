import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class M_pub(Node):
  def __init__(self):
    super().__init__('mpub')


def main():
  rclpy.init()
  node = M_pub()
  pub = node.create_publisher(String, 'messagepub', 10)
  msg = String()
  msg.data = 'hello, world'
  while True:
    pub.publish(msg)
  node.destroy_node()

if __name__ == '__main__':
  main()

