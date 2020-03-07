/**********************
 Trainer KMDEI (Parser)
***********************/

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <Arduino.h>
#include "lib/parse_merger.h"

void setup(){Serial.begin(9600);}

void loop(){
	if(Serial.available() > 0){
		data = Serial.readString();
		parse_string();
		
		Serial.println("Total Data [" + String(get_data_total()) + "] --> [0] " + DATA_STR(0) + "; [1] " + DATA_STR(1));
		clear_str();
	}
}
