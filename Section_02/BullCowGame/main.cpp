/**
 * Bulls and Cows game.
 * A basic text console game, similar to hangman.
 * Author: James Boullion
 */

/**
 * This is the class which displays and retrieves information from the user.
 * This can be thought of as the VIEW in the MVC pattern.
 */

//system includes
#include <iostream>
#include <string>

//custom includes
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;// int32_t;

void PrintIntro();
bool PlayGame();
FText GetGuess();
bool ReturnResult(FBullCowCount BullCowCount);
bool PlayAgain(bool success);
void PrintError(EGuessValidity GuessError);

FBullCowGame BCGame;

int main()
{	
	int32  success = false;

	do
	{
		PrintIntro();
		success = PlayGame();
	}
	while (PlayAgain(success));

	return 0;
}


//Game logic
bool PlayGame()
{
	BCGame.Reset();

	//How many guesses before failure
	int32 MaxTries = BCGame.GetMaxTries();
	int32 CurrentTry = BCGame.GetCurrentTry();
	EGuessValidity ValidGuess;
	bool bPlayerWon = false;

	FBullCowCount BullCowCount;

	FString Guess = "";

	//for (int32  CurrentTry = 1; CurrentTry <= MaxTries; CurrentTry++)
	do
	{
		BCGame.UpdateCurrentTry();
		CurrentTry = BCGame.GetCurrentTry();
		ValidGuess = EGuessValidity::Empty;

		BCGame.SetGuess( GetGuess() );
		ValidGuess = BCGame.IsValidGuess();
		if (ValidGuess == EGuessValidity::Good) {
			BullCowCount = BCGame.IsCorrectGuess();
			bPlayerWon = ReturnResult(BullCowCount);
		}
		else
		{
			PrintError(ValidGuess);
		}		

	} while (!bPlayerWon && CurrentTry < MaxTries);

	return bPlayerWon; //success or failure
}

void PrintError(EGuessValidity GuessError)
{
	switch (GuessError) {
	case EGuessValidity::Empty:
		std::cout << "Empty Guess!" << std::endl;
		break;
	case EGuessValidity::Too_Long:
		std::cout << "Too Long!" << std::endl;
		break;
	case EGuessValidity::Too_Short:
		std::cout << "Too Short!" << std::endl;
		break;
	case EGuessValidity::Not_Isogram:
		std::cout << "Not Isogram!" << std::endl;
		break;
	case EGuessValidity::Not_Lowercase:
		std::cout << "Not Lowercase!" << std::endl;
		break;
	default:
		std::cout << "Unknown Invalid!" << std::endl;
	}
	
	return;
}

//On success or failure, ask the user to play again
bool PlayAgain(bool success)
{	
	FText response = "";

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
void PrintIntro()
{
	int32 WordLength = BCGame.GetSecretWordLength();

	std::cout << "Welcome to Bullseyes and Cow Pies!\n"; // << std::endl stands for "End Line" and works similarly to \n;
	std::cout << "Guess the magic word bitch!\n";
	std::cout << "The magic word is " << WordLength << " letters long.\n";
	std::cout << std::endl;

	return;
}


//Get a guess from the user
FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << std::endl << CurrentTry << ". Show me what you got: ";

	std::getline(std::cin, Guess);

	return Guess;
}

//Show the user the result of their guess
bool ReturnResult(FBullCowCount BullCowCount)
{
	bool bPlayerWon = BCGame.DidPlayerWin(BullCowCount);

	//Return feedback to user
	if (bPlayerWon)
	{
		std::cout << "That is correct! You Win!" << std::endl;
	}
	else
	{
		std::cout << "Your guess contained " << BullCowCount.Bulls << " bulls and " << BullCowCount.Cows << " cows." << std::endl;
	}
	

	return bPlayerWon;
}
