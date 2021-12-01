#pragma once
#include "OOCSI.h"

#include "question.h"
#include "funfact.h"
#include "achievement.h"
#include "prompt.h"
#include "getcreative.h"
#include "goal.h"
#include "joke.h"

class OOCSIPromptReciever
{
  private:
    OOCSI* oocsi;
  public:
    OOCSIPromptReciever();
    void Connect(const char* ssid, const char* password);
    Prompt* Check(Prompt* allPrompts[], const int aantalPrompts);

    void enableLogging();
    void disableLogging();
};

OOCSIPromptReciever::OOCSIPromptReciever() {
  oocsi = new OOCSI();
}

void OOCSIPromptReciever::Connect(const char* ssid, const char* password) {
  Serial.println("connecting");
  oocsi->connect("ESP-RESET", "oocsi.id.tue.nl", ssid, password);
  oocsi->subscribe("esp-testchannel");
  oocsi->setLogging(false);
  Serial.println("connected");
}

Prompt* OOCSIPromptReciever::Check(Prompt* allPrompts[], const int aantalPrompts) {
  if (oocsi->check())
  {
    Serial.println("pass check");
    if (oocsi->has("joke")) {
      return new Joke(oocsi->getString("joke", ""));
    }
    if (oocsi->has("question")) {
      return new Question(oocsi->getString("question", ""));
    }
    if (oocsi->has("funfact")) {
      return new FunFact(oocsi->getString("funfact", ""));
    }
    if (oocsi->has("getcreative")) {
      return new GetCreative(oocsi->getString("getcreative", ""));
    }
    if (oocsi->has("goal")) {
      return new Goal(oocsi->getString("goal", ""));
    }
    if (oocsi->has("achievement")) {
      return new Achievement(oocsi->getString("achievement", ""));
    }
    if (oocsi->has("getfromlist")) {
      int num = oocsi->getInt("getfromlist", -1);
      if (num < 0) {
        Serial.print("Err: num < 0!");
        return NULL;
      }
      if (num >= aantalPrompts) {
        Serial.print("Err: num >= aantalPrompts!");
        return NULL;
      }
      return allPrompts[num];
    }
  }
  return NULL;
}



void OOCSIPromptReciever::enableLogging() {
  oocsi->setLogging(true);
}


void OOCSIPromptReciever::disableLogging() {
  oocsi->setLogging(false);
}
