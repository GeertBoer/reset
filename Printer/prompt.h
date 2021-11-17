#pragma once
#include "Adafruit_Thermal.h"

class Prompt {
public:
	virtual void print(Adafruit_Thermal *printer) = 0;
};