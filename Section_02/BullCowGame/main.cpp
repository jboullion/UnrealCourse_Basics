/**
 * Bulls and Cows game.
 * A basic text console game, similar to hangman.
 * Author: James Boullion
 */

#include <iostream>
#include <string>

#include "FBullCowGame.h"

void PrintIntro(int WordLength);
bool PlayGame(int WordLength);
std::string GetGuess(int CurrentTry);
void PrintResult(std::string Guess);
bool PlayAgain(bool success);

FBullCowGame BCGame;

int main()
{	
	int WordLength = BCGame.GetWordLength();
	int success = false;

	do
	{
		PrintIntro(WordLength);
		success = PlayGame(WordLength);
	}
	while (PlayAgain(success));

	return 0;
}


//Game logic
bool PlayGame(int WordLength)
{
	
	//How many guesses before failure
	constexpr int NUM_GUESSES = 5;
	int CurrentTry = BCGame.GetCurrentTry();

	for (int CurrentTry = 1; CurrentTry <= NUM_GUESSES; CurrentTry++)
	{
		BCGame.SetCurrentTry(CurrentTry);
		PrintResult(GetGuess(CurrentTry));
	}

	return true; //success or failure
}

//On success or failure, ask the user to play again
bool PlayAgain(bool success)
{	
	std::string response = "";

	std::cout << std::endl;
	if (success) {
		std::cout << "You're so smart! Play again? (y/n) ";
	}
	else 
	{
		std::cout << "You're a loser in life don't be a loser in the game! Play again? (y/n) ";
	}

	std::getline(std::cin, response);
	std::cout << std::endl;

	return (response[0] == 'y' || response[0] == 'Y');
	
}


//Welcome the users
void PrintIntro(int WordLength)
{
	
	std::cout << "Welcome to Bullseyes and Cow Pies!\n"; // << std::endl stands for "End Line" and works similarly to \n;
	std::cout << "Guess the magic word bitch!\n";
	std::cout << "The magic word is " << WordLength << " letters long.\n";
	std::cout << std::endl;

	return;
}


//Get a guess from the user
std::string GetGuess(int CurrentTry)
{
	std::string Guess = "";

	std::cout << std::endl << CurrentTry << ". Show me what you got: ";

	std::getline(std::cin, Guess);

	return Guess;
}

//Show the user the result of their guess
void PrintResult(std::string Guess) {

	//Return feedback to user
	std::cout << "You Guessed: " << Guess << std::endl;

	return;
}
