#include<EEPROM.h>
//___________motor pin bot 2_____________
#define left_motor_forward_pin 6
#define left_motor_backward_pin 7
#define right_motor_forward_pin 10
#define right_motor_backward_pin 9
#define left_motor_speed_pin 5
#define right_motor_speed_pin 11

// //___________motor pin bot 1_____________
// #define left_motor_forward_pin 10
// #define left_motor_backward_pin 9
// #define left_motor_speed_pin 11
// #define right_motor_forward_pin 6
// #define right_motor_backward_pin 7
// #define right_motor_speed_pin 5


//________________Define button pins____________

#define light_pin 13
#define switch_pin 12

byte base[8] = {1, 2, 4, 8, 16, 32, 64, 128}; //ir sensor base value
//_______________pid variable_________________
int Weight[8]={100,200,300,400,500,600,700,800};
float kp = 1, kd = 40; //pid parameter ,need to be adjust1.15 28
float P,D;
int prevError = 0;
int error, sumWS = 0, linePos;
int delSpeed;
int MAX_SPEED=250,MIN_SPEED=-250,SET_SPEED=250,SET_POINT=450;
int Lspeed,Rspeed;
#define turnSpeed 80

byte btn_press = 0;
int sensor_value[8];    //store sensor analog read value

byte sum = 0; //store total sensor in black line

int decimal;  //store sensor analog read value in decimal

int maximum[8], minimum[8], mid[8];       //store sensor analog read  maximum , minimum and mid value

//________________________________ logic detection variable ________________________________
char flag='s';
char cross='s';          // for |- or -| path detection
uint32_t m1;//,m2;
char side = 'l';         // for left hand rule or right hand rule
// #define u_turn_delay 200   //delay for u turn 
#define node_delay 30     //to make perfact 90 degree turn
// #define stop_timer 150     // stop delay if find end point  

void setup() {

  Serial.begin(9600);
  //_____________reading maximum, minimum,mid value from EEPROM___________________
  for (int i = 0; i < 8; i++) {
    mid[i] = EEPROM.read(i) * 4;
    maximum[i] = EEPROM.read(i + 8) * 4;
    minimum[i] = EEPROM.read(i + 16) * 4;
    Serial.println(String(maximum[i]) + " " + String(mid[i]) + " " + String(minimum[i]));
  }
  pinMode(12, INPUT_PULLUP);     //Switch pinMode
  pinMode(13, OUTPUT);     //Light pinMode
    // _____motor pinMode_______
  pinMode(left_motor_forward_pin, OUTPUT);
  pinMode(left_motor_backward_pin, OUTPUT);
  pinMode(left_motor_speed_pin, OUTPUT);
  pinMode(right_motor_forward_pin, OUTPUT);
  pinMode(right_motor_backward_pin, OUTPUT);
  pinMode(right_motor_speed_pin, OUTPUT);
}
void loop() {
  btn_press = button_read();
  if (btn_press == 1) pid_line_follow2();
  else if (btn_press == 2)  cal();
  else if (btn_press == 3)  motor(150,0);
  else if (btn_press == 4)  motor(0,150);
  else if (btn_press == 5)  motor(150,150);
}
