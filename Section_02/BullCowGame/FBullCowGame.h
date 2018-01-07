#pragma once

#include <iostream>
#include <string>

class FBullCowGame
{

public:
	int GetWordLength();
	int GetCurrentTry();
	void SetCurrentTry(int);

private:
	int WordLength = 10;
	int CurrentTry = 1;

};

