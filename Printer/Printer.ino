#include "Adafruit_Thermal.h"
#include "question.h"
#include "funfact.h"
#include "achievement.h"
#include "prompt.h"
#include "getcreative.h"
#include "goal.h"
#include "prompt_images/wheel.h"
#include "image_prompt.h"
#include "joke.h"
#include "prompt_images/sudoku.h"
#include "prompt_images/boggle.h"
#include "prompt_images/empty.h"
#include "prompt_images/finishdrawing1.h"
#include "prompt_images/finishdrawing2.h"
#include "prompt_images/kwikmath.h"
#include "oocsi_prompt_reciever.h"


// SETTINGS: ------------------------

const char* wifi_ssid = "tue-psk";
const char* wifi_pass = "r3s3tr3s3t";
const int aantal_prompts = 47;

int spaceAfterPrint = 2; // 7 is best for casing V1

// END SETTINGS----------------------


OOCSIPromptReciever recv = OOCSIPromptReciever();
Adafruit_Thermal printer(&Serial1);
Prompt* prompts[aantal_prompts];

void setup() {
  recv.Connect(wifi_ssid, wifi_pass);

  Serial.begin(19200);
  Serial1.begin(19200);
  printer.begin();

  prompts[0] = new Achievement("What was your highlight of today?");
  prompts[1] = new Achievement("What was your biggest success last week?");
  prompts[2] = new Achievement("What are you most proud off?");
  prompts[3] = new Achievement("What do you like best at work?");
  prompts[4] = new FunFact("60% of our team said they have been using the experience cabins to relax this week. What do you to ground between meetings?");
  prompts[5] = new GetCreative("Draw something you love!");
  prompts[6] = new Goal("What would you like to learn this week?");
  prompts[7] = new Goal("Quick retrospective: What made you move forward this week? What held you back? What should you do next?");
  prompts[8] = new Goal("Stretch your body: make it a habit to stretch every hour!");
  prompts[9] = new Goal("Breath: Take three deep breaths, observe what you feel and continue.");
  prompts[10] = new Goal("Nature: Go for a walk to get some fresh air.");
  prompts[11] = new Goal("Sound: Listen to your favorite song!");
  prompts[12] = new Question("How do you spend the traveling time between office and home?");
  prompts[13] = new Question("Do you use your traveling time to refocus and relax?");
  prompts[14] = new Question("Do you use you travel time to let go of unproductive thoughts to be fully present on arrival?");
  prompts[15] = new Question("How do you start your day when working from home?  ");
  prompts[16] = new Question("Do you focus your mind and body to begin your day distraction-free?");
  prompts[17] = new Question("How do you end your day working from home?");
  prompts[18] = new Question("Do you disengaged from work and find a place to be present when working from home?");
  prompts[19] = new Question("How do you keep your focus working from home?");
  prompts[20] = new Question("What do you do to calm your nerves for challenging tasks?");
  prompts[21] = new Question("How many breaks do you take during your working day?");
  prompts[22] = new Question("Are you fully present when someone is speaking?");
  prompts[23] = new Question("How do you stay calm before though talks?");
  prompts[24] = new Question("How many time did you stretch today? Try to keep track of this!");
  prompts[25] = new Question("How many glasses of water did you have today? Try to keep track of this!");
  prompts[26] = new Question("What did you have for lunch today? Try to keep track of this!");
  prompts[27] = new Question("Did you have a good night\'s sleep last night? Try to keep track of this!");
  prompts[28] = new Question("Who or what inspires you?");
  prompts[29] = new ImagePrompt("Visualize: The wheel of life, rate 1" , wheel_width, wheel_height, wheel_data);
  prompts[30] = new ImagePrompt("Sudoku", sudoku_width, sudoku_height, sudoku_data);
  prompts[31] = new ImagePrompt("How many words can you find?", boggle_width, boggle_height, boggle_data);
  prompts[32] = new ImagePrompt("Draw something!" , empty_width, empty_height, empty_data);
  prompts[33] = new ImagePrompt("Arrange the giving digits to make three 3 digits numbers that add up to 999", kwikmath_width, kwikmath_height, kwikmath_data);
  prompts[34] = new FunFact("You have had 4 walking meetings this week. Good job.");
  prompts[35] = new FunFact("You used the standing desk for an average of 4,5 hours a day last week.");
  prompts[36] = new FunFact("You drank an average of 6 glasses of water a day last week, this is more than the week before.");
  prompts[37] = new GetCreative("Visualize: Think of your favorite animal!");
  prompts[38] = new GetCreative("Visualize: The wheel of life, rate 1");
  prompts[39] = new Joke("Milou: \"What are you doing in the fridge?\" \n Lauren: \"The recipe said, rest in fridge for one hour.\"");
  prompts[40] = new Joke("Paul: \"I\'ve got problems with mathematics.\" \n Richard: \"Me too.\" \n George: \"Yeah, that makes four of us.\"");
  prompts[41] = new Joke("When I greeted my boss in the morning, he told me to have a good day. \n Who am I to argue? So I thanked him and went back home.");
  prompts[42] = new Joke("Me: \"Do you think it\'s strange to talk to yourself?\" \n Me: \"No.\" ");
  prompts[43] = new Goal("Get to know you colleagues better! Ask them a fun question!");
  prompts[44] = new Question("Do you experience a relaxed kind of focus working from home, do recognize distractions?");
  prompts[45] = new ImagePrompt("Finish the drawing:", finishdrawing1_width, finishdrawing1_height, finishdrawing1_data);
  prompts[46] = new ImagePrompt("Finish the drawing:", finishdrawing2_width, finishdrawing2_height, finishdrawing2_data);

  // hoogste prompt = maximaal aantal_prompts - 1

  printer.inverseOn();
  printer.setFont('A');
  printer.setSize('L');
  printer.println("RESET:CONNECTED");
  printer.feed(2);
  printer.inverseOff();

}


void loop() {
  Prompt* p = recv.Check(prompts, aantal_prompts);
  if (p != NULL)
  {
    p->print(&printer);
    printer.feed(spaceAfterPrint);
    delay(2000);
  }

//  delay(6000);
//  prompts[random(0, aantal_prompts)]->print(&printer);
//  printer.feed(7);
//  delay(300000); // 5 minutes
  delay(50);
}
