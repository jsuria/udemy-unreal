/*
This is the console executable, makes use of the BullCow class
Acts as the view in a MVC pattern, for user interaction.
Game logic is in FBullCowGame class

BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

*/

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// TODO - Basically comment this out when porting to Unreal
using FText = std::string;
using int32 = int;

// Signatures
void PrintIntro(void);
void PlayGame(void);
FText GetGuess(void);
bool AskToPlayAgain(void);

FBullCowGame BCGame;

int main()
{
	PrintIntro();
	PlayGame();

	return 0;
}

FText GetGuess()
{
	FText UserGuess = "";
	getline(std::cin, UserGuess);
	return UserGuess;
}

void PlayGame()
{
	//FBullCowGame Player1Game; // This is how we instantiate in C++!
	//FBullCowGame Player2Game;

	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;
	FText SecretWord = BCGame.GetSecretWord();

	// Internal toggle
	//bool HasGuessed = false;
	bool GameIsActive = true;
	//bool GameIsWon = BCGame.IsGameWon();

	while (GameIsActive)
	{
		// Update try count
		int32 CurrentTry;

		for (int i = 1; i <= MaxTries; i++)
		{
			// Update try count
			BCGame.SetCurrentTry(i);
			CurrentTry = BCGame.GetCurrentTry();
			// TODO - Implement input validation
			// TODO - Display hits for Bulls and Cows
			std::cout << CurrentTry << ". Enter your guess:";
			FText Guess = GetGuess();

			// Mine: store current guess
			// TODO - Find a way to track history of guessed words, maybe in a list: BCGame.SetCurrentAttemptWord(Guess);
			std::cout << std::endl << "You entered " << Guess << std::endl;
			std::cout << std::endl;

			if (Guess == SecretWord)
			{
				std::cout << "You guessed the secret word!" << std::endl;
				std::cout << "Number of attempts: " << i << std::endl;
				BCGame.SetGameWon(true);
				break;
			}
			else 
			{
				// Bulls and Cows: Do this when words are not matched, so we compare by letter
				FBullCowCountStruct BullCowCount = BCGame.SubmitGuess(Guess);

				std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
				std::cout << "Cows: " << BullCowCount.Cows << std::endl;

				// TODO - Nice-to-have, displays default message on wrong guess
				/*
					if (i < MaxTries - 1) 
					{
						std::cout << "Wrong! Try again!" << std::endl;
					}
					else
					{
						// Ran out of tries
						if (i == MaxTries)
						{
							std::cout << "Sorry, you ran out of tries! The secret word is " << SecretWord << std::endl;
						}
						// TODO - Nice-to-have, warns player of last try
						else
						{
							std::cout << "Careful, this is your last try!" << std::endl;
						}
					}
				*/
			}
		}
		if (!AskToPlayAgain())
		{
			GameIsActive = false;
			BCGame.Reset();
		}
	}
	return;
}

void PrintIntro()
{
	int32 WordLength = BCGame.GetGameWordLength();
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << WordLength << " letter isogram that I am thinking of?" << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Play again (y/n)? ";
	FText ResponseBuff;
	getline(std::cin, ResponseBuff);
	return (ResponseBuff[0] == 'y' || ResponseBuff[0] == 'Y');
}