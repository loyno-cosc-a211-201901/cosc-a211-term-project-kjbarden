// Program Name: Final Project Game
// Purpose: a text based game where your (hard) decisions influence the outcome of
//          of the (hard) game, that actually isn't as hard as I intended due to me severely
//          underestimating how much time it actually takes to write a (not so good) storyline
// Author: Kyle Barden
// Date Last Modified: April 19, 2019

//***********
// READ THIS: I'm gonna be breaking the 4th wall a lot as the narrator and the narrator is gonna
//            be very rude and talk trash to you at points so don't take it personally, the game is supposed
//            to make you upset, anyway that's all, here comes the narrator. Scences are also listed
//            as functions in reverse chronological order (except intro) so start at the bottom of the program and read up.
//***********

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
//global variables used to track living status of party memebers 1 = alive, 0 = dead
bool Jack = 1, Kirk = 1, Steve = 1, Sean = 1, Isabella = 1, Carl = 1, Player = 1;
//used for player health, so you can't keep making dumb combat mistakes, (that was the intention going in but my story isn't as long as
//I thought it would be so it's just there for show at this point
int Health = 100;
//used to keep track of how many bandits are left in the final fight, also kind of arbitrary because well, you'll see that it doesn't matter too much.
int Bandits = 20;

int RNG(int min, int max){
  const int MIN = min; //set min random value
  const int MAX = max; //set max random value
  int Random; //random number
  Random = (rand() % (MAX - MIN + 1) + MIN);

  return Random;
}

char TwoChoices(char Choice, char c1, char c2, char c3, char c4){
  while (Choice != c1 && Choice != c2 && Choice != c3 && Choice != c4){
    cout << "Invalid, choose again (" << c1 << " or " << c3 << ")\n";
    cin >> Choice;
  }
  return Choice;
}

//beginning game messages, ask for start
bool Intro(){

  char GameStartChoice;
  bool GameStart = 0;

  cout << "Welcome to The Game, I'm not good at names so that's what it's called.\n\n"
       << "You're a warrior on an mission to retrieve a noble family's stolen heirloom, "
       << "your party consists of: \n\n"
       << "Yourself - a warrior trained in most aspects of fighting\n"
       << "3 Swordsmen - Jack, Kirk, and Steve\n"
       << "2 Archers - Sean and Isabella\n"
       << "A healer - Carl\n\n"
       << "Your decisions will decide how easy the final stage of the game is for you.\n"
       << "Letting your party members die is not advised, when a combat choice is presented\n"
       << "I recommend visualizing what your character is doing because you CAN die and I am\n"
       << "not a merciful narrator/game overlord.\n\n"
       << "Anyway, still want to play? (Y/N)\n";
  cin >> GameStartChoice;
  GameStartChoice = TwoChoices(GameStartChoice,'Y', 'y', 'N', 'n');

  if(GameStartChoice == 'Y' || GameStartChoice == 'y'){
    GameStart = 1;
  }
  else {
    GameStart = 0;
    cout << "Wow, I'm offended, I guess you're scared. Thanks for reading the intro I guess.";
  }
  return GameStart;
}
//so for this one and the other scene14, i decided to do the unspeakable...
//a cliffhanger ending because, where's the fun in a real ending? although these are different cliffhangers
void Scene14b(){
  cout << "The bandits come to encircle you and you soon realize that Sean has been taken out and Isabella is running toward you with bandits on her tail.\n"
       << "Oof, hard choices huh?\n"
       << "A. Try to save Isabella from her pursuers\n"
       << "B. Fight the bandits and hope Isabella can figure something out\n"
       << "C. Try to push through the bandits to their leader now that they're spread out\n\n"
       << "Haha, this is the end of The Game 1, stay tuned for more in Programming 2.";
}

void Scene14a(){
  cout << "The bandits don't try to encirlce you, instead for each of your archers, 4 bandits approach them, looking to eliminate your advantage.\n"
       << "You have quite a choice here...\n"
       << "A. Push to try and save Isabella\n"
       << "B. Push to try and save Sean\n"
       << "C. Push the bandit leader now that he has spread out his forces\n\n"
       << "Haha, this is the end of The Game 1, stay tuned for more in Programming 2.";
}

void Scene13bB(){
  cout << "Honestly for bad choices back to back, you deserve this one.\n"
       << "As soon as you jump out, the bandits are ready for you, like they expected this to happen. You'd be able to take just this group of bandits,\n"
       << "but soon after you start your attack, Isabella and Sean are taken out by the bandit archers and you're soon surrounded. You and the remainder of your\n"
       << "group fight valiantly but end up losing to the bandits. Sucks to suck. Game over.\n";
}

void Scene13bA(){
  cout << "Isabella and Sean are able to take out 2 bandits before you engage the rest, they almost seemed prepared for you to jump out at them.\n"
       << "Almost as if to confirm your suspicions the rest of the bandits are in the outpost much sooner than you would have thought, looks like you'll\n"
       << "have to fight hard to avoid losing here.\n";
  Bandits-= 2;
  Scene14b();
}

void Scene13aB(){
  cout << "You and the other swordsmen only manage to take out a bandit before you pull away into the outpost to prevent being encircled\n"
       << "On your way back you get nicked in the leg by a sword\n";
  Health -= 3;
  Bandits--;
  cout << "Your Health is now: " << Health << endl;
  //14a because it will link up with the other lowercase a, (13aA)
  Scene14a();
}

void Scene13aA(){
  cout << "You and the swordsmen are able to hold off against the initial charge but will be easily overwhelmed if you're surrounded.\n"
       << "Isabella is able to take out another bandit before you and the swordsmen start to really fight back.\n";
  Bandits--;
  //14a because it will link up with the other lowercase a, (13aB)
  Scene14a();
}

void Scene12b(){
  char Choice12b;
  cout << "Chapter 3: The End until I can maybe actually tell a decent story\n\n"
       << "You and the other swordsmen wait inside the outpost while Isabella and Sean are hidden in vantage points around the camp.\n"
       << "The first group of bandits are just now entering the camp with the rest coming in close behind.\n"
       << "A. Wait for Isabella or Sean to fire and then charge out at the bandits in camp\n"
       << "B. Charge out at the bandits and hope Sean and Isabella can get some of the bandits coming in next\n";
  cin >> Choice12b;
  Choice12b = TwoChoices(Choice12b, 'A', 'a', 'B', 'b');
  //scenes will be the previous scene's letters, followed by the choice most recently made, in alternating case if there are more than 2 routes to be taken
  if (Choice12b == 'A' || Choice12b == 'a'){
    Scene13bA();
  }
  else{
    Scene13aB();
  }
}

void Scene12a(){
  char Choice12a;
  cout << "Chapter 3: The End until I can maybe actually tell a decent story\n\n"
       << "You and the swordsmen wait outside the outpost while Isabella and Sean stay behind in the best vantage points they can find.\n"
       << "As soon as the bandits get in range, they also seem to realize that you are not bandits, and they charge you. Isabella and Sean\n"
       << "begin firing taking out 2 of the bandits before they are able to get too close to hit from their current positions.\n";
  Bandits-= 2;
  cout << "Bandits left: " << Bandits << endl
       << "A. Fight Defensively and try to get the bandits into the outpost and give Isabella and Sean better shot opportunities\n"
       << "B. Fight Agressively and hope Isabella and Sean can get clean shots on the bandits\n";
  cin >> Choice12a;
  Choice12a = TwoChoices(Choice12a, 'A', 'a', 'B', 'b');
  //scenes will now be the previous scenes letters, followed by the choice most recently made, in alternating case
  if (Choice12a == 'A' || Choice12a == 'a'){
    Scene13aA();
  }
  else{
    Scene13aB();
  }
}

void Scene11(){
  char Choice11;
  cout << "The time has come for me to see if you have any type of strategy and/or luck, the bandit leader and a sizeable group of bandits arrive\n"
       << "soon. Are you up to the test? Let's find out.\n\n"
       << "Isabella comes into camp and straight to you letting you know she spotted the bandits about 45 minutes away and that there are about 20 of them\n"
       << "(Be thankful its ONLY 20 :).)\n"
       << "A. Wait outside for them and have Isabella and Sean start shooting as soon as they can\n"
       << "B. Wait for them to get into camp and then start the ambush\n\n";
  cin >> Choice11;
  Choice11 = TwoChoices(Choice11, 'A', 'a', 'B', 'b');
  if (Choice11 == 'A' || Choice11 == 'a'){
    Scene12a();
  }
  else{
    Scene12b();
  }
}

void Scene10n(){
  cout << "You decide that you'll set an ambush for the bandits to get the heirloom back.\n";
  Scene11();
}

void Scene10d(){
  cout << "As the bandit on the horse gets closer he simply yells 'Message from the chief!' and tosses a rolled up letter into the camp before\n"
       << "riding off to what's probably the next outpost. The letter just says that the rest of the bandits from the main camp\n"
       << "will be coming up this road tomorrow night. You decide that you'll set an ambush for the bandits to get the heirloom back.\n";
  Scene11();
}

//so I'd love to make a choice here where you can either stay and wait for the rest of the bandits or go to them, but that's a lot more
//creativity required that I don't have, so I'm taking it easy and letting you stay and wait for them

void Scene9n(){
  cout << "After you finish off the bandits, you check their leader's tent for any useful information, and luckily right on the small table\n"
       << "is just what you're looking for, a letter from the bandit chief. The letter just says that the rest of the bandits from the main camp\n"
       << "will be coming up this road tomorrow night.\n";
  Scene10n();
}

void Scene9d(){
  cout << "Shortly after you take out the outpost you see a horseman approach from the direction of the bandit camp, they're likely coming\n"
       << "to bring some type of message, so you tell everyone to take up positions and hide.\n";
  Scene10d();
}

void Scene8b(){
  cout << "Sean and Isabella are able to take out two of the bandits before you and the swordsmen reach them and make quick work of them.\n";
  Scene9d();
}

void Scene8a(){
  cout << "Sean and Isabella are able to take out one of the bandits before you and the swordsmen reach them and make quick work of them.\n";
  Scene9d();
}

void Scene7c(){
  cout << "You move on the bandits outpost during the night, by the time you get close, Isabella and Sean have taken out the two\n"
       << "bandits on watch, and you and the others have no problem killing the other bandits while they sleep.\n";
  //n = night choice
  Scene9n();
}

void Scene7b(){
  cout << "As you approach, the bandit on watch calls out to his buddies and 4 bandits emerge from the outpost ready to engage.\n"
       << "The bandit the was on watch picks up a bow from his vantage point and sends an arrow that flies wide of your group.\n"
       << "Isabella and Sean silently take out the bandit archer and the rest of the bandits charge towards you thinking it'll be an\n"
       << "easy fight with their archer, but they all drop dead before they reach you from your two archers.\n";
  //d = day choice
  Scene9d();
}

void Scene7a(){
  char Choice7a;
  cout << "As you approach, the bandit on watch calls out to his buddies and 4 bandits emerge from the outpost ready to engage.\n"
       << "The bandit the was on watch picks up a bow from his vantage point and sends an arrow that nicks your sword arm (-5 health).\n"
       << "Isabella and Sean's arrows follow immediately and hit the bandit twice in the chest.\n"
       << "A. Charge the remaining bandits now that they have no support\n"
       << "B. Continue to advance slowly and let Sean and Isabella try to end the melee before it begins\n";
  cin >> Choice7a;
  Health -= 5;
  Choice7a = TwoChoices(Choice7a, 'A', 'a', 'B', 'b');
  cout << "Your health is now " << Health << endl;
  if (Choice7a == 'A' || Choice7a == 'a'){
    Scene8a();
  }
  else{
    Scene8b();
  }
}

void Scene6b(){
  char Choice6b;
  cout << "Attacking the outpost now is a little risky, but you decide that you might lose time if you wait until night.\n"
       << "From what Sean could tell there were about 5 bandits at the outpost, but he couldn't tell what weapons they had.\n"
       << "A. Have Sean and Isabella follow behind you and the Swordsmen to support you at close range\n"
       << "B. Have Sean and Isabella flank on the left while you and the swordsmen push the right side of the outpost\n";
  cin >> Choice6b;
  Choice6b = TwoChoices(Choice6b, 'A', 'a', 'B', 'b');
  if (Choice6b == 'A' || Choice6b == 'a'){
    Scene7a();
  }
  else{
    Scene7b();
  }
}

void Scene6a(){
  cout << "Attacking at night is the smart play in this situation, but you might lose some time because of it.\n"
       << "From what Sean could tell there were about 5 bandits at the outpost, but he couldn't tell what weapons they had.\n"
       << "You tell Sean and Isabella to take up a positon on the left and right of the outpost to take out any sentries\n"
       << "or bandits that try and flank you and the swordsmen as you come down the road into the middle of the outpost.\n";
  //no choice here but c to keep the scenes for different paths the same number
  Scene7c();
}

void Scene5(){
  char Choice5;
  cout << "Chapter 2: Assault\n\n"
       << "Morning arrives and everyone is ready to go. After a few hours pass Sean tells you that the bandits have another\n"
       << "outpost on the road ahead. The terrain is rough and muddy so you won't be able to take the wagon around the Outpost.\n"
       << "A. Wait until night to attack the outpost\n"
       << "B. Attack the outpost now and keep moving\n\n";
  cin >> Choice5;
  Choice5 = TwoChoices(Choice5, 'A', 'a', 'B', 'b');
  if(Choice5 == 'a' || Choice5 == 'A'){
    Scene6a();
  }
  else{
    Scene6b();
  }

}

void Scene4b(){
  cout << "You set up camp and as everyone is sleeping, Steve falls asleep on watch and your camp is encircled by bandits.\n"
       << "The bandits slaughter all of you while you sleep after finding the bodies of the other bandits.\n\n"
       << "You lose, maybe try listening to a good idea next time.";
}

void Scene4a(){
  cout << "You carry on for another 2 to 3 hours before setting up camp and letting everyone rest.\n"
       << "You tell everyone that you're only a half day away from the bandit camp that the heirloom is suspected to be at\n"
       << "and that you'll attack in the middle of the afternoon.\n\n";
  Scene5();
}

void Scene3(){
  char Choice3;
  float rand3 = RNG(1, 10);
  cout << "You call for the other members of your party to come fight off the bandits.\n"
       << "Sean and Isabella take down the archer with a quick barrage of arrows while\n"
       << "you Jack and Steve quickly kill the other two bandits who were surprised to see the\n"
       << "rest of the party.\n\n";
       if (Kirk == 0){
         cout << "Carl calls out to everyone else that Kirk is dead.\n\n";
       }
       else if (rand3 > 7){
         cout << "Carl comes over to let everyone know Kirk is alive but badly injured.\n\n";
         Kirk = 1;
       }
       else if (rand3 <= 7){
         Kirk = 0;
         cout << "Carl calls out to everyone else that Kirk is dead.\n\n";
       }
  cout << "Isabella recommends that you move along and camp farther away in case more bandits show up in the night.\n\n";

  cout << "A. Follow her advice and keep moving and camp later in the path.\n";
  if (Kirk == 0){
    cout << "B. Stop and set up camp to bury Kirk.\n";
  }
  else{
    cout << "B. Stop and set up camp to let Kirk rest.\n";
  }
  cin >> Choice3;
  Choice3 = TwoChoices(Choice3, 'A', 'a', 'B', 'b');

  if (Choice3 == 'B' || Choice3 == 'b'){
    Scene4b();
  }
  else{
    Scene4a();
  }
}

void Scene2b(){
  cout << "The bandit archer fires another arrow which hits Kirk in the heart before moving on to the wagon again\n"
       << "with the rest of the bandits. (I told you choices matter...)\n\n";
  Kirk = 0;
  Scene3();
}

void Scene2a(){
  float rand2 = RNG(1, 10);
  if(rand2 > 1){
    cout << "Kirk hits the ground and the arrow's head comes out of his back, potentially saving his life.\n\n";
    Scene3();
  }
  else {
    Kirk = 0;
    Scene3();
  }
}

//Scene 1 further scences will have a letter to denote the previous choice(if applicable) i.e scene 2b
void Scene1(){
  char Choice1a;

    cout << "Chapter 1: Ambush\n\n"
         << "It's mid-afternoon, you and your party are on the road north to the location where the family's\n"
         << "heirloom is being held. You are sitting in the front of the wagon talking with Kirk\n"
         << "about when you'll be stopping for the night when an arrow flies from one of the trees nearby\n"
         << "and hits Kirk in the Chest. Following the arrow is a group of 3 bandits coming straight to the wagon.\n\n"
         << "Time for your first choice, what do you do?\n"
         << "A. Push Kirk off the wagon and jump off the wagon with your shield up\n"
         << "B. Jump off the wagon with your shield and sword ready\n";
    cin >> Choice1a;
    Choice1a = TwoChoices(Choice1a, 'A', 'a', 'B', 'b');

    if (Choice1a == 'a' || Choice1a == 'A'){
      Scene2a();
    }
    else{
      Scene2b();
    }
}

//main function
int main(){

  //seed RNG
  unsigned seed = time(0);
  srand(seed);
if (Intro() == 1){
  Scene1();
}

  return 0;
}
