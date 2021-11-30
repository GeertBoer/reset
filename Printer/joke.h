#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"
#include "header_images/joke_header_image.h"

class Joke : public Prompt
{
  private:
    String head;
    String body;
    bool hasHead = false;
  public:
    Joke(String body);
    Joke(String head, String body);
    void print(Adafruit_Thermal *printer);
};

Joke::Joke(String body) {
  this->body = body;
  hasHead = false;
}

Joke::Joke(String head, String body) {
  this->head = head;
  this->body = body;
  hasHead = true;
}

void Joke::print(Adafruit_Thermal *printer) {
  printer->printBitmap(joke_header_image_width, joke_header_image_height, joke_header_image_data);

  if (hasHead) {
    printer->setFont('A');
    printer->setSize('M');
    printer->inverseOn();
    printer->println(head);
    printer->inverseOff();
  }

  printer->setFont('A');
  printer->setSize('M');
  printer->println(body);
}
