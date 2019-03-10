# servo_control_openManipulator
This is the code that is uploaded to the arduino uno in order to control a servo motor connected to pin 9.  The commands to move to the arduino through a certain angle are given by publishing a rostopic command in the terminal. 

After uploading the code with the file name "servo-control_openManipulator" to the arduino uno successfully (should be able to work on mega too), the following commands are then run in their own terminals (a new terminal for each command). 

NB: For each new terminal window i opened, i run the following commands first. 
$ source /opt/ros/kinetic/setup.bash
$ source ~/catkin_ws/devel/setup.bash
$ roscore

Commands 7, 8, and 9 above are all run in the same terminal window. 
$ rosrun rosserial_python serial_node.py
$ rsotopic pub /open_manipulator/joint1_position/command std_msgs/Float64 "data: 2.0" 

Command 12 (rosserial_python) sets up serial communication between the computer running the master core (roscore) and arduino uno (serial_node). 
Command 13 commands joint1 of openManipulator to move 2 radians clockwise. 

NB: In the code running on arduino uno, i have converted radians to microseconds (its because am using a PowerHd 1711mg servo motor which only responds better to angle's in microseconds). 
