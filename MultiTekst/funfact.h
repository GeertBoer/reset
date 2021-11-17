#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"
#include "header_images/didyouknow_header_image.h"

class FunFact : public Prompt
{
private:
	String fact;
public:
	FunFact(String fact);
	void print(Adafruit_Thermal *printer);
};

FunFact::FunFact(String fact) {
	this->fact = fact;
}

void FunFact::print(Adafruit_Thermal *printer) {
	printer->printBitmap(didyouknow_header_image_width, didyouknow_header_image_height, didyouknow_header_image_data);

	printer->setFont('A');
	printer->setSize('M'); 
	printer->println(fact);
}
