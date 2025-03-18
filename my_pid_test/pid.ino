void pid_line_follow() {
  while (true) {
    line_pos();
    if (sum == 0) {
      //______________90 degree left right turn_____________
      if (flag != 's') {
        (flag == 'l') ? turn(-turnSpeed, turnSpeed) : turn(turnSpeed, -turnSpeed);
      }
    }
    //___________________________ normal line follow ___________________________
    else if (sum == 1 || sum == 2) {
      //___________________________ left forward or right forward turn ___________________________
      if (cross != 's') {
        (cross == 'l') ? turn(-turnSpeed, turnSpeed) : turn(turnSpeed, -turnSpeed);
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
