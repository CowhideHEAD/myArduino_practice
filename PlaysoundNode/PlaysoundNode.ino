#define BUZZER 3
#define C   262
#define D   294
#define E   330
#define F   349 
#define G   392
#define A   440
#define B   494

unsigned long int duration =250;
void setup(){

}

void loop(){

    tone(BUZZER,C,duration);
    delay(1000);
    tone(BUZZER,D,duration);
    delay(1000);
    tone(BUZZER,E,duration);
    delay(1000);
    tone(BUZZER,F,duration);
    delay(1000);
    tone(BUZZER,G,duration);
    delay(1000);
    tone(BUZZER,A,duration);
    delay(1000);
    tone(BUZZER,B,duration);
    delay(1000);
}