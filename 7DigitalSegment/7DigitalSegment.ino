
#define LATCH_PIN 4
#define CLK_PIN   7
#define DATA_PIN  8


 void SendDataToSegment(byte Segment_no, byte hexValue);
 
const byte C_HEX  = 0xC6;
const byte TWO_HEX  = 0xA4;
const byte P_HEX  = 0x8C;

byte select_seg1 = 0xF1 ;
byte select_seg2 = 0xF2 ;
byte select_seg3 = 0xF4 ;
byte select_seg4 = 0xF8 ;





const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};


void setup ()
{
/* All the pins like latch, clock and data pins are used as output */
  pinMode(LATCH_PIN,OUTPUT);
  pinMode(CLK_PIN,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
 


}

/* Main program */
void loop()
{
/* Update the display with the current counter value */
  SendDataToSegment(select_seg1 , C_HEX);
  SendDataToSegment(select_seg2 , TWO_HEX);
  SendDataToSegment(select_seg3 , P_HEX);
   
}

 
void SendDataToSegment(byte Segment_no, byte hexValue)
{
  /* Make Latch pin Low */
  digitalWrite(LATCH_PIN,LOW);
  /* Transfer Segmenent data */
  shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, hexValue);
    /* Transfer Segmenent Number  */
  shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, Segment_no );
    /* Make Latch pin High so the data appear on Latch parallel pins */
  digitalWrite(LATCH_PIN,HIGH);
}