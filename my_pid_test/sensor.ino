//____________________Create sensor reading function____________________
void sensor_read() {
  sum = 0;
  decimal=0;
  for(int i=0; i<8; i++){
  sensor_value[i] = analogRead(i);
    (sensor_value[i] > mid[i]) ? sensor_value[i] = 1 : sensor_value[i] = 0;
    decimal+=sensor_value[i]*base[i];
    sum += sensor_value[i];
  }
}
//____________________Create sensor showing function____________________
void show_the_value() {
  sensor_read();
  for (int i = 7 ; i >= 0 ; i--) {
    Serial.print(sensor_value[i]);
    Serial.print("");
  }
  Serial.print(" SUM:");
  Serial.println(sum);
  // delay(500);
}
