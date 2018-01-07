#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	this->Reset();
	
	return;
}

//Construct / Reset game
void FBullCowGame::Reset()
{
	//set constructor scoped variables
	//We are setting "magic" values as constants and applying those constants to our class variables. Rather than applying "magic" values directly to our class variables.
	constexpr int32 MAX_TRIES = 5;

	const FString SECRET_WORD = "Meridian";

	//set class level variables.
	WordLength = 10;
	CurrentTry = 1;
	MaxTries = MAX_TRIES;
	bCorrectGuess = false;

	sSecretWord = SECRET_WORD;

	return;
}

//Logic Methods

bool FBullCowGame::IsValidGuess(FString)
{
	return true;
}

FBullCowCount FBullCowGame::IsCorrectGuess(FString)
{
	//CurrentTry++;
	FBullCowCount BullCowCount;

	int32 SecretWordLength = sSecretWord.length();
	//loop through out secret word and check it against our guess
	for (int32 i = 0; i < SecretWordLength; i++) {
		for (int32 j = 0; j < SecretWordLength; j++) {

		}
	}

	return BullCowCount;
}


bool FBullCowGame::DidPlayerWin(FBullCowCount)
{
	/*
	int32 SecretWordLength = sSecretWord.length();

	if (BullCowCount == SecretWordLength) {
		return true;
	}
	else 
	{
		return false;
	}
	*/
}

//Getters

int32 FBullCowGame::GetWordLength() const { return WordLength; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MaxTries; }



//Setters

void FBullCowGame::SetCurrentTry(int32 count) { CurrentTry = count; }
