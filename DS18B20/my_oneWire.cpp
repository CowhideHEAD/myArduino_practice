#include "my_oneWire.h"
#include <Arduino.h>

/*
    마스터가 HIGH에서 LOW로 레벨전환이 될때 명령시작
    LOW상태에서 최소480us~960us를 유지 ==reset pulse
    신호가끝나면 pull up 저항에의해 DS18B20이 HIGH상태가된다. 15us유지
    이때부터 DS18B20이 master에게 신호를 보낸다.
    HIGH 에서 LOW로 60us~240us 유지
    다시 LOW에서 HIGH로 신호가 바뀐다.


*/

/**/
void Initialization(unsigned int pin){
    unsigned long Time=0;
    unsigned long current=0;
    unsigned long previous=0;

    pinMode(pin,OUTPUT);
    //reset pulse start
    digitalWrite(pin,LOW);
    delayMicroseconds(500);
    previous=micros();
    Serial.print("Master Tx resetpulse time");
    Serial.println(previous);
    
    
    //wait 15~60us and receive slave sending data
    pinMode(pin,INPUT);
    previous=micros();

    while(digitalRead(pin)==HIGH){} //SUC!
    current=micros()-previous;
    // Serial.print("DS18B20 wait time: ");
    // Serial.println(current);
    


    //Master Rx presence pulse
    previous=micros();
    Serial.print("previous ::");
    Serial.println(previous);
    while(digitalRead(pin)==LOW){}
    if(digitalRead(pin)==HIGH){
    current=micros()-previous;
    Serial.print("Master Rx time: ");
    Serial.println(current);
    }
    
  
}
