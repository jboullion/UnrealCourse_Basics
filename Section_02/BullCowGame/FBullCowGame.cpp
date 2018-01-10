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

	const FString SECRET_WORD = "james";

	//set class level variables.

	CurrentTry = 0;
	bCorrectGuess = false;
	sGuess = "";
	MaxTries = MAX_TRIES;
	sSecretWord = SECRET_WORD;

	return;
}

//Logic Methods

EGuessValidity FBullCowGame::IsValidGuess() const
{
	int32 GuessLength = sGuess.length();
	int32 SecretWordLength = GetSecretWordLength();

	if (GuessLength == 0)
	{
		return EGuessValidity::Empty;
	}
	else if (GuessLength > SecretWordLength)
	{
		return EGuessValidity::Too_Long;
	}
	else if (GuessLength < SecretWordLength)
	{
		return EGuessValidity::Too_Short;
	}
	
	if (! IsIsogram(sGuess))
	{
		return EGuessValidity::Not_Isogram;
	}

	
	return EGuessValidity::Good;
	
}

FBullCowCount FBullCowGame::IsCorrectGuess()
{
	//CurrentTry++;
	FBullCowCount BullCowCount;

	int32 GuessLength = sGuess.length();
	int32 SecretWordLength = GetSecretWordLength();
	//loop through out secret word and check it against our guess
	for (int32 sw = 0; sw < SecretWordLength; sw++)
	{
		for (int32 g = 0; g < GuessLength; g++)
		{
			if (tolower(sGuess[g]) == sSecretWord[sw])
			{
				if (g == sw)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}

				break;
				
			}
			else
			{
				//miss
			}
		}
	}

	return BullCowCount;
}


bool FBullCowGame::DidPlayerWin(FBullCowCount BullCowCount) const
{

	if (BullCowCount.Bulls == sSecretWord.length())
	{
		return true;
	}
	else 
	{
		return false;
	}

}

//Check if string is an isogram
bool FBullCowGame::IsIsogram(FString CheckString) const
{
	TMap<char, bool> LetterMap;

	//TECHNICALLY a one letter word is an isogram, although I do not really like that definition
	if (CheckString.length() == 1) { return true; }

	//build our TMap. Use auto instead of char to allow the compiler to decide what simple type to use
	// This is an O (n) solving algorithm. We use a hash table (a TMap in this case) to check if we find a duplicate letter by looping through the guess once
	for (auto letter : CheckString)
	{
		letter = tolower(letter);

		if (LetterMap[letter])
		{
			//if this letter already exists in this map, we know this is not an isogram
			return false;
		}
		else
		{
			LetterMap[letter] = true;
		}
		
	}


	// This is an O(n log n) + n solving algorithm. The n log n is due to the sorting function and the + n is because we still have to go through the word to check it, but only once
	/*
	int32 StringLength = CheckString.length();
	std::sort(CheckString.begin(), CheckString.end());
	for (int32 g = 0; g < StringLength; g++)
	{
		if (sGuess[g + 1] && sGuess[g] == sGuess[g+1])
		{
			return false;
		}
	}
	*/


	// O(n^2) - This is a n^2 solving algorithm. It works but is slow
	/*
	int32 StringLength = CheckString.length();
	for (int32 ga = 0; ga < StringLength; ga++)
	{
		for (int32 gb = 0; gb < StringLength; gb++)
		{
			//Only accept words that do not share the same letter in two spaces
			if (ga != gb && sGuess[ga] == sGuess[gb])
			{
				return false;
			}
		}
	}
	*/

	return true;
}

void FBullCowGame::UpdateCurrentTry() { CurrentTry++; }


//Getters

int32 FBullCowGame::GetSecretWordLength() const { return sSecretWord.length(); }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MaxTries; }


//Setters
void FBullCowGame::SetGuess(FString PlayerGuess) { sGuess = PlayerGuess; }

