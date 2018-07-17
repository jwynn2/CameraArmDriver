/**
 * Author Dat Nguyen
 * Date: 6/4/2018
 *
 * This library help perform sequences and movement of the vamera Arm
 */


#ifndef CameraArmDriver_h
#define CameraArmDriver_h

#include <Servo.h>
#include <Arduino.h>



class CameraArmDriver{

  public:

  //define range of motor
  // these defineition need to be config and change everytime using a new set of servo.
  	// custom min/max pulse width settings that best suit my servos
  //shoulder
  const int CENTER_SHOULDER= 76;
  const int CW_SHOULDER= 0; // right
  const int CCW_SHOULDER =170; // left
  const int SHOULDER_MIN_PW= 570;//calibrate the servo to get the best fit value.
  const int SHOULDER_MAX_PW =2470;

  //base
  const int CENTER_BASE =87;
  const int CW_BASE =8; // right
  const int CCW_BASE =173; // left
  const int BASE_MIN_PW =570;//calibrate the servo to get the best fit value.
  const int BASE_MAX_PW =2470;

	#define S_OFFSET 0
  #define S_SPEED 20 // um pwm delay interpret as speed.


  CameraArmDriver();// DEFAULT
  // init Servo
  void cameraArmBegin(int basePin, int shoulderPin);
  void end();
  void turnBase(char pos );
  void turnShoulder(char pos );
	void commandMode();
  /**
   * This function get/ set the cameraFacePosition
   */
  int getCameraFacePosition();
  void setCameraFacePos(char pos); 

  /**
   * This function turn the base and init the shoulder to the left or right
   * take 1 argument 'r' or 'l' the position the relative to the camera arm namespace
   * not from the mobile platform
   * void
   */
  void turn(char pos);

  /**
   * this funciton init the camera arm to rest position
   */
  void rest();


  private:
    Servo _base, _shoulder;
    int _basePin, _shoulderPin;
    byte cameraFacePos; // 1 beging right, -1 begin left, 0 being middle  
};


#endif
