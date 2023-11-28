#include <Arduino.h>
#include <IRremote.h>
// put function declarations here:

int RECV_PIN = 2;

decode_results res;
IRrecv irrecv(RECV_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&res)){
    Serial.print("Hec: ");
    Serial.println(res.value, HEX);
   
    Serial.print("DEC: ");
    Serial.println(res.value);
    Serial.println("--------------");
    irrecv.resume();
  }
  delay(500);
}

// put function definitions here:
