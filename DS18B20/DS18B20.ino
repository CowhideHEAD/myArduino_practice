#include <DHT.h>

#include <core_build_options.h>
#include <swRTC.h>

#include <TimerOne.h>
#include <MultiFuncShield.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "my_oneWire.h"
#define ONE_WIRE_BUS    5  //wired pin number
#define DQpin   5
#define THERMO_BUTTON   A2

//OneWire Commands
#define READSCRATCH     0xBE  // Read from scratchpad



#define LATCH_PIN 4
#define CLK_PIN   7
#define DATA_PIN  8

byte select_seg1 = 0xF1;
byte select_seg2 = 0xF2 ;
byte select_seg3 = 0xF4 ;
byte select_seg4 = 0xF8 ;

unsigned long value;

//setup a oneWire instance 
OneWire onewire(ONE_WIRE_BUS);

//Pass onewire reference to Dallas Temperture 
DallasTemperature sensor(&onewire);

//define to hold device address
DeviceAddress Thermometer_0, Thermometor_1;

OneWire* _wire;


void setup(void){
    /*serial port open*/
    Serial.begin(9600);
    
    // /*Start up the library*/
    sensor.begin();
    Serial.println(sensor.getDeviceCount(),HEX);

    // initialize Realtime clock

    swRTC cur_RTC;

        cur_RTC.stopRTC();
        cur_RTC.setTime(17, 05, 50);  //시, 분, 초
        cur_RTC.startRTC();

    // initialize multi-function shield library
    Timer1.initialize();
    MFS.initialize(&Timer1); 


   
    // device's address where storiged temparture data
    if (!sensor.getAddress(Thermometor_1, 1)) Serial.println("Unable to find address for Device 1");

    if(sensor.getAddress(Thermometer_0,0)){
        Serial.print("Device 0 Address :");
        printAddress(Thermometer_0);
    }  
    else Serial.println("Unable to find address for Device 0");

    Serial.println(" ");
    if(sensor.getAddress(Thermometor_1,1)){
        Serial.print("Device 1 Address : ");
        printAddress(Thermometor_1);
    }
    else Serial.println("Unable to find address for Device 1");
    
    


    
 

}

void printAddress(DeviceAddress deviceAddress){
        for(uint8_t i =0;i<8;i++){
            //if(deviceAddress[i]<16) Serial.print("0");
            Serial.print(deviceAddress[i]);
        }
    }


void printTemperture(DeviceAddress deviceAddress){
    float temptureC=sensor.getTempC(deviceAddress);
    Serial.print("Temperature :");
    Serial.print(temptureC);
    Serial.println("C");
}


float getTemperture_as_float(DeviceAddress deviceAddress){
    return sensor.getTempC(deviceAddress);
}




void loop(){
    // if(analogRead(THERMO_BUTTON)==LOW){
    //     while (true)
    //     {
        sensor.requestTemperatures();
        printTemperture(Thermometer_0);
        MFS.write("5S5S");
        delay(1000);
       
      //  }   
    //}
    
    // Serial.println("Nothing");
    // delay(1000);



}