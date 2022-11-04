#define POTmeter A0
#define BUZZER  3

unsigned long int analogedata;
unsigned long int frequency;
void setup(){
    Serial.begin(9600);

}

void loop(){
    
    analogedata=analogRead(POTmeter);
   /// frequency=map(analogedata,0,1023,1000,50000);
    int duration = 250;
    for(int frequency=1000;frequency<3000;frequency++){
        tone(BUZZER,frequency,duration);
        delay(1);
        Serial.println(frequency);

    }

    for(int frequency=3000;frequency>1000;frequency--){
        tone(BUZZER,frequency,duration);
        delay(1);
        Serial.println(frequency);

    }
    

    if(Serial.read()){
        stop();
    }




}

void stop(){
    int count = 0;
    while(count<1000){
        count++;
        delay(1000);
    }
    count=0;

}