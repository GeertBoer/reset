#pragma once
#include "OOCSI.h"

class OOCSIPromptReciever
{
  private:
    bool gotMessage;
    OOCSI* oocsi;
  public:
    OOCSIPromptReciever();
    void Connect();
    void Check();
    static void cb();
};

OOCSIPromptReciever::OOCSIPromptReciever() {
  oocsi = new OOCSI();
  gotMessage = false;
}

void OOCSIPromptReciever::Connect() {
  Serial.println("bonjour");
  oocsi->connect("ESP-RESET", "oocsi.id.tue.nl", "tue-psk", "r3s3tr3s3t", this->cb);
  oocsi->subscribe("esp-testchannel");
  Serial.println("connected");
}

void OOCSIPromptReciever::cb() {
  Serial.println("came into oocsi callback!!");
}

void OOCSIPromptReciever::Check() {
  Serial.println("Entered check function");
  oocsi->check();
  Serial.println("Leaving check function");

  
}
