#include <Arduino.h>
#include "parse_merge.h"

static unsigned char pwm_val = 0;
static unsigned char id_m = 0;
static unsigned char pos_m = 0;

void turn_motor(unsigned char _pos_){
  if(_pos_ == 1){
    digitalWrite(7, 1);
    digitalWrite(8, 0);
  }else{
    digitalWrite(7, 0);
    digitalWrite(8, 1);
  }
}

void setup(){
  Serial.begin(9600);
  
  /*
  * 5 -> motor left
  * 6 -> motor right
  * 7 -> control right
  * 8 -> control left
  */
  for(int x=5; x<=8; x++)
    pinMode(x, OUTPUT);

  Serial.println("Ready to Receive Command!");
}

void loop(){
  if(Serial.available() > 0){
    WAIT_DATA_UNTIL('\n');
    parse_string();
    
    Serial.println("-==| DATA RECEIVED! |==-");
    Serial.println("Data Total\t: " + String(get_data_total()));
    Serial.println("ID motor\t: " + DATA_STR(0));
    Serial.println("Arah Putar\t: " + DATA_STR(1));
    Serial.println("Nilai PWM\t: " + DATA_STR(2) + "\n\n");
    
    if(DATA_STR(0) == "0"){
      id_m = 5;
      analogWrite(6, 0);
    }else if(DATA_STR(0) == "1"){
      id_m = 6;
      analogWrite(5, 0);
    }else{
      id_m = 0;
      analogWrite(5, 0);
      analogWrite(6, 0);
    }
    
    if(DATA_STR(1) == "0" || DATA_STR(1) == "left") pos_m = 0;
    else if(DATA_STR(1) == "1" || DATA_STR(1) == "right") pos_m = 1;
    else pos_m = 0;
    
    pwm_val = DATA_STR(2).toInt();
    clear_str();
  }
  
  turn_motor(pos_m);
  analogWrite(id_m, pwm_val);
}
