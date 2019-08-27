//https://makerpro.cc/2017/03/how-to-set-up-esp32-on-arduino-ide/
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
int BT_Pin=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
  pinMode(BT_Pin,INPUT);//風扇relay

}
/*
void loop() {
  int BTStat=0; 
  while(true){
    if(digitalRead(BT_Pin)==1){
      delay(10);
      if(BTStat==0){
        BTStat=1;
        SerialBT.print("0");
        Serial.println("0");
      }
    }else{
      if(BTStat==1){
        BTStat=0;
        SerialBT.print("1");
        Serial.println("1");
        delay(10);
      }
    }
  }
}
*/
void loop() {
  if(digitalRead(BT_Pin)==0){
    delay(1);
    if(digitalRead(BT_Pin)!=0){
      Serial.println("ppp");
    }
  }
}
   //SerialBT.print("0");Serial.print("0");delay(20);
