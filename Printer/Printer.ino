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
const int aantal_prompts = 113;

int spaceAfterPrint = 2; // 7 is best for casing V1

// END SETTINGS----------------------


OOCSIPromptReciever recv = OOCSIPromptReciever();
Adafruit_Thermal* printer = new Adafruit_Thermal(&Serial1);
Prompt* prompts[aantal_prompts];

void setup() {
  recv.Connect(wifi_ssid, wifi_pass);
  recv.enableLogging();

  Serial.begin(19200);
  Serial1.begin(19200);
  printer->begin();

  
  // Funfact
  prompts[0] = new FunFact("60% of our team said they have been using the experience cabins to relax this week. What do you to ground between meetings?");
  prompts[1] = new FunFact("You have had 4 walking meetings this week. Good job.");
  prompts[2] = new FunFact("You used the standing desk for an average of 4,5 hours a day last week.");
  prompts[3] = new FunFact("You drank an average of 6 glasses of water a day last week, this is more than the week before.");

  prompts[4] = new FunFact("Laughing is good for the heart and can increase blood flow by 20%.");
  prompts[5] = new FunFact("Always look on the bright side: being an optimist can help you live longer. ");
  prompts[6] = new FunFact("Exercise will give you more energy, even when you’re tired.");
  prompts[7] = new FunFact("Between 2000 and 2015, the average global life expectancy increased by five years. ");
  prompts[8] = new FunFact("Less than 1% of Americans ride their bike to work, while 50% of Copenhagen residents bike to work or school.");
  
  // Mental
  prompts[9] = new FunFact("Learning a new language or playing a musical instrument gives your brain a boost. ");
  prompts[10] = new FunFact("Feeling stressed? Read! It can lower levels of your cortisol, and other unhealthy stress hormones, by 68%. ");
  prompts[11] = new FunFact("Drinking coffee can reduce the risk of depression, especially for woman. ");
  prompts[12] = new FunFact("Smelling rosemary may increase alertness and improve memory so catch a whiff before a test or important meeting. ");
  prompts[13] = new FunFact("Writing in a journal can make you a happier person!");
  prompts[14] = new FunFact("Chewing gum makes you more alert, relieves stress and reduces anxiety levels. ");
  prompts[15] = new FunFact("Wawling outside can reduce negative thoughts and boost self-esteem.");
  
  // Food
  prompts[16] = new FunFact("Chocolate is good for your skin; its antioxidants improve blood flow and protect against UV damage. ");
  prompts[17] = new FunFact("Almonds, avocados and arugula (the triple A) can boost your sex drive and improve fertility. ");
  prompts[18] = new FunFact("Tea can lover risks of heart attack, certain cancers, type 2 Diabetes and Parkinson’s disease. Just make sure your tea isn’t too sweet! ");
  prompts[19] = new FunFact("Eating oatmeal provides a serotonin boost to calm the brain and improve your mood. ");
  prompts[20] = new FunFact("An apple a day does keep the doctor away. Apples can reduce levels of bad cholesterol to keep your heart healthy. ");
  prompts[21] = new FunFact("The amino acid found in eggs can help improve your reflexes. ");
  prompts[22] = new FunFact("Extra virgin olive oil is the healthiest fat on the planet. ");
  prompts[23] = new FunFact("Vitamin D is as important as calcium in determining bone health, and most people don’t get enough of it.");
  
  // Physical
  prompts[24] = new FunFact("The body has more than 650 muscles.");
  prompts[25] = new FunFact("Sleeping naked can help you burn more calories. ");
  prompts[26] = new FunFact("Walking at a fast pace for three hours or more at least once a week, you can reduce your risk of heart disease by up to 65%. ");
  prompts[27] = new FunFact("Regular activity can ease the severity and reduce the frequency of lower back pain. ");
  prompts[28] = new FunFact("Running is good for you. People who run 12-18 miles a week have a stronger immune system and can increase their bone mineral density. ");
  
  // Hydration
  prompts[29] = new FunFact("Drinking at least five glasses of water a day can reduce your chances of suffering from a heart attack by 40%.");
  prompts[30] = new FunFact("Dehydration can have a negative impact on your mood and energy levels. Drink enough water to ensure you’re always at your best. ");
  prompts[31] = new FunFact("Repeatedly using plastic water bottles can release chemicals into your water. Why not try a reusable bottle instead? It’s good for you and the planet. ");
  prompts[32] = new FunFact("The spinal disc core is comprised of a large volume of water therefore dehydration could lead to back pain. ");
  prompts[33] = new FunFact("Hydration is key for a good complexion. Drinking enough water also makes you less prone to wrinkles.");
  prompts[34] = new FunFact("Water can aid in weight loss because it helps to remove the by-products of fat and if consumed before a meal can make you more satisfied and eat less. ");
  prompts[35] = new FunFact("Your muscles and joints require water in order to stay energized, lubricated and healthy. ");
  prompts[36] = new FunFact("The blue light from your phone can mess with your circadian rhythm.");
  
  // Random facts
  prompts[37] = new FunFact("Breathing deeply in moments of stress, or anytime during the day, brings many benefits such as better circulation, decreased anxiety and reduced blood pressure. ");
  prompts[38] = new FunFact("The nose knows: it can remember 50,000 different scents. ");
  prompts[39] = new FunFact("Humans have 46 chromosomes, while peas have 14 and crayfish have 200. ");
  prompts[40] = new FunFact("Left-handed people are more likely to suffer from ADHD. ");
  prompts[41] = new FunFact("The eye muscles are the most active in the body, moving more than 100,000 times a day! ");
  prompts[42] = new FunFact("Humans can cough at 60 miles an hour and sneezes can be 100 miles an hour – which is faster than the average car! ");
  prompts[43] = new FunFact("Although bodies stop growing, noses and ears will not.");
  prompts[44] = new FunFact("The soles of your feet contain more sweat glands and nerve endings per square inch than anywhere else on your body. "); 

  // Creative
  // Complete the picture
  prompts[45] = new GetCreative("Complete the Picture: 'Happy as a calm' ");
  prompts[46] = new GetCreative("Complete the Picture: 'I can't get no satisfaction' ");
  prompts[47] = new GetCreative("Complete the Picture: 'Human nature' ");
  prompts[48] = new GetCreative("Complete the Picture: 'Here comes trouble' ");
  prompts[49] = new GetCreative("Complete the Picture: 'The art of noise' ");
  prompts[50] = new GetCreative("Complete the Picture: 'Happiness' ");
  
  // Look away from what you are creating
  prompts[51] = new GetCreative("Look away from what you are creating. \nRules: Draw an object without lifting your pencil from the paper, look at your handpalm and a maximum of 1 minute.' /nCategory: Love");
  prompts[52] = new GetCreative("Look away from what you are creating. \nRules: Draw an object without lifting your pencil from the paper, look at your handpalm and a maximum of 1 minute.' /nCategory: Busy");
  prompts[53] = new GetCreative("Look away from what you are creating. \nRules: Draw an object without lifting your pencil from the paper, look at your handpalm and a maximum of 1 minute.' /nCategory: Stress");
  prompts[54] = new GetCreative("Look away from what you are creating. \nRules: Draw an object without lifting your pencil from the paper, look at your handpalm and a maximum of 1 minute.' /nCategory: Food");
  prompts[55] = new GetCreative("Look away from what you are creating. \nRules: Draw an object without lifting your pencil from the paper, look at your handpalm and a maximum of 1 minute.' /nCategory: Gadget");
  prompts[56] = new GetCreative("Look away from what you are creating. \nRules: Draw an object without lifting your pencil from the paper, look at your handpalm and a maximum of 1 minute.' /nCategory: Music");
      
  prompts[57] = new GetCreative("Draw something you love!");
  prompts[58] = new GetCreative("Visualize: Think of your favorite animal!");
  prompts[59] = new GetCreative("Visualize: The wheel of life, rate 1");
  
  // Achievement
  prompts[60] = new Achievement("What was your highlight of today?");
  prompts[61] = new Achievement("What was your biggest success last week?");
  prompts[62] = new Achievement("Celebrate! What are you most proud off?");
  prompts[63] = new Achievement("Celebrate! What do you like best at work?");
  prompts[64] = new Achievement("Choose a colour to celebrate your happiness! ");
  prompts[65] = new Achievement("Create a dance move for your celebration! ");
  prompts[66] = new Achievement("Buy flowers today and celebrate life. ");
  prompts[67] = new Achievement("Tell a colleague of yours what you have achieved this month!");
  prompts[68] = new Achievement("Play your favorite track and dance on it. ");
  prompts[69] = new Achievement("What do you enjoy the most?");
  prompts[70] = new Achievement("Name or think about three important persons in your life. Why are they important? ");
  
 
  prompts[71] = new Achievement("What was your highlight of today?");
  prompts[72] = new Achievement("What was your biggest success last week?");
  prompts[73] = new Achievement("What are you most proud off?");
  prompts[74] = new Achievement("What do you like best at work?");
  
  // Goal
  prompts[75] = new Goal("What would you like to learn this week?");
  prompts[76] = new Goal("Quick retrospective: What made you move forward this week? What held you back? What should you do next?");
  prompts[77] = new Goal("Stretch your body: make it a habit to stretch every hour!");
  prompts[78] = new Goal("Breath: Take three deep breaths, observe what you feel and continue.");
  prompts[79] = new Goal("Nature: Go for a walk to get some fresh air.");
  prompts[80] = new Goal("Sound: Listen to your favorite song!");
  prompts[81] = new Goal("Get to know you colleagues better! Ask them a fun question!");
  
  // Random Questoion
  prompts[82] = new Question("How do you spend the traveling time between office and home?");
  prompts[83] = new Question("Do you use your traveling time to refocus and relax?");
  prompts[84] = new Question("Do you use you travel time to let go of unproductive thoughts to be fully present on arrival?");
  prompts[85] = new Question("How do you start your day when working from home?  ");
  prompts[86] = new Question("Do you focus your mind and body to begin your day distraction-free?");
  prompts[87] = new Question("How do you end your day working from home?");
  prompts[88] = new Question("Do you disengaged from work and find a place to be present when working from home?");
  prompts[89] = new Question("How do you keep your focus working from home?");
  prompts[90] = new Question("What do you do to calm your nerves for challenging tasks?");
  prompts[91] = new Question("How many breaks do you take during your working day?");
  prompts[92] = new Question("Are you fully present when someone is speaking?");
  prompts[93] = new Question("How do you stay calm before though talks?");
  prompts[94] = new Question("How many time did you stretch today? Try to keep track of this!");
  prompts[95] = new Question("How many glasses of water did you have today? Try to keep track of this!");
  prompts[96] = new Question("What did you have for lunch today? Try to keep track of this!");
  prompts[97] = new Question("Did you have a good night\'s sleep last night? Try to keep track of this!");
  prompts[98] = new Question("Who or what inspires you?");
  prompts[99] = new Question("Do you experience a relaxed kind of focus working from home, do recognize distractions?");
  
  // Games
  prompts[100] = new ImagePrompt("Visualize: The wheel of life, rate 1" , wheel_width, wheel_height, wheel_data);
  prompts[101] = new ImagePrompt("Sudoku", sudoku_width, sudoku_height, sudoku_data);
  prompts[102] = new ImagePrompt("How many words can you find?", boggle_width, boggle_height, boggle_data);
  prompts[103] = new ImagePrompt("Draw something!" , empty_width, empty_height, empty_data);
  prompts[104] = new ImagePrompt("Arrange the giving digits to make three 3 digits numbers that add up to 999", kwikmath_width, kwikmath_height, kwikmath_data);

  // Jokes
  prompts[105] = new Joke("Milou: \"What are you doing in the fridge?\" \n Lauren: \"The recipe said, rest in fridge for one hour.\"");
  prompts[106] = new Joke("Paul: \"I\'ve got problems with mathematics.\" \n Richard: \"Me too.\" \n George: \"Yeah, that makes four of us.\"");
  prompts[107] = new Joke("When I greeted my boss in the morning, he told me to have a good day. \n Who am I to argue? So I thanked him and went back home.");
  prompts[108] = new Joke("Me: \"Do you think it\'s strange to talk to yourself?\" \n Me: \"No.\" ");

  prompts[109] = new Goal("Get to know you colleagues better! Ask them a fun question!");
  prompts[110] = new Question("Do you experience a relaxed kind of focus working from home, do recognize distractions?");
  prompts[111] = new ImagePrompt("Finish the drawing:", finishdrawing1_width, finishdrawing1_height, finishdrawing1_data);
  prompts[112] = new ImagePrompt("Finish the drawing:", finishdrawing2_width, finishdrawing2_height, finishdrawing2_data);


  // hoogste prompt = maximaal aantal_prompts - 1

  printer->inverseOn();
  printer->setFont('A');
  printer->setSize('L');
  printer->println("RESET:CONNECTED");
  printer->feed(2);
  printer->inverseOff();
}


void loop() {
  Prompt* p = recv.Check(prompts, aantal_prompts);
  if (p != NULL)
  {
    printer->wake();
    Serial.println("4");
    p->print(printer);
    Serial.println("5");
    printer->feed(spaceAfterPrint);
    Serial.println("6");
    printer->sleep();
    delay(2000);
  }

//  delay(6000);
//  prompts[random(0, aantal_prompts)]->print(&printer);
//  printer.feed(7);
//  delay(300000); // 5 minutes
  delay(1500);
}
