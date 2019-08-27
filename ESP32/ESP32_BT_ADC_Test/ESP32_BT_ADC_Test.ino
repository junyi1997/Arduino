int pinADC[]={36, 39, 34, 35, 32, 33};//25, 26, 27, 14, 12, 13, 4, 0, 2, 15
int state[]={0,0,0,0,0,0,0,0};
int small_R=3700;
#include <driver/adc.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include "esp32-hal-adc.h" 
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
void setup()
{
  for (int i=0; i<8; i++)
  {
    pinMode(pinADC[i], ANALOG);
  }
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
}
void loop()
{
  for(int i = 0 ; i < 6 ; i++)
  {
    Serial.print(analogRead(pinADC[i]));Serial.print("\t");  
  }
  int read_raw1;int read_raw2;
  adc2_config_channel_atten( ADC2_CHANNEL_8, ADC_ATTEN_6db );
  esp_err_t r = adc2_get_raw( ADC2_CHANNEL_8, ADC_WIDTH_12Bit, &read_raw1);
  Serial.print(read_raw1);Serial.print("\t");
  adc2_config_channel_atten( ADC2_CHANNEL_9, ADC_ATTEN_6db );
  esp_err_t r1 = adc2_get_raw( ADC2_CHANNEL_9, ADC_WIDTH_12Bit, &read_raw2); 
  Serial.println(read_raw2);
  delay(100);
}
