import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rclpy.qos import QoSProfile

class M_turtle(Node):
  def __init__(self):
    super().__init__('move_turtle')
    self.qos = QoSProfile(depth = 10)
    self.pub = self.create_publisher(Twist, '/cmd_vel', self.qos)
    self.create_timer(0.4, self.pubmessage)
    self.vel = 0.0

  def pubmessage(self):
    self.msg = Twist()
    self.msg.linear.x = self.vel
    self.msg.linear.y = 0.0
    self.msg.linear.z = 0.0
    self.msg.angular.x = 0.0
    self.msg.angular.y = 0.0
    self.msg.angular.z = 0.5
    self.pub.publish(self.msg)
    self.get_logger().info(f'Seding message: [{self.msg}]')
    self.vel += 0.005
    if self.vel > 0.22:
      self.vel = 0.0

def main():
  rclpy.init()
  node = M_turtle()
  try:
    rclpy.spin(node)
  except:
    node.msg.linear.x = 0.0
    node.msg.angular.z = 0.0
    for i in range(10):
      node.pub.publish(node.msg)
    node.destroy_node()

if __name__ == '__main__':
  main()

