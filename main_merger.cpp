/**********************
 Trainer KMDEI (Merger)
***********************/

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <Arduino.h>
#include "lib/parse_merger.h"

void setup(){Serial.begin(9600);}

void loop(){
	Serial.write(ADC_Read(0) + ";" + ADC_Read(1));
	delay(10);
}
