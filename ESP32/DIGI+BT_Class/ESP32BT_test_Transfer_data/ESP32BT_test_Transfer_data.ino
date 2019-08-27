//https://makerpro.cc/2017/03/how-to-set-up-esp32-on-arduino-ide/
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
  pinMode(36,ANALOG);

}

void loop() {

  SerialBT.print(int(analogRead(36)));
  Serial.println(analogRead(36));
  delay(300);
}
