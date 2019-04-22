#include "pch.h"
#include "FBullCowGame.h"

using FString = std::string;

FBullCowGame::FBullCowGame()
{
	// Flush everything and use default values
	Reset();
}

void FBullCowGame::Reset()
{
	// UDEMY:
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	constexpr int MAX_WORD_LENGTH = 9;
	MyGameWordLength = MAX_WORD_LENGTH;
	const FString SECRET_WORD = "Bubble Bath";
	MySecretWord = SECRET_WORD;

	MyCurrentTry = 0;
	
	MyCurrentAttemptedWord = "";
	GameWon = false;
	//IsIsogram(std::string);
}

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int32 FBullCowGame::GetGameWordLength() const {
	return MyGameWordLength;
}

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

void FBullCowGame::SetCurrentTry(int32 CurrentTry)
{
	MyCurrentTry = CurrentTry;
}

bool FBullCowGame::IsGameWon() const {
	return GameWon;
}

bool FBullCowGame::CheckGuessValidity(FString ValidateWord)
{
	return IsIsogram(ValidateWord);
}
// Receives a VALID guess, increments turn and returns coun
FBullCowCountStruct FBullCowGame::SubmitGuess(FString GuessWord)
{
	// Increment the turn number
	// Setup a return variable
	// Loop through all the letters in the guessed word
	// Do comparisons for each letter (have to be unique)
	// TODO: Implement IsIsogram()
	MyCurrentTry++; //?

	FBullCowCountStruct BullCowCount;

	int32 HiddenWordLength = MySecretWord.length();

	// Addendum: Check if added word is shorter or longer
	// than hidden word
	// TODO: Check if guess and secret word are equal before doing a letter by letter check
	if (GuessWord != MySecretWord)
	{
		// Loop through all the letters
		for (int32 i = 0; i < HiddenWordLength; i++)
		{
			// Compare letters against the hidden word
			for (int32 j = 0; j < HiddenWordLength; j++)
			{
				// If they match, then score Bulls
				if ((i == j) && (GuessWord[j] == MySecretWord[i])) {
					BullCowCount.Bulls++;
				}
				// Word is there but not in the same place
				/*
					else if ((i != j) && (GuessWord[j] == MySecretWord[i]))
					{
						BullCowCount.Cows++;
					}
				*/
				else
				{
					BullCowCount.Cows++;
				}

			}
		}
	}
	
	return BullCowCount;
}

void FBullCowGame::SetGameWon(bool Won)
{
	GameWon = Won;
}

void FBullCowGame::SetCurrentAttemptWord(FString AttemptWord)
{
	MyCurrentAttemptedWord = AttemptWord;
}

FString FBullCowGame::GetCurrentAttemptWord() const {
	return MyCurrentAttemptedWord;
}

FString FBullCowGame::GetSecretWord() const {
	return MySecretWord;
}

bool FBullCowGame::IsIsogram(FString CheckWord)
{

	return false;
}
