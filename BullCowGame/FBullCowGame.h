#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCountStruct {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();  // Constructor

	// Udemy methods
	void Reset();			// TODO - Improve on return value
	int32 GetMaxTries() const;
	int32 GetGameWordLength() const;

	int32 GetCurrentTry() const;		// Nth try?
	void SetCurrentTry(int32);	// Probably will run this inside loop

	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	FBullCowCountStruct SubmitGuess(FString);	// count container for Bulls and Cows

	void SetGameWon(bool);

	// My custom methods
	//bool IsGameActive();
	//int GetCurrentAttemptCount();
	//int GetNthTries();	// How many tries to get successful guess
	void SetCurrentAttemptWord(FString);
	FString GetCurrentAttemptWord() const;
	FString GetSecretWord() const;

private:
	// Class variables, constructor has initialization
	int32 MyCurrentTry;
	int32 MyGameWordLength;
	FString MyCurrentAttemptedWord;
	int32 MyMaxTries;
	bool GameWon;
	bool IsIsogram(FString);	// TODO - Implement IsIsogram
	FString MySecretWord;
	
};