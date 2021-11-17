#pragma once
#include "Adafruit_Thermal.h"
#include "header_images/achievement_header_image.h"
#include "prompt.h"

class Achievement : public Prompt
{
private:
	String body;
public:
	Achievement(String body);
	void print(Adafruit_Thermal *printer);
	//~Question();
};

Achievement::Achievement(String body) {
	this->body = body;
}

void Achievement::print(Adafruit_Thermal *printer) {
	printer->printBitmap(achievement_header_image_width, achievement_header_image_height, achievement_header_image_data);

	printer->setSize('M'); 
	printer->println(body);
}
