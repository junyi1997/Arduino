int pinADC[]={36, 39, 34, 35, 32, 33};//25, 26, 27, 14, 12, 13, 4, 0, 2, 15
int state[]={0,0,0,0,0,0,0,0};
int small_R=3800;
int big_R=1000;
int ADC_V0[8]={0,0,0,0,0,0,0,0};
int k=100;//取樣次數
#include <driver/adc.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include "esp32-hal-adc.h" 
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
void setup()
{
  for (int i=0; i<8; i++){pinMode(pinADC[i], INPUT);}
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
}
void loop()
{
  for(int j = 0 ; j < k ; j++)
  {
    for(int i = 0 ; i < 7 ; i++)
    {
      //Serial.print(analogRead(pinADC[i]));Serial.print("\t"); 
      ADC_V0[i]+=analogRead(pinADC[i]);
    }
    int read_raw1;int read_raw2;
    adc2_config_channel_atten( ADC2_CHANNEL_8, ADC_ATTEN_11db );
    esp_err_t r = adc2_get_raw( ADC2_CHANNEL_8, ADC_WIDTH_12Bit, &read_raw1);
    adc2_config_channel_atten( ADC2_CHANNEL_9, ADC_ATTEN_11db );
    esp_err_t r1 = adc2_get_raw( ADC2_CHANNEL_9, ADC_WIDTH_12Bit, &read_raw2); 
    ADC_V0[6]+=read_raw1;
    ADC_V0[7]+=read_raw2;
  }
  for (int i=0;i<8;i++){ADC_V0[i]=ADC_V0[i]/k;}
  if (ADC_V0[0]<small_R && ADC_V0[0]>big_R){if(state[0]==0){state[0]=1;SerialBT.print("Do0");}}
  else{if(state[0]==1){state[0]=0;SerialBT.print("000");}}
 
  if (ADC_V0[1]<small_R && ADC_V0[1]>big_R){if(state[1]==0){state[1]=1;SerialBT.print("Re0");}}
  else{if(state[1]==1){state[1]=0;SerialBT.print("000");}}
  
  if (ADC_V0[2]<small_R && ADC_V0[2]>big_R){if(state[2]==0){state[2]=1;SerialBT.print("Mi0");}}
  else{if(state[2]==1){state[2]=0;SerialBT.print("000");}}
  
  if (ADC_V0[3]<small_R && ADC_V0[3]>big_R){if(state[3]==0){state[3]=1;SerialBT.print("Fa0");}}
  else{if(state[3]==1){state[3]=0;SerialBT.print("000");}}
  
  if (ADC_V0[4]<small_R && ADC_V0[4]>big_R){if(state[4]==0){state[4]=1;SerialBT.print("So0");}}
  else{if(state[4]==1){state[4]=0;SerialBT.print("000");}}
 
  if (ADC_V0[5]<small_R && ADC_V0[5]>big_R){if(state[5]==0){state[5]=1;SerialBT.print("La0");}}
  else{if(state[5]==1){state[5]=0;SerialBT.print("000");}}
  
  if (ADC_V0[6]<small_R && ADC_V0[6]>big_R){if(state[6]==0){state[6]=1;SerialBT.print("Si0");}}
  else{if(state[6]==1){state[6]=0;SerialBT.print("000");}}
  
  if (ADC_V0[7]<small_R && ADC_V0[7]>big_R){if(state[7]==0){state[7]=1;SerialBT.print("Do1");}}
  else{if(state[7]==1){state[7]=0;SerialBT.print("000");}}
}
