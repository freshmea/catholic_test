# catholic_test
my first code repository
this is first edit


- - -

## 2023_02_13

- - -

* 1 교시
  * turtlebot3 조립
  * Environment VMware 17 Ubuntu 20.04

* 2 교시
  * ROS2 DDS 설명
  * 터틀봇3 조립
* 점심시간
* 3 교시
  * ROS2 cli 설명
* 4교시
  * 깃 설정:
    * gitHub ID 만들기.
    * VSCode git 연동 설명.
* 5교시
  * 터틀심 실습
  * 터틀심 스폰 시키기( 토픽 이름 변경)
```
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: 'turtle2'}"
```
  * 터틀심 두개 만들어서 각각 ros2 topic pub 으로 제어
```shell
  ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist '{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}'
  ros2 topic pub --rate 1 /turtle2/cmd_vel geometry_msgs/msg/Twist '{linear: {x: 4.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}'
```
* 6교시
  * 마크 다운 문서 쓰는 법 .
  * 오늘 배운 것 마크다운 문서로 정리.
  * Ubuntu 한글 설정
* 7교시
  * 파라미터 설정, 액션 커맨드 사용 등.
```shell
git config --global user.email "freshmea@naver.com"
git config --global user.name "freshmea"


ros2 topic pub --rate 1 /turtle2/cmd_vel geometry_msgs/msg/Twist '{linear: {x: 4.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}'

ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: 'turtle2'}"

```


