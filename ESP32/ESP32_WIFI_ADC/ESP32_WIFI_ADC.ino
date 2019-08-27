#include <WiFi.h>

int pinADC[]={36, 39, 34, 35, 32, 33, 25, 26, 27, 14, 12, 13, 4, 0, 2, 15};

const char* ssid     = "yourssid";

const char* password = "yourpasswd";

void setup()

{

    for (int i=0; i<16; i++)

        pinMode(pinADC[i], ANALOG);

    Serial.begin(115200);   

    WiFi.begin(ssid, password); //remove this line to get 16ch ADC

}

void loop()

{

    // only 6ch ADC is enabled if Wifi is begun

    for (int i=0; i<16; i++) {

        Serial.print("[");

        Serial.print(pinADC[i]);

        Serial.print("]");

        Serial.print(analogRead(pinADC[i]));

        Serial.print(" ");

    }

    Serial.println();

    delay(1000);

}
