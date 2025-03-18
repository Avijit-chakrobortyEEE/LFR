void line_pos(){
  sumWS = 0;
  sensor_read();
   //________________________________ calculate error ________________________________
  for (int i=0; i<=7; i++) {                     //------------------------------------------
    sumWS += sensor_value[i] * Weight[i];        //---------calculate sum * Weight-----------
  }                                              //------------------------------------------
  if (sum!=0)linePos=sumWS/sum;                  //---------calculate line Position-----------
//  else while(sum==0) motor(-100,100);
  error=SET_POINT-linePos;                       //---------calculate error and SET_POINT is desire line position-----------


    //________________________________ left,right,left-forward,right-forward turn,30,45 ________________________________
  if (sum == 3 || sum == 4 || sum == 5||sum == 6) {
    if (sensor_value[7]+sensor_value[6] > 0 && sensor_value[0] == 0 && sensor_value[3] + sensor_value[4] > 0) {       //_________90 degree left detection logic___________
      flag = 'l';                                                                                                     //_________90 degree left detected___________
      while (sensor_value[7] == 1 && sensor_value[0] == 0) sensor_read();                                             //_________90 degree left and forward detection logic___________
      if (sensor_value[0] == 0) {                                                                                     //_________90 degree left and forward detection logic to seperate from T section___________
        delay(node_delay);                                                                                            //_________90 degree left and forward detection logic___________
        sensor_read();                                                                                                //_________90 degree left and forward detection logic___________
        if (sum != 0) if (side == 'l') cross = 'l';                                                                   //_________90 degree left and forward detected___________
      }
    }

    else if (sensor_value[0]+sensor_value[1] > 0 && sensor_value[7] == 0 && sensor_value[3] + sensor_value[4] > 0) {    //_________90 degree right detection logic___________
      flag = 'r';                                                                                        //_________90 degree right detected___________
      while (sensor_value[7] == 0 && sensor_value[0] == 1) sensor_read();                                //_________90 degree right and forward detection logic___________
      if (sensor_value[7] == 0) {                                                                        //_________90 degree right and forward detection logic to seperate from T section___________
        delay(node_delay);                                                                               //_________90 degree right and forward detection logic___________
        sensor_read();                                                                                   //_________90 degree right and forward detection logic___________
        if (sum != 0) if (side == 'r') cross = 'r';                                                       //_________90 degree right and forward detected___________
      }
    }
    m1 = millis();
  }
  if(millis()-m1>500) flag='s';
}
