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

- - -
## 2023_2_14
- - -

* 1교시 (10시~)
  * 파이썬(속성)
    * 변수 설명
    * 함수 정의 설명
    * class 설명
    * 상속 설명
* 2교시
  * 패키지 설명
```shell
ros2 pkg create --build-type ament_python my_package
```
  * 노드 등록 하는 방법 설명 : setup.py 수정 'mp = my_package.mpub:main'
  * Error and Try
* 점심시간
* 3교시
  * mpub.py 작성
  * 한 노드에서 두 개의 노드에 topic 보내기 [mtpub.py, tsub.py]
* 4교시
  * mpub.py 변형해서 거북이 움직이기 [move_turtle.py, ]
* 5교시
  *
* 6교시
  *
