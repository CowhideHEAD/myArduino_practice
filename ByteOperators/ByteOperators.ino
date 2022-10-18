/*
    ByteOperator 
    최소유효바이트 Lest significant Byte 와 최대유효바이트 Most significat Byte를 출력한다.
    highByte(i),lowByte(i)을 써본다.
*/
#define highWord(w)  ((w)>>16)
#define lowWord(w)  ((w)&0xffff)
long longValue = 16909060;    //4byte

void setup(){
    Serial.begin(9600);
}

void loop(){
    byte loByte,hiByte;

    int loWord=lowWord(longValue);
    int hiWord=highWord(longValue);

    Serial.println(loWord,DEC);
    Serial.println(hiWord,DEC);
    

    delay(10000);

}