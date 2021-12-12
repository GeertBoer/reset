#include "oocsisender.h"
OocsiSender* sender;

void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(115200);
  Serial.println();
  delay(2000);
  Serial.println("Welkom dat je kijkt");
  sender = new OocsiSender("Beerenboom","SQAAVCAA");
  
}

int currentValue = 0;
int lastValue = 0;
int delta = 0;

const int average_size = 40;
int moving_average[average_size] = {0};
int pointer_average = 0;

unsigned long oldMillis = millis();
bool modee = false;
void loop() {
  Serial.println("sending msg..");
  sender->SendInt(analogRead(1));
  delay(40);
//  // calculate moving average
//  currentValue = analogRead(1);
//
//  delta = currentValue - lastValue;
//  if (delta < 0) {
//    delta *= -1;
//  }
//  lastValue = currentValue;
//
//  moving_average[pointer_average] = delta;
//
//  pointer_average++;
//  if (pointer_average >= average_size)
//  {
//    pointer_average = 0;
//  }
//
//  unsigned long total = 0;
//  for (int i = 0; i < average_size; i++)
//  {
//    total += moving_average[i];
//  }
//
//  total = total / average_size;
//  Serial.println(total);
//  // done with moving average
//
//  // send total over oocsi
//  if (total > 1000) {
//    
//    //    Serial.println("HAII");
//    for (int i = 0; i < average_size; i++)
//    {
//      moving_average[i] = 0;
//    }
//    delay(1000);
//  }
//
//  delay(150);
//
//  digitalWrite(1, modee);
//  modee = !modee;
//  delay(100);
}
