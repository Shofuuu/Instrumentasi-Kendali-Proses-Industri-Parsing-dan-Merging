/*
* Parse Library written in C++ (Arduino)
* by Muhammad Shofuwan Anwar
*/

#define DATA_STR(x) __data_flock__[x]
#define WAIT_DATA_UNTIL(x) __data__ = Serial.readStringUntil(x)
#define MAX 10

static String __data__ = "";
static String __data_flock__[MAX];

static void clear_str(void){
    for(int x=0;x<MAX;x++)
        __data_flock__[x] = "";
}

static void parse_string(){
    int counter = 0;
    String temp = "";

    if(__data__[__data__.length()-2] != ';')
        __data__ += ';';

    for(int x=0;x<__data__.length();x++){
        if(__data__[x] != ';'){
            temp += __data_flock__[x];
        }else{
            __data_flock__[counter] = temp;
            counter++;
            temp = "";
        }
    }
}

static int get_data_total(){
    int total = 0;

    for(int x=0;x<MAX;x++){
        if(__data_flock__[x] != "")
            total++;
    }

    return total;
}

/*void ADC_Init(unsigned char mux){
    ADCSRA |= (1<<ADEN);
    ADMUX = (1<<mux);
    ADMUX |= (1<<REFS0) | (1<<REFS1);
    ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}

int ADC_Read(unsigned char mux){
    ADC_Init(mux);

    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADSC)));
    return ADCW;
}*/
