const int inputPin =2;
void setup(){

    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(inputPin,INPUT);
    Serial.begin(9600);
}

bool debouce(int pin){
    bool state;
    bool previousState;
    int bouncedelay=10;

    previousState=digitalRead(inputPin);    //0이면 false 0이아니면 true
    for(int counter=0;counter<bouncedelay;counter++){
        state=digitalRead(inputPin);
        delay(1);   //1ms delay
        
        if(state!=previousState){
            state=false;
            counter=0;
            previousState=state;
        }
        counter+=1;
    }



}


void loop()
{
    int val = digitalRead(inputPin);
    bool bittom_state=debouce(inputPin);
    if(val==HIGH){
        
        digitalWrite(LED_BUILTIN,HIGH);
        Serial.print(val);
        Serial.print(" ");
        
    }
    else{
        digitalWrite(LED_BUILTIN,LOW);
        Serial.print(val);
        Serial.print(" ");
        

    }
    
    
}