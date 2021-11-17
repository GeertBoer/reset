#pragma once
#include "Adafruit_Thermal.h"
#include "prompt.h"
#include "header_images/question_header_image.h"

class Question : public Prompt
{
private:
	String body;
public:
	Question(String body);
	void print(Adafruit_Thermal *printer);
	//~Question();
};

Question::Question(String body) {
	this->body = body;
}

void Question::print(Adafruit_Thermal *printer) {
	printer->printBitmap(question_header_image_width, question_header_image_height, question_header_image_data);

	printer->setFont('A');
	printer->setSize('M'); 
	printer->println(body);
}
