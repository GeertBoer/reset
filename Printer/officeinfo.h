#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"
#include "header_images/officeinfo_header_image.h"

class OfficeInfo : public Prompt
{
private:
	String body;
public:
	OfficeInfo(String body);
	void print(Adafruit_Thermal *printer);
};

OfficeInfo::OfficeInfo(String body) {
	this->body = body;
}

void OfficeInfo::print(Adafruit_Thermal *printer) {
	printer->printBitmap(officeinfo_header_image_width, officeinfo_header_image_height, officeinfo_header_image_data);

	printer->setFont('A');
	printer->setSize('M'); 
	printer->println(body);
}
