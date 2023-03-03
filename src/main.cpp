#include <Arduino.h>

byte bmsData = 0x0;

//The pin labeled RX on the bluetooth adaptor connects to PA3
//The pin labeled TX on the bluetooth adaptor connects to PA2
//The data pin next to the positive wire on the BMS connects to PA10
//The data pin next to the negative wire on the BMS connects to PA9
//The RX pin on the ESP connects to PB10
//The TX pin on the ESP connects to PB11

void setup() {
  Serial1.begin(9600); //BMS
  Serial2.begin(9600); //Bluetooth
  Serial3.begin(9600); //ESP
}

void loop() {
  if (Serial2.available()) {
    Serial1.write(Serial2.read()); //Forward all requests from the Bluetooth dongle to the BMS
  }

  if (Serial1.available()) { //Forward all responses from the BMS to the Bluetooth dongle and the ESP
    bmsData = Serial1.read();
    Serial3.write(bmsData); //ESP
    Serial2.write(bmsData); //Bluetooth
  }

  if (Serial3.available()) {
    Serial1.write(Serial3.read()); //Forward all requests from the ESP to the BMS
  }
}