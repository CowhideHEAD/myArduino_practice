#define POTmeter A0
#define BUZZER  3

unsigned long int analogedata;
unsigned long int value;
void setup(){
    Serial.begin(9600);

}

void loop(){
    
    analogedata=analogRead(POTmeter);
    value=map(analogedata,0,1023,0,100);

    //analogWrite(BUZZER,value);

    Serial.println(value);


}