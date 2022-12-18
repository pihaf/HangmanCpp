#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <iostream>

using namespace std;

void renderGame(const string& guessedWord, const string& badGuesses, const string& guesses, string& longGuess, bool& checkTimer, bool& checkHints, struct tm start, const string& word, bool markch[], int& hintcount);
void displayFinalResult(bool won, const string& word, bool& checkSound);
char getHint(bool markch[], const string& word);
void playBell(const bool& checkSound);
const string& getNextHangMan();
const string& getNextDancingMan();

#endif // DRAW_H_INCLUDED
