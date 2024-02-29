#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>

using namespace std;

//COMMIT CHANGES ON GITHUB TEST1

void welcomeMessage() {
  cout << "********************************************\n"
       << "Welcome to Roller's Un-Random house of dice!\n"
       << "********************************************\n";
}

// returns userName
string getUserName(string userInput) {
  string userInputName = userInput;
  return userInputName;
}

// returns Random SEED using time or given values by user
int randomSeed(int userChoice) {
  int userChoice_randomSeedFunc = userChoice;
  if (userChoice_randomSeedFunc == 0) {
    int numSec = time(nullptr);
    srand(numSec);
    cout << "THE TIMER!What a daring choice!\n";
    cout << "\n";
    return rand();
  } else {
    srand(userChoice_randomSeedFunc);
    cout << userChoice << "! What a wise and safe choice!\n";
    cout << "\n";
    return userChoice;
  }
}
// Gets max bet from the user and Returns the value
int getMaxBet(int userMaxBet) {
  int userMaxBet_func = userMaxBet;
  int returnedMaxBet = 0;
  if (userMaxBet_func < 1) {
    cout << "The maximum bet mus te greater than or equal to 1.\n";
    cout << "What would you like to be the max bet? : ";
    cin >> returnedMaxBet;
    return returnedMaxBet;
  } else {
    return userMaxBet_func;
  }
}

// Returns a random value between 1 and 6 *INCLUSIVE*
int randomRolling1TO6() {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(1, 6);
  return dist(rd);
}

// Gets user's bet and returns the value
int getUserBet(int maxBet) {
  int userBet = 0;
  bool numIsValid = false;
  cout << "Enter your bet: ";
  cin >> userBet;
  while (numIsValid == false) {
    if (userBet < 1) {
      cout << "Your bet must be atleast 1.\n";
      cout << "Enter your bet: ";
      cin >> userBet;
    } else if (userBet > maxBet) {
      cout << "Your bet cannot exceed the max bet (" << maxBet << ")\n";
      cout << "Enter your bet: ";
      cin >> userBet;
    } else if ((userBet > 1) && (userBet < maxBet)) {
      return userBet;
    }
  }

  return 0;
}

int calcScores_dealer(int num1, int num2) { return num1 + num2; }

int calcScores_player(int num1, int num2) { return num1 + num2; }

// the gameplay itself
void gamePlay(int userMAXBET, string userName) {
  int gamePoints = 50;
  int gameRound = 1;
  bool gameIsOn = true;
  int maxBetMade = getMaxBet(userMAXBET);
  while (gameIsOn) {
    cout << "Round " << gameRound << " You have " << gamePoints << " points\n";
    int dealerNum1 = randomRolling1TO6();
    int dealerNum2 = randomRolling1TO6();
    int dealersScore = calcScores_dealer(dealerNum1, dealerNum2);
    cout << "Dealer Rolls: " << dealerNum1 << " + " << dealerNum2 << " = "
         << dealersScore << "             ";

    int userBet = getUserBet(maxBetMade);
    int userNum1 = randomRolling1TO6();
    int userNum2 = randomRolling1TO6();
    int playersScore = calcScores_player(userNum1, userNum2);
    cout << "You Roll: " << userNum1 << " + " << userNum2 << " = "
         << playersScore << endl;

    if (playersScore > dealersScore) {
      cout << userName << ", you won! :-)\n";
      gamePoints += userBet;
      cout << "Current Score: " << gamePoints << endl;
      gameRound++;
    } else if (playersScore == dealersScore) {
      cout << userName << " , it's a draw! :-|\n";
      cout << "Current Score: " << gamePoints << endl;
      ;
      gameRound++;
    } else {
      cout << userName << ", you lost! :-(\n";
      gamePoints -= userBet;
      cout << "Current Score: " << gamePoints << endl;
      gameRound++;
    }

    if (gamePoints <= 0) {
      cout << "I'm sorry;" << userName
           << ", you have no points left. YOU LOSE!";
      gameIsOn = false;
    } else if (gamePoints >= 100) {
      cout << "Congratulations " << userName
           << "! You win the game with a score of " << gamePoints;
    }
  }
}

int main() {

  welcomeMessage();

  string userInputName = "";
  cout << "What is your first name: ";
  cin >> userInputName;

  // RANDOM SEED using TIME or userInput
  int randomUserChoice = 0;
  cout << "Would you like to pick an un-random game, or let the timer pick?\n"
       << "Enter 0 for timer, or pick your own un-random game:";
  cin >> randomUserChoice;
  randomSeed(randomUserChoice);

  int userMAXBET = 0;
  cout << "What would you like to be the max bet? : ";
  cin >> userMAXBET;

  // the game itself

  gamePlay(userMAXBET, userInputName);

  return 0;
}
