//https://makerpro.cc/2017/03/how-to-set-up-esp32-on-arduino-ide/
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
  pinMode(4,OUTPUT);

}

void loop() {
  
  if(SerialBT.available()){
    Serial.println("");
  }
  while(SerialBT.available())
  {
    char btdata=SerialBT.read();
    Serial.print(btdata);//查看藍芽輸入的值
    if (btdata=='1'){digitalWrite(4,HIGH);}//關風扇
    if (btdata=='2'){digitalWrite(4,LOW);}//開風扇

    
  }
   //SerialBT.print("0");Serial.print("0");delay(20);
  delay(100);
}
