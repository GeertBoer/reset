#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"
#include "header_images/getcreative_header_image.h"

class GetCreative : public Prompt
{
private:
	String body;
public:
	GetCreative(String body);
	void print(Adafruit_Thermal *printer);
};

GetCreative::GetCreative(String body) {
	this->body = body;
}

void GetCreative::print(Adafruit_Thermal *printer) {
	printer->printBitmap(getcreative_header_image_width, getcreative_header_image_height, getcreative_header_image_data);

	printer->setFont('A');
	printer->setSize('M'); 
	printer->println(body);
}
