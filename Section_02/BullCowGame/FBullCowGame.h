#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm> //used for std::sort 
#define TMap std::map

using FString = std::string;
using int32 = int; // int32_t;


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessValidity
{
	Good,
	Not_Isogram,
	Too_Short,
	Too_Long,
	Empty,
	Not_Lowercase

};

class FBullCowGame
{

public:
	FBullCowGame(); //constructor

	// ...for all intents and purposes, the real constructor
	void Reset();

	//Make sure this is a valid guess string
	EGuessValidity IsValidGuess() const;

	//Only submit valid guess
	FBullCowCount IsCorrectGuess();

	//returns true if the guess was completely correct
	bool DidPlayerWin(FBullCowCount) const;

	

	//increment the current try
	void UpdateCurrentTry();

	int32 GetSecretWordLength() const;
	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;

	void SetGuess(FString);
	

private:
	//set in constructor
	int32 WordLength;
	int32 CurrentTry;
	int32 MaxTries;

	FString sSecretWord;
	FString sGuess;

	bool bCorrectGuess;

	//return true if string is an isogram
	bool IsIsogram(FString) const;
};

