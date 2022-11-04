#define SWITCH_1    3
#define SWITCH_2    2
#define RED_LIGHT   12
#define BLUE_LIGHT  13
#define IRSENSOR_PIN   7
#define LDRSENSOR_PIN   A1

#define RGB_RED     9
#define RGB_GREEN   10
#define RGB_BLUE    11
#define BUZZER_PIN  5

#define BUZZER_COUNT_ONE    1
#define BUZZER_COUNT_TWICE  2

#define PRESS_SAMETIME_SWITCH   (abs(pressSWITCH_1() - pressSWITCH_2())> 0 ? true : false)






void setup(){
    Serial.begin(9600);
    interrupts();
}

bool debounce(int SWITCH){
    bool flag_1,flag_2;
    
    while(true){
        flag_1=digitalRead(SWITCH);
        flag_2=digitalRead(SWITCH);
        if(flag_1 == flag_2)    break;
    }   
    
    
}

//스위치 1이 눌린시간을 반환하는 함수
unsigned long getSWITCH_1_pressTime(){
static bool state;
static unsigned long switchtime=0;
    if(digitalRead(SWITCH_1)==LOW){
        debounce(SWITCH_1);
        state !=state;
        switchtime=millis();
    }
    if(state ==LOW) return millis()- switchtime;
    else return 0;
}


// interupt call back함수
void stop_until_NO_MOVEMENT(){
    while (true){
        Serial.println("Interupted...");
        delay(1);

    }

}

// void (*ptr_stopfun)()=stop_until_NO_MOVEMENT;

//빨강,초록,파랑 LED 깜빡이는 함수
void RGB_LIGHT(int delayTime=800){
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);

    digitalWrite(RGB_RED,HIGH);
    digitalWrite(RGB_GREEN,HIGH);
    digitalWrite(RGB_BLUE,HIGH);
    delay(delayTime);

    digitalWrite(RGB_RED,LOW);
    digitalWrite(RGB_GREEN,LOW);
    digitalWrite(RGB_BLUE,LOW);


}
//부저 따르릉함수
void buzzer(int durationTime=1000){
    pinMode(BUZZER_PIN,OUTPUT);

    for(int duration=0;duration<durationTime;duration++){
        digitalWrite(BUZZER_PIN,LOW);
        delay(1);
        digitalWrite(BUZZER_PIN,HIGH);
    }

}

bool IRsensor(){
    pinMode(IRSENSOR_PIN,INPUT);
    if(digitalRead(IRSENSOR_PIN)==LOW){
        Serial.println("MOVEMENT DETECT!"); 
    //   attachInterrupt(digitalPinToInterrupt(7),stop_until_NO_MOVEMENT,LOW);   //트리거 기준이 뭐야
        RGB_LIGHT();
        while(digitalRead(IRSENSOR_PIN)==LOW){};
        return true;
    }    
    else{
        Serial.println("NOW work");
        return false;
    }

    
    // delay(500);
}

bool test(){
    pinMode(LDRSENSOR_PIN,INPUT);
    pinMode(BLUE_LIGHT,OUTPUT);
    pinMode(RED_LIGHT,OUTPUT);

    if(analogRead(LDRSENSOR_PIN)>900){
        Serial.println("test pass");
        digitalWrite(BLUE_LIGHT,HIGH);
        Serial.println(analogRead(LDRSENSOR_PIN));
        delay(1000);
        }
    else{
        Serial.println("test fail");
        digitalWrite(RED_LIGHT,HIGH);
        Serial.println(analogRead(LDRSENSOR_PIN));

        delay(1000);
    }

    digitalWrite(BLUE_LIGHT,LOW);
    digitalWrite(RED_LIGHT,LOW);

    //buzzer();
    delay(500);
    //buzzer();


}


void loop(){

    //안전장치 활성화
    // if(IRsensor()==true) {}
    // else{


        // while(PRESS_SAMETIME_SWITCH==true){
        // if(PRESS_SAMETIME_SWITCH ==false) break;
        // buzzer();
        // test();
        // delay(1000);
        // }
    
    //}
    
    Serial.println(getSWITCH_1_pressTime());
    delay(1000);


        

    
   
}

    
   
    
        
        
    


