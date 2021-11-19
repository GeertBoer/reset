#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"

class ImagePrompt : public Prompt
{
  private:
    int width;
    int height;
    const uint8_t* data;
    String head;
  public:
    ImagePrompt(int width, int height, const uint8_t* data);
    ImagePrompt(String head, int width, int height, const uint8_t* data);
    void print(Adafruit_Thermal *printer);
};

ImagePrompt::ImagePrompt(int width, int height, const uint8_t* data) {
  this->width = width;
  this->height = height;
  this->data = data;
}

ImagePrompt::ImagePrompt(String head, int width, int height, const uint8_t* data) {
  this->width = width;
  this->height = height;
  this->data = data;
  this->head = head;
}

void ImagePrompt::print(Adafruit_Thermal *printer) {
  if (head.length() > 0) {
    printer->inverseOn();
    printer->setFont('A');
    printer->setSize('L');
    printer->println(head);
    printer->inverseOff();
  }
  printer->printBitmap(width, height, data);
}
