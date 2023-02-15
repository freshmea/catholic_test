import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class M_pub(Node):
  def __init__(self):
    super().__init__('mpub')
    self.pub = self.create_publisher(String, 'message', 10)
    self.create_timer(1, self.pubmessage)
    self.count = 0

  def pubmessage(self):
    msg = String()
    msg.data = f'hello, world : {self.count}'
    self.pub.publish(msg)
    self.get_logger().info(f'Sending message: [{msg.data}]')
    self.count += 1

def main():
  rclpy.init()
  node = M_pub()
  try:
    rclpy.spin(node)
  except:
    node.destroy_node()

if __name__ == '__main__':
  main()

