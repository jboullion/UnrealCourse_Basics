/**
 * Bulls and Cows game.
 * A basic text console game, similar to hangman.
 * Author: James Boullion
 */

#include <iostream>
#include <string>

using namespace std;

void PrintIntro(int WORD_LENGTH);
bool PlayGame(int WORD_LENGTH);
string GetGuess(int WORD_LENGTH);
void PrintResult(string WORD_LENGTH);
bool PlayAgain(bool success);

int main()
{	
	constexpr int WORD_LENGTH = 10;
	int success = false;

	do
	{
		PrintIntro(WORD_LENGTH);
		success = PlayGame(WORD_LENGTH);
	}
	while (PlayAgain(success));

	return 0;
}


//Game logic
bool PlayGame(int WORD_LENGTH)
{
	//How many guesses before failure
	constexpr int NUM_GUESSES = 5;

	for (int count = 1; count <= NUM_GUESSES; count++)
	{
		PrintResult(GetGuess(WORD_LENGTH));
	}

	return true; //success or failure
}

//On success or failure, ask the user to play again
bool PlayAgain(bool success)
{	
	string response = "";

	cout << endl;
	if (success) {
		cout << "You're so smart! Play again? (y/n) ";
	}
	else 
	{
		cout << "You're a loser in life don't be a loser in the game! Play again? (y/n) ";
	}

	getline(cin, response);
	cout << endl;

	return (response[0] == 'y' || response[0] == 'Y');
	
}


//Welcome the users
void PrintIntro(int WORD_LENGTH)
{
	
	cout << "Welcome to Bullseyes and Cow Pies!\n"; // << std::endl stands for "End Line" and works similarly to \n;
	cout << "Guess the magic word bitch!\n";
	cout << "The magic word is " << WORD_LENGTH << " letters long.\n";
	cout << endl;

	return;
}


//Get a guess from the user
string GetGuess(int WORD_LENGTH)
{
	string Guess = "";

	cout << "Show me what you got: ";

	getline(cin, Guess);

	return Guess;
}

//Show the user the result of their guess
void PrintResult(string Guess) {

	//Return feedback to user
	cout << "\nYou Guessed: " << Guess << endl;

	return;
}
