import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Mt_pub(Node):
  def __init__(self):
    super().__init__('mpub')
    self.pub = self.create_publisher(String, 'message', 10)
    self.tpub = self.create_publisher(String, 'time', 10)
    self.create_timer(1, self.pubmessage)
    self.create_timer(0.1, self.pubtime)
    self.count = 0
    self.time = 0

  def pubmessage(self):
    msg = String()
    msg.data = f'hello, world : {self.count}'
    self.pub.publish(msg)
    self.get_logger().info(f'Seding message: [{msg.data}]')
    self.count += 1

  def pubtime(self):
    tmsg = String()
    tmsg.data = f'publish time : {self.time}'
    self.tpub.publish(tmsg)
    self.time += 0.1

def main():
  rclpy.init()
  node = Mt_pub()
  try:
    rclpy.spin(node)
  except:
    node.destroy_node()

if __name__ == '__main__':
  main()

