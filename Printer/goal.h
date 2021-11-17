#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"
#include "header_images/goal_header_image.h"

class Goal : public Prompt
{
private:
	String head;
	String body;
	bool hasHead = false;
public:
	Goal(String body);
	Goal(String head, String body);
	void print(Adafruit_Thermal *printer);
};

Goal::Goal(String body) {
	this->body = body;
	hasHead = false;
}

Goal::Goal(String head, String body) {
	this->head = head;
	this->body = body;
	hasHead = true;
}

void Goal::print(Adafruit_Thermal *printer) {
	printer->printBitmap(goal_header_image_width, goal_header_image_height, goal_header_image_data);

	printer->setFont('A');
	printer->setSize('M'); 
	printer->println(body);
}
