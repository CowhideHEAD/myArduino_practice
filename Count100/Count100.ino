/*
    1~100 까지 1초간격으로 숫자를 증가시킵니다. 그리고 이를 화면상에 출력합니다.
    100이 완료되면
    100~1까지 1초간격으로 숫자를 삼소시킵니다. 
    위 과정울 반복합니다.
*/

int count =1;

void setup(){
    Serial.begin(9600);
    
}

void loop(){
    
    while (count<100 && count>=1)
    {
        Serial.println(count);
        count+=1;
        delay(300);
        if(count==100) break;
    }
    
    while (count<=100 && count >=1)
    {
        Serial.println(count);
        count-=1;
        delay(300);

        if(count==1) break;

        
    }

    
        

}