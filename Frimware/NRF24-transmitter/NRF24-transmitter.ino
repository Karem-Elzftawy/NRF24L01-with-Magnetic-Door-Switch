#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);
//RF24 radio(2,15);

const byte address[6] = "00001";

const int sensor = 2; 
int state; // 0 close - 1 open Switch

const char text[] = "nrftest";

void setup() {
  pinMode(sensor, INPUT_PULLUP);
  Serial.begin(9600);
  delay(1000);
  Serial.println(F("RF24/Simple Transmit data Test"));
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void loop() {
  state = digitalRead(sensor);
  if (state == LOW)
  {
  radio.write(&text, sizeof(text));
  Serial.println("Transmitted!");
  delay(1000);  
  }
}
