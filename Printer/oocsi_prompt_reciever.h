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
    void Connect();
    Prompt* Check();
};

OOCSIPromptReciever::OOCSIPromptReciever() {
  oocsi = new OOCSI();
}

void OOCSIPromptReciever::Connect() {
  Serial.println("connecting");
  oocsi->connect("ESP-RESET", "oocsi.id.tue.nl", "tue-psk", "r3s3tr3s3t");
  oocsi->subscribe("esp-testchannel");
  oocsi->setLogging(false);
  Serial.println("connected");
}

Prompt* OOCSIPromptReciever::Check() {
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
  }
  return NULL;
}
