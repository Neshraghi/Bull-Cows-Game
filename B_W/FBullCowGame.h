#pragma once
#include<string>

using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum  class EGuessStatus 
{
	ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowecase,
};

class FBullCowGame 
{
public:
	FBullCowGame();//constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	
	void Reset();//TODO ake a more rich return 
	FBullCowCount SubmitGuess(FString); //Counting Bulls & Cows and increasing the try Assumi valid guess #
	
	
private:
	// initiated in constructor
	int32 MyCureentTry;
	int32 MyMaxTries;
	bool IsIogram(FString);
	FString MyHiddenWord;
};