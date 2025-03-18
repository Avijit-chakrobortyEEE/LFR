void motor(int a, int b) {
  if (a >= 0) {
    digitalWrite(left_motor_forward_pin, 1);
    digitalWrite(left_motor_backward_pin, 0);
  }
  else {
    a = -a;
    digitalWrite(left_motor_forward_pin, 0);
    digitalWrite(left_motor_backward_pin, 1);
  }
  if (b >= 0) {
    digitalWrite(right_motor_forward_pin, 1);
    digitalWrite(right_motor_backward_pin, 0);
  }
  else {
    b = -b;
    digitalWrite(right_motor_forward_pin, 0);
    digitalWrite(right_motor_backward_pin, 1);
  }
  analogWrite(left_motor_speed_pin, a);
  analogWrite(right_motor_speed_pin, b);
}