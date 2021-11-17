#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"

class Text : public Prompt {
public:
	void print(Adafruit_Thermal *printer);
};