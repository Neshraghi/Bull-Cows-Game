/* This is the consol excecutable, that make use of Bull&Cow class
this acts as the view in a MVC pattern, and is responsible for all user interaction, for game logic see the FBullCowgame class*/



#include <iostream>
#include<string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; //instantiate a new game


int main() 
{
	std::cout<< BCGame.GetCurrentTry();
	bool bPlayAgain;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

	} while (bPlayAgain);
		

	std::getchar();
	return 0;
	 
}



void PrintIntro() 
{
	int32 WORLD_LENGTH = BCGame.GetHiddenWordLength();
	//introduce the game
	std::cout << "/////****************************************////\n";

	std::cout << "Welcome BUll& Cows, a fum word game!\n";
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess();// TODO  make loop checking validation
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);//TODO... submit valid guess to the game
		
		//TODO... print the number of Bulss and Cows
		std::cout << "Bulss = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows<<std::endl;
		std::cout << "#" << count << "  " << "Your guess was: " << Guess <<std::endl;

	}
}

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << "  Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin,Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << std::endl;
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
