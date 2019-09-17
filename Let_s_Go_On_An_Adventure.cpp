// Title:      Let's go on an adventure!
// Program by: Giancarlo David

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

// Function prototypes
void asteriskLine();
void diningHall();
void south();
bool rng(int, int);
void companionComplain(bool[], string[]);
void michaelSound();
void rebekahSound();
void gianSound();
void kennySound();
void kevinSound();
void melissaSound();
void victoriaSound();
void resetGo(bool[]);
void oddsToGo(bool[], int &, string[]);
void oddsToGoFinals(bool companions[], int &count, string names[]);
void night1(bool[], string[]);
void finalsWeek(bool[], string[]);

// Function to check which companions will come with you
void numCheck(int guess, bool companions[], int &count, int odds, string names[])
{
   // Random number generator and set randNum equal to the number generated
   srand(time(0));
   int randNum = rand() % odds + 1;

   // Display user's guess and what randNum is set equal to
   cout << "\nYour guess was " << guess << " " << names[count] << "'s number was " << randNum << endl;
   cin.get();

   // If statement for when user's guess equals randNum
   if (guess == randNum)
   {
      // Display who is now accompanying the user
      cout << "You guessed right! " << names[count] << " is now coming on the adventure with you!" << endl << endl;
      companions[count] = true;

      // Update count
      count++;
   }

   // Else statement for when user's guess does not equal randNum
   else
   {
      // Display who is not accompanying the user
      cout << "You guessed wrong! " << names[count] << " is not coming with you." << endl << endl;
      companions[count] = false;

      // Update count
      count++;
   }
} // End function numCheck


int main()
{
   // Set and define variables
   string username;
   const int numOfCompanions = 8;
   bool companions[numOfCompanions] = { 0,1,1,1 };
   string names[numOfCompanions] = { "Null", "Michael", "Rebekah", "Gian", "Kenny", "Kevin", "Melissa", "Victoria" };
   int count = 4;
   int odds;
   int guess;

   // Display centered title
   cout << setw(55) << "***Let's go on an adventure!***" << endl << endl;

   // Display prompt for user's name, and store user's name in username
   cout << "Please enter your name\n";
   getline(cin, username);
   cout << "\nWelcome " << username << ", the adventure simulator is about to begin." << endl;
   cin.get();
   cout << endl;

   // Call function asteriskLine for aesthetics
   asteriskLine();

   // Display the setting the user is in
   cout << "You are currently in your room after a long day of school." << endl;
   cout << "It is currrently 6 P.M. and the group chat has just decided to get dinner\nand you notice your stomach rumble." << endl;
   cout << "You decide to go to the dining hall in hopes of getting a delicious meal." << endl;
   
   // Call function asteriskLine for aesthetics
   asteriskLine();

   cin.get();
   cout << endl;
   
   // Call function diningHall to display dining options
   diningHall();
   
   // Call function asteriskLine for aesthetics
   asteriskLine();
   
   // Display more of storyline
   cout << "You eat with your friends Michael, Melissa, Kenny, Victoria, \nKevin, Rebekah, and Gian." << endl;
   cout << "Conversation flows as you all eat your meals." << endl;
   cin.get();
   cout << "Once everyone is done, you all put up your dishes \nand head over to residence hall south" << endl;
   cout << "in order to commence friendshiping." << endl;
   cin.get();

   // Call function south to simulate residence hall south
   south();

   // Call function oddsToGo to decide which companions will accompany the user
   oddsToGo(companions, count, names);
   
   // Call function asteriskLine for aesthetics
   asteriskLine();

   // Call function night1 to simulate the first night of adventure
   night1(companions, names);

   // Call function asteriskLine for aesthetics
   asteriskLine();
   
   // Display time skip
   cout << "*Finals week comes and goes*" << endl;
   cin.get();

   // Call function asteriskLine for aesthetics
   asteriskLine();

   // Display advancement of the storyline
   cout << "With finals done, " << endl;
   cout << "you decide it's time for one more adventure" << endl;
   cout << "before everyone leaves for winter break" << endl;
   cin.get();
   cout << "You text the group chat seeing who might want to eat dinner." << endl;
   cin.get();
   cout << "Everyone responds that they are going to head down" << endl;
   cout << "so you head down to meet up with them." << endl;
   cin.get();
   
   // Call function asteriskLine for aesthetics
   asteriskLine();

   // Call function diningHall to display dining options
   diningHall();

   // Call function asteriskLine for aesthetics
   asteriskLine();

   // Display advancement of storyline
   cout << "You eat with your friends Michael, Melissa, Kenny, Victoria, \nKevin, Rebekah, and Gian." << endl;
   cout << "Conversation flows as you all eat your meals." << endl;
   cin.get();
   cout << "When everyone is finished you all stay there talking." << endl;
   cout << "You then decide to bring up wanting to go on an adventure." << endl;
   cin.get();
   cout << "Michael, Rebekah, and Gian are up for the adventure. \nWhile the others are kind of on the fence." << endl;
   cin.get();
   cout << "You decide to play \"What are the odds?\" \nwith each person to see if you can get them to come." << endl << endl;

   // Call function resetGo to reset companions to not accompany the user
   resetGo(companions);

   // Call function oddsToGoFinals to decide which companions will accompany the user
   oddsToGoFinals(companions, count, names);

   // Call function asteriskLine for aesthetics
   asteriskLine();

   // Call function finalsWeek to simulate the final adventure
   finalsWeek(companions, names);

   // Call function asteriskLine for aesthetics
   asteriskLine();
   cin.get();

   // Display the ending message
   cout << "**Simulation over**" << endl;
   cin.get();
   cout << "Thank you " << username << endl;
   cin.get();
   cout << "\tfor going through the simulator." << endl;
   cin.get();
   cout << "\tHopefully your experience was thoroughly enjoyable." << endl;
   cin.get();
   cout << "\tUntil next time!" << endl;
   asteriskLine();

   system("pause");
   return 0;
} // End function main

void asteriskLine()
{
   // For loop to display a line of asterisks across the console
   for (int count = 0; count < 80; count++)
   {
      cout << "*";
   }
}

void diningHall()
{
   // Set and define variables
   int choice;
   bool invalid = true;
   bool chicken;
   int sauce;

   // Display prompt and menu options
   cout << "You arrive at the dining hall and notice there are 4 stations to choose from.";
   cout << "\nEnter the number of the station that you want to choose" << endl << endl;
   cout << "1. West Side Grill" << endl;
   cout << "2. The Deli" << endl;
   cout << "3. Burger Station" << endl;
   cout << "4. The Pasta Bar" << endl << endl;

   // Get user input for choice
   cin >> choice;

   // While loop while user doesn't choose valid option
   while (invalid == true)
   {
      // Switch statement for variable choice
      switch (choice)
      {
      // Case for when choice equals 1
      case 1:
      {
         // Call funciton asteriskLine for aesthetics
         asteriskLine();

         // Display what happens when you choose option 1
         cout << "You see some nasty broccoli and make comment about it." << endl;
         cout << "You don't touch the broccoli but instead get the other food in the station." << endl;
         cout << "On your way to the table, the broccoli lady runs to you and says" << endl;
         cout << "\"I know you wanted some of these\" as she hands you a bowl of broccoli\nand stares you down" << endl;
         
         // Call function asterisk line for aesthetics
         asteriskLine();
         cin.get();

         // Set invalid to false in order to break while loop
         invalid = false;

         // Break from switch statement
         break;
      }
      // Case for when choice equals 2
      case 2:
      {
         // Call function asteriskLine for aesthetics
         asteriskLine();

         // Display what happens when user chooses option 2
         cout << "You see no other good options so you force yourself to make a sandwich to eat." << endl;
         cout << "After using the panini press, you end up with a mediocre sandwich." << endl;

         // Display asteriskLine for aesthetics
         asteriskLine();
         cin.get();

         // Set invalid to false in order to break from while loop
         invalid = false;

         // Break from switch statement
         break;
      }
      // Case for when choice equals 3
      case 3:
      {
         // Call function asteriskLine for aesthetics
         asteriskLine();

         // Display what happens when user chooses option 3
         cout << "You choose to get a burger because you think \"What could go wrong?\"" << endl;
         cout << "It's after you make the burger that you realize that you have\nmade a huge mistake." << endl;
         cout << "The burger is burnt and dry, and you hate yourself for every bite you take." << endl;

         // Call function asteriskLine for aesthetics
         asteriskLine();
         cin.get();

         // Set invalid to false in order to break from while loop
         invalid = false;

         // Break from switch statement
         break;
      }
      case 4:
      {
         // Call asteriskLine for aesthetics
         asteriskLine();

         // Display prompt for Richard to ask you for chicken and get user input for chicken
         cout << "You gather the vegetables that you want in your pasta,\nand give Richard your bowl." << endl;
         cout << "\nRichard asks if you want chicken\n1. Yes\n0. No" << endl;
         cin >> chicken;

         // Input validation for chicken (Causes infinite loop for some reason)
         while (chicken != 0 && chicken != 1)
         {
            cout << "It's a yes or no question, or in this case 1 or 0, so pick 1 or 0." << endl;
            cin >> chicken;
         }

         // If statement for when user wants chicken
         if (chicken == true)
         {
            // Display message saying Richard puts chicken in user's pan
            cout << "\nRichard helps you out with those gains by\nputting in a little protein into your pan." << endl;
            cin.get();
         }

         // Else if statement for when the user doesn't want chicken
         else if (chicken == false)
         {
            // Display message about depressed chicken
            cout << "\nThe chicken contemplates why you don't want to eat it\nand cries in its containter." << endl;
            cin.get();
         }

         // Display prompt for Richard asking user for sauce and get user input for sauce
         cout << "\nWhile cooking, Richard puts in some angel dust to satisfy your itch\nand asks what sauce you want." << endl;
         cout << "Pick your sauce" << endl;
         cout << "1. Alfredo" << endl;
         cout << "2. Marinara" << endl;
         cout << "3. The SAUCE" << endl;
         cin >> sauce;

         // Set pickSauce equal to false
         bool pickSauce = false;

         // While loop for while pickSauce is equal to false
         while (pickSauce == false)
         {
            // Switch statement for sauce
            switch (sauce)
            {
            // Case for when user picks alfredo
            case 1:
            {
               // Displays how basic the user is
               cout << "You stick with one of the basic sauces and your pasta turns out alright." << endl;

               // Set pickSauce to true in order to break out of while loop
               pickSauce = true;

               // Break from switch statement
               break;
            }
            // Case for when user picks marinara
            case 2:
            {
               // Display message on how basic the user is
               cout << "You stick with one of the basic sauces and your pasta turns out alright." << endl;

               // Set pickSauce to true to break out of while loop
               pickSauce = true;

               // Break from switch statement
               break;
            }
            // Case for when user picks the SAUCE
            case 3:
            {
               // Display message for picking the best sauce, the SAUCE
               cout << "You picked the legendary SAUCE and your tastebuds are delighted\nthat you made such a choice." << endl;

               // Set pickSauce to true to break out of while loop
               pickSauce = true;

               // Break from switch statement
               break;
            }
            // Default statement for when user inputs an invalid number
            default:
            {
               // Display message saying user wants some sauce
               cout << "You know deep down you want some sauce on your pasta, now choose a legitimate response." << endl;

               // Get user input for sauce
               cin >> sauce;

               // Break from switch statement
               break;
            }
            }
         }

         // Call function asteriskLine for aesthetics
         asteriskLine();

         // Set invalid to false to break from while loop
         invalid = false;

         //Break from switch statement
         break;
      }
      default:
      {
         // Call asteriskLine for aesthetics
         asteriskLine();

         // Display error message if user doesn't pick valid option, get user input for choice
         cout << "Your stomach rumbles, you definitely need some food." << endl;
         cout << "Enter the number of the station that you want to choose";
         cin >> choice;

         // Break from switch statement
         break;
      }
      }
      cin.get();
      cin.get();
      cout << endl << endl;
   }
} // End function diningHall

void south()
{
   // Call function asteriskLine
   asteriskLine();

   // Display continuation of storyline
   cout << "While at south, you all end up doing homework." << endl;
   cout << "Michael, Melissa, and Victoria are working on calculus." << endl;
   cout << "Kenny and Gian are working on chemistry." << endl;
   cout << "Kevin and Rebekah are working on computer science." << endl;
   cin.get();
   cout << "*A few hours pass*" << endl;
   cin.get();

   // Display despair
   cout << "After a few hours of homework, the room has turned into chaos." << endl;
   cin.get();
   cout << "Michael, Melissa, and Victoria are now throwing hot tamales at each other.";
   cin.get();
   cout << "Gian is shouting as he gets every ALEKS question wrong.";
   cin.get();
   cout << "Kenny is trying to help Rebekah and Kevin with their homework.";
   cin.get();
   cout << "Kevin has now given up at this point and lies down listening to music.";
   cin.get();
   cout << "Rebekah struggles to understand Kenny's explanation for the program." << endl;
   cin.get();
   cout << "Seeing this, you decide it's time for a break and ask \n\"Who is up for an adventure?\"" << endl;
   cin.get();
   cout << "Michael, Rebekah, and Gian are up for the adventure. \nWhile the others are kind of on the fence." << endl;
   cin.get();
   cout << "You decide to play \"What are the odds?\" \nwith each person to see if you can get them to come." << endl << endl;
}// End function south

bool rng(int optionOdds, int pickedOdds)
{
   // Random number generator, set randNum equal to a random number using the odds
   srand(time(0));
   int randNum = rand() % optionOdds + 1;

   // If statement for when pickedOdds is equal to randNum
   if (pickedOdds == randNum)
   {
      // Return true
      return true;
   }
   // Else statement for wen pickedOdds is not equal to randNum
   else
   {
      // Return false
      return false;
   }
}

void companionComplain(bool companion[], string name[])
{
   // For loop that goes through every possible companion
   for (int count = 0; count < 8; count++)
   {
      // If statement for if companion is accompanying the user
      if (companion[count] == true)
      {
         // Switch statement for count
         switch(count)
         {
         // Case for when count equals 1
         case 1: michaelSound();
            break;
         // Case for when count equals 2
         case 2: rebekahSound();
            break;
         // Case for when count equals 3
         case 3: gianSound();
            break;
         // Case for when count equals 4
         case 4: kennySound();
            break;
         // Case for when count equals 5
         case 5: kevinSound();
            break;
         // Case for when count equals 6
         case 6: melissaSound();
            break;
         // Case for when count equals 7
         case 7: victoriaSound();
            break;
         }
      }
      
      // Else statement if companion[count] is not accompanying user
      else
      {
         // Continues to the next iteration of the for loop
         continue;
      }
   }
}// End function companionComplain

void michaelSound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;

   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Michael sighs and looks cranky (As usual)" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Michael squints at you" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Michael starts singing 'Bohemian Rhapsody'" << endl;
      break;
   }
}// End function michaelSound

void rebekahSound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;
   
   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Rebekah compulsively fills the silence with talking" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Rebekah says \"Isn't this FANTABULAMAZING\"" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Rebekah talks about being Mormon" << endl;
      break;
   }
}// End function rebekahSound

void gianSound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;

   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Gian's eyebrows twitch" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Gian says \"Don't worry about it\"" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Gian talks about Melee" << endl;
      break;
   }
}// End function gianSound

void kennySound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;

   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Kenny laughs and says \"Feelsbadman\"" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Kenny says \"Same\"" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Kenny says \"Ma heart\"" << endl;
      break;
   }
} // End function kennySound

void kevinSound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;

   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Kevin groans and says \"Not like this\"" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Kevin stares at you" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Kevin puts his earbuds in" << endl;
      break;
   }
}// End function kevinSound

void melissaSound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;

   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Melissa purrs" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Melissa continues to watch anime" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Melissa looks ready to practice jiu jitsu on you" << endl;
      break;
   }
}// End function melissaSound

void victoriaSound()
{
   // Random number generator, set rng equal to the random number generated
   srand(time(0));
   int rng = rand() % 3 + 1;

   // Switch statement for rng
   switch (rng)
   {
   // Case for when rng equals 1
   case 1: cout << "Victoria makes a pun" << endl;
      break;
   // Case for when rng equals 2
   case 2: cout << "Victoria makes random movements" << endl;
      break;
   // Case for when rng equals 3
   case 3: cout << "Victoria talks about science" << endl;
      break;
   }
}// End function victoriaSound

void resetGo(bool companions[])
{
   // For loop to set companions to not accompany user
   for (int count = 4; count < 8; count++)
   {
      companions[count] = false;
   }
}// End function resetGo

void oddsToGo(bool companions[], int &count, string names[])
{
   // Define variables
   int odds;
   int guess;

   // Display prompt for Kenny's "What are the odds?" game, get user input for guess, set odds equal to 2
   cout << "Kenny says there is a 1 in 2 chance that he would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 2;

   // Call function numCheck to check if guess is correct
   numCheck(guess, companions, count, odds, names);

   // Display prompt for Kevin's "What are the odds?" game, get user input for guess, set odds equal to 3
   cout << "Kevin says there is a 1 in 3 chance that he would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 3;

   // Call function numCheck to check if guess is correct
   numCheck(guess, companions, count, odds, names);

   // Display prompt for Melissa's "What are the odds?" game, get user input for guess, set odds equal to 5
   cout << "Melissa says there is a 1 in 50 chance that she would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 50;

   // Call function numCheck to check if guess is correct
   numCheck(guess, companions, count, odds, names);

   // Display prompt for Victoria's "What are the odds?" game, get user input for guess, set odds equal to 10
   cout << "Victoria says there is a 1 in 10 chance that she would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 10;

   // Call function numCheck to check if guess is correct
   numCheck(guess, companions, count, odds, names);
   
   // Display which companions are accompanying the user
   cout << "Great! ";
   for (int count = 0; count < 8; count++)
   {
      if (companions[count] == true)
      {
         cout << names[count] << " ";
      }
   }

   // Set count equal to 4 for future use
   count = 4;
   cout << "\nare all coming with you on the adventure!" << endl;
   cin.get();
}// End function oddsToGo

// Need to comment from here down
void oddsToGoFinals(bool companions[], int &count, string names[])
{
   int odds;
   int guess;
   cout << "Kenny says there is a 1 in 2 chance that he would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 2;
   numCheck(guess, companions, count, odds, names);

   cout << "Kevin says there is a 1 in 2 chance that he would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 2;
   numCheck(guess, companions, count, odds, names);

   cout << "Melissa says there is a 1 in 10 chance that she would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 10;
   numCheck(guess, companions, count, odds, names);

   cout << "Victoria says there is a 1 in 5 chance that she would go." << endl;
   cout << "What will your guess be?: ";
   cin >> guess;
   odds = 5;
   numCheck(guess, companions, count, odds, names);

   cout << "Great! ";
   for (int count = 0; count < 8; count++)
   {
      if (companions[count] == true)
      {
         cout << names[count] << " ";
      }
   }
   cout << "\nare all coming with you on the adventure!" << endl;
   cin.get();
}

void night1(bool companions[], string name[])
{
   int option;
   int odds;
   bool escaped = false;

   cout << "Night 1:" << endl;
   cin.get();
   cout << "The sky is clear, the night is chilly and you all decide \nto go to the soccer fields.";
   cin.get();
   cout << "You get there and realize that the fence is closed so you \ncan't go onto the soccer fields.";
   cin.get();
   cout << "There's a covered area with picnic tables, your group decides to head there.";
   cin.get();
   cout << "\n*Two hours pass*" << endl;
   cin.get();
   cout << "It starts pouring rain!" << endl;
   cin.get();
   cout << "You guys are cold but are stuck under the cover \nbecause of the rain." << endl;
   cout << "Three options are left: " << endl;
   cout << "1. Look for an umbrella (1 in 5 chance of finding one)" << endl;
   cout << "2. Wait until the rain stops (1 in 10 chance of happening)" << endl;
   cout << "3. Sprint home (1 in 2 chance of everyone agreeing)" << endl << endl;
   
   while (escaped != true)
   {
      cout << "\nWhat option will you choose? ";
      cin >> option;
      cout << "Pick your odds: ";
      cin >> odds;

      switch (option)
      {
      case 1:
      {
         if (rng(5, odds) == true)
         {
            cout << "You found an umbrella!" << endl;
            cout << "You walk home shielded from the rain." << endl;
            cin.get();
            escaped = true;
         }
         else
         {
            cout << "You did not find an umbrella." << endl;
            companionComplain(companions, name);
         }
         break;
      }
      case 2:
      {
         if (rng(10, odds) == true)
         {
            cout << "The rain stopped!" << endl;
            cout << "You walk home with no worries." << endl;
            cin.get();
            escaped = true;
         }
         else
         {
            cout << "The rain comes down harder." << endl;
            companionComplain(companions, name);
         }
         break;
      }
      case 3:
      {
         if (rng(2, odds) == true)
         {
            cout << "Everyone agrees to sprint home in the rain" << endl;
            cout << "You get home but you are soaking wet." << endl;
            cin.get();
            escaped = true;
         }
         else
         {
            cout << "Not everyone agrees to sprint home in the rain." << endl;
            companionComplain(companions, name);
         }
         break;
      }
      }
   }
   cin.get();

   cout << "You get home safely,";
   cin.get();
   cout << "mad about what you had to experience,";
   cin.get();
   cout << "but happy about the memories you'll cherish.";
   cin.get();
}

void finalsWeek(bool companions[], string name[])
{
   int option;
   int odds;
   bool escaped = false;
   bool found = false;

   cout << "Final night:" << endl;
   cin.get();
   cout << "The night is clear, though it is very cold outside." << endl;
   cin.get();
   cout << "You decide that it's best to go into Founders" << endl;
   cout << "since it's the only building open at this time." << endl;
   cin.get();
   cout << "You get to a door, and it won't open." << endl;
   cout << "What do you guys do next?" << endl;
   cin.get();
   cout << "1. Try another door (1 in 10 chance you find one that opens)" << endl;
   cout << "2. Look for keys (1 in 7 chance you find some)" << endl;
   cout << "3. Go back home (1 in 1000 chance that everyone gives up)" << endl << endl;

   while (escaped != true)
   {
      cout << "\nWhat option will you choose? ";
      cin >> option;
      cout << "Pick your odds: ";
      cin >> odds;

      switch (option)
      {
      case 1:
      {
         if (rng(10, odds) == true)
         {
            cout << "The door you try opens!" << endl;
            cout << "You hurry in to escape the cold." << endl;
            cin.get();
            cout << "You find a place to sit and start talking." << endl;
            cin.get();
            cout << "*A few hours pass*" << endl;
            cin.get();
            cout << "You all feel exhausted and decide to head home." << endl;
            cin.get();
            cout << "You hug everyone prior to separating." << endl;
            escaped = true;
         }
         else
         {
            cout << "Another locked door." << endl;
            companionComplain(companions, name);
         }
         break;
      }
      case 2:
      {
         if (rng(7, odds) == true)
         {
            cout << "You found keys!" << endl;
            cout << "Although they're for a car..." << endl;
            cin.get();
            cout << "What should you do with the keys?" << endl;
            cin.get();
            cout << "1. Find a police officer and turn them in" << endl;
            cout << "(1 in 10 odds of finding a police officer)" << endl;
            cout << "2. Find the person who the keys belong to" << endl;
            cout << "(1 in 7 odds of finding the person)" << endl;

            while (found != true)
            {
               cout << "What option will you choose? ";
               cin >> option;
               cout << "Pick your odds: ";
               cin >> odds;
               
               switch (option)
               {
               case 1:
               {
                  if (rng(10, odds) == true)
                  {
                     cout << "You don't find a police officer," << endl;
                     cout << "but you find the police station and" << endl;
                     cout << "you turn in the keys there" << endl;
                     cin.get();
                     found = true;
                     break;
                  }
                  else
                  {
                     cout << "There are no police officers in sight." << endl;
                     cout << "Where are they when you need them most?" << endl;
                     cin.get();
                     break;
                  }
               }
               case 2:
               {
                  if (rng(7, odds) == true)
                  {
                     cout << "You find the person looking for the keys!" << endl;
                     cout << "They are eternally grateful" << endl;
                     cin.get();
                     found = true;
                     break;
                  }
                  else
                  {
                     cout << "Maybe you should keep the keys..." << endl;
                     cout << "Rebekah doesn't let you." << endl;
                     cin.get();
                     break;
                  }
               }
               }
            }

            escaped = true;
         }
         else
         {
            cout << "Why would keys just be sitting around?" << endl;
            companionComplain(companions, name);
            break;
         }

         cout << "You feel good about the good deed you did." << endl;
         cin.get();
         cout << "It comes time for everyone to part." << endl;
         cin.get();
         cout << "You give everyone a hug and wish them a good break."  << endl;

         break;
      }
      case 3:
      {
         if (rng(1000, odds) == true)
         {
            cout << "Everyone gives up because it's too cold." << endl;
            cout << "What a disappointing way to end the semster." << endl;
            cin.get();
            escaped = true;
            
            cout << "Convince everyone to stay adventuring?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> option;
           
            if (option == 1)
            {
               cout << "The group agrees to keep adventuring!" << endl;
               escaped = false;
               cin.get();
            }
            else if (option == 0)
            {
               cout << "You're all quitters" << endl;
               cin.get();
               cout << "Although there was no adventure," << endl;
               cout << "You are all happy to be warm inside." << endl;
               cout << "You hug everyone and wish them all a good break." << endl;
            }
            else
            {
               cout << "Pick one or two you idiot." << endl;
               cin.get();
            }
            break;

         }
         else
         {
            cout << "You are determined to have this adventure." << endl;
            companionComplain(companions, name);
         }

         break;
      }
      }
   }
   cin.get();

   cout << "With the semester over," << endl;
   cout << "You think back on all that's happened..." << endl;
   cin.get();
   cout << "You are very glad for your experiences," << endl;
   cout << "and friends you have made." << endl;
   cin.get();
   cout << "You hope that the next semester will" << endl;
   cout << "involve as much fun as the first." << endl;
}
