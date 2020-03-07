/**********************
 Trainer KMDEI (Parser)
***********************/

#include <Arduino.h>

void setup(){Serial.begin(9600);}

void loop(){
	if(Serial.available() > 0){
		data = Serial.readString();
		parse_string();
		
		Serial.println("Total Data [" + String(get_data_total()) + "] --> [0] " + DATA_STR(0) + "; [1] " + DATA_STR(1));
		clear_str();
	}
}
