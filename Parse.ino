#include <Arduino.h>
#include "parse_merge.h"

static unsigned char pwm_val = 0;
static unsigned char id_m = 0;
static unsigned char pos_m = 0;

void setup(){
  Serial.begin(9600);
  pinMode(5, OUTPUT); // motor left control (0)
  pinMode(6, OUTPUT); // motor right control (1)
}

void loop(){
  if(Serial.available() > 0){
    WAIT_DATA_UNTIL('\n');
    parse_string();
    
    Serial.println("-==| DATA RECEIVED! |==-");
    Serial.println("Data Total\t: " + String(get_data_total()));
    Serial.println("ID motor\t\t: " + DATA_STR(0));
    Serial.println("Arah Putar\t: " + DATA_STR(1));
    Serial.println("Nilai PWM\t: " + DATA_STR(2));
    
    if(DATA_STR(0) == "0" || DATA_STR(0) == "1")
      id_m = (DATA_STR(0).toInt() + 5);
    else id_m = 5;
    
    if(DATA_STR(1) == "0" || DATA_STR(1) == "left") pos_m = 0;
    else if(DATA_STR(1) == "1" || DATA_STR(1) == "right") pos_m = 1;
    else pos_m = 0;
    
    pwm_val = DATA_STR(0).toInt();
  }
  
  if(pos_m == 1){
  }
}
