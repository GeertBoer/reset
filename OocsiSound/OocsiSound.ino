#include "oocsisender.h"
OocsiSender* sender;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  delay(2000);
  Serial.println("Welkom dat je kijkt");
  sender = new OocsiSender("resetmobile", "r3s3tr3s3t");
}

int currentValue = 0;
int lastValue = 0;
int delta = 0;

const int average_size = 40;
int moving_average[average_size] = {0};
int pointer_average = 0;

unsigned long oldMillis = millis();
bool modee = false;
int highest = 0;
void loop() {
  // calculate moving average
  currentValue = analogRead(1);

  delta = currentValue - lastValue;
  if (delta < 0) {
    delta *= -1;
  }
  lastValue = currentValue;

  moving_average[pointer_average] = delta;

  pointer_average++;
  if (pointer_average >= average_size)
  {
    pointer_average = 0;
  }

  unsigned long total = 0;
  for (int i = 0; i < average_size; i++)
  {
    total += moving_average[i];
  }
  total = total / average_size;
  if (total > highest) {
    highest = total;
  }

  if (total > 800) {
    Serial.print("Sending prompt... ");
    Serial.println(total);
    sender->Send("There's more noise than usual \nat this time. Does that impact \nyour workflow?");
    delay(1000);

    for (int i = 0; i < average_size; i++)
    {
      moving_average[i] = 0;
    }   
  }     
        
  delay(40);
  sender->Ping();
  
  //  if (digitalRead(0) == LOW){
  //    delete sender;
  //    sender = new OocsiSender("Ziggo8303271","GcnwCsecry3c");
  //  } 
}       
