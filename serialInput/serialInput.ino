int blinkDelay=0;
void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);
}

void blink();

void loop(){
    if(Serial.available()){
        char ch= (char)Serial.read();
        Serial.println(ch);
        if(isDigit(ch)){
            blinkDelay=(ch-'0');
            blinkDelay=blinkDelay*100;
            Serial.print("blinkDelay = ");
            Serial.print(blinkDelay,DEC);
            Serial.println(" ");
        }
    }
    blink();
}

void blink(){
    digitalWrite(LED_BUILTIN,HIGH);
    delay(blinkDelay);
    digitalWrite(LED_BUILTIN,LOW);
    delay(blinkDelay);
}