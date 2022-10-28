/*
    스위치를 누를때 바운스 현상이 일어난다. 그러나 이는 너무빠르게 지나가기때문에 관측하기 어렵다.
    프로그램을 통해 바운스가 일어나는지, 몇변일어나는지 count해보자

    
*/

const int inputpin=2;
int bouncelow=0;
int bouncehigh=0;


void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(2,INPUT);

}

void loop(){

    
    
    while(digitalRead(inputpin)==true){
        if(digitalRead(inputpin)==0){
             bouncelow+=1;
            digitalWrite(LED_BUILTIN,HIGH);
    }
    else if(digitalRead(inputpin)!=0){
             bouncehigh+=1;
            digitalWrite(LED_BUILTIN,LOW);

    }
    }
    

    Serial.print("bounce low : ");
    Serial.print(bouncelow);
    Serial.print("\n");
    Serial.print("bounce high : ");
    Serial.print(bouncehigh);
    delay(1);
    

}