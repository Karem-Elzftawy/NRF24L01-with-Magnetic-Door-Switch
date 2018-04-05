#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);
//RF24 radio(2,15);

const int LED = 2; 
const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  //ESP.wdtDisable();
  Serial.begin(9600);
  delay(1000);
  Serial.println(F("RF24/Simple Receive data Test"));
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {
  char text[32] = "";
  
  if (radio.available()) {
    Serial.println("Received!");
    radio.read(&text, sizeof(text));
    String transData = String(text);
    if (transData == "nrftest") {
      Serial.print("Data received = ");
      Serial.println(transData);
        //tone(buzzer, 1000);
        //delay(500);
        //noTone(buzzer);
        digitalWrite(LED, HIGH);
        delay(500);
        //digitalWrite(LED, LOW);
      }    
  }
  else {
  digitalWrite(LED, LOW);}
}
