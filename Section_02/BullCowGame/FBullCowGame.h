#pragma once

#include <iostream>
#include <string>

using FString = std::string;
using int32 = int; // int32_t;


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{

public:
	FBullCowGame(); //constructor

	// ...for all intents and purposes, the real constructor
	void Reset();

	//Make sure this is a valid guess string
	bool IsValidGuess(FString);

	//Only submit valid guess
	FBullCowCount IsCorrectGuess(FString);

	//returns true if the guess was completely correct
	bool DidPlayerWin(FBullCowCount);

	int32 GetWordLength() const;
	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;

	void SetCurrentTry(int32);

private:
	//set in constructor
	int32 WordLength;
	int32 CurrentTry;
	int32 MaxTries;

	FString sSecretWord;

	bool bCorrectGuess;
};

