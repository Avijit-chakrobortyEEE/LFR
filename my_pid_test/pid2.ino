void pid_line_follow2() {
  Serial.println("start");
  while (true) {
    //    if (millis() - m1 > 500) flag = 's';
    line_pos2();
    sensor_read();
    if (sum == 0) {
      //______________90 degree left right turn_____________
      if (flag != 's') {
        (flag == 'l') ? motor(-turnSpeed, turnSpeed) : motor(turnSpeed, -turnSpeed);
        while (sensor_value[3] == 0 && sensor_value[4] == 0) sensor_read();
        flag = 's'; //when you are done turning robot, make the flag to its normal state so that robot wont turn on its own when it finds no line without detecting 90degree logic
      }
      //      delay(800);motor(0,0);
    }
    //___________________________ normal line follow ___________________________
    else if (sum == 2 || sum == 1) {
      //___________________________ left forward or right forward turn ___________________________
      if (cross != 's') {
        (cross == 'l') ? motor(-turnSpeed, turnSpeed) : motor(turnSpeed, -turnSpeed);
        while (sensor_value[5] + sensor_value[4] + sensor_value[3] + sensor_value[2] > 0) sensor_read();
        while (sensor_value[3] == 0 && sensor_value[4] == 0) sensor_read();
        cross = 's';
      }
      P = kp * error;
      D = kd * (error - prevError);
      delSpeed = P + D;
      Lspeed = SET_SPEED + delSpeed;
      Rspeed = SET_SPEED - delSpeed;

      Lspeed = constrain(Lspeed, MIN_SPEED, MAX_SPEED);
      Rspeed = constrain(Rspeed, MIN_SPEED, MAX_SPEED);
      // Serial.println(" Pos:" + String(linePos) + " Err:" + String(error) + " delS:" + String(delSpeed) + " L:" + String(Lspeed) + " R:" + String(Rspeed));

      motor(Lspeed, Rspeed);
      prevError = error;
    }
  }
}












//___Alternative___//

// int Lspeed = leftBaseSpeed - adjust;
// int Rspeed = rightBaseSpeed + adjust;


// if(LSspeed>250) Lspeed=250;
// else if(Lspeed<=0) Lspeed=0;
// if(Rspeed>250) Rspeed=250;
// else if(Rspeed<=0) Rspeed=0;
