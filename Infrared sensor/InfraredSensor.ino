#define ENable  5
#define Irradiance A5

int SenserValue;

void setup(){
    pinMode(ENable, OUTPUT);
    pinMode(Irradiance, INPUT);
    Serial.begin(9600);

}

void loop(){
    digitalWrite(ENable,LOW);
    if(analogRead(Irradiance)){
        SenserValue=analogRead(Irradiance);
        Serial.println("Yes!");
        Serial.println(SenserValue);
        delay(500);
    }
    else{
        Serial.println("No!");
        delay(500);

    }


}