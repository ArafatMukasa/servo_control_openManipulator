#if defined (ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  
#else 
  #include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float64.h>

const float pi = 3.141592654;
float angle_deg;
float angle_rad;
int angle_micro;

ros::NodeHandle nh;

Servo servo;

void servo_cb (const std_msgs::Float64& cmd_msg) 
{
  
  angle_rad = cmd_msg.data; // angle_rad is an angle in radians. The angle value received from the publisher (cmd_msg.data) is in radians. 
  angle_deg = angle_rad * (180/pi);//angle_rad is then converted to degrees. 
  angle_micro = int (600 + angle_deg * (50.0/9.0));//This converts angle_deg to angle_micro (angle in microseconds to drive the servo motor). 600 is the lowest value in microseconds the servo canaccept, below which the servo will be damaged.  
    
  servo.writeMicroseconds (angle_micro); 
  digitalWrite (13, HIGH-digitalRead(13)); //toggle led 

}


ros::Subscriber <std_msgs::Float64> sub ("/open_manipulator/joint1_position/command", servo_cb);


void setup ()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe (sub);
  servo.attach (9, 600, 2300); //attach servo on pin 9. The lowest value is 600 and highest is 2,300 microseconds that could be written to pin 9. 
}


void loop ()
{
  nh.spinOnce();
  delay(15);
}
