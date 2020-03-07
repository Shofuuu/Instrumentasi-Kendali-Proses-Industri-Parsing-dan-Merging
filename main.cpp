/**********************
 Trainer KMDEI (Merger)
***********************/

#include <Arduino.h>

void setup(){Serial.begin(9600);}

void loop(){
	Serial.write(ADC_Read(0) + ";" + ADC_Read(1));
	delay(10);
}
