void turn(int a, int b) {
  motor(a, b);
  while (sensor_value[6] + sensor_value[5] + sensor_value[4] + sensor_value[3] + sensor_value[2] + sensor_value[1] > 0) sensor_read();
  while (sensor_value[2] == 0 && sensor_value[3] == 0) sensor_read();
//  Serial.print(flag);
//  Serial.print(" ");
//  Serial.println(cross);
  flag = 's';
  cross = 's';
}
