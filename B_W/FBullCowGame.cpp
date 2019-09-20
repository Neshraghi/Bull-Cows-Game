#include "FBullCowGame.h"

//using int32 = int;


FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCureentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "neda";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCureentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon()const
{
	return false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus :: Not_Isogram; 
	}

	else if (false)
	{
		return EGuessStatus :: Not_Lowecase;
	}

	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus :: Wrong_Length;
	}
	else 
	{
		EGuessStatus :: ok;
	}
	
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyMaxTries++; 	//return try number
	
	FBullCowCount BullCowCount; //setup a return variable
	int32 HiddenWordLength = MyHiddenWord.length();
	
	for (int32 MyHidChar = 0; MyHidChar <= HiddenWordLength; MyHidChar++) 
	{// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			if (MyHiddenWord[MyHidChar] == Guess[GChar])
			{
				if (MyHidChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}

	}
	return BullCowCount;
}

bool FBullCowGame::IsIogram(FString)
{
	return false;
}
