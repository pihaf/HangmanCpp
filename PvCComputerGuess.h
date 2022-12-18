#ifndef PVCCOMPUTERGUESS_H_INCLUDED
#define PVCCOMPUTERGUESS_H_INCLUDED

#include <iostream>
#include <set>

using namespace std;

int getUserWordLength();
void initialize(int& wordLength, string& secretWord, int& incorrectGuess, set<char>& previousGuesses, bool& stop);
string getUserAnswer(char guess);
bool isGoodMask(char guess, const string& mask, const string& secretWord);
void updateSecretWord(const string& mask, string& secretWord);
void update(char guess, const string& mask, int& incorrectGuess, set<char>& previousGuesses, string& secretWord, bool& stop);
void render(int incorrectGuess, const set<char>& previousGuesses, const string& secretWord);
void playAnimation(bool isLosing, const string& word);
void PvCComputerGuessMain(bool& ReturnToMenu, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
bool Yes(const char& key);
bool checkPlayAgain();

#endif // PVCCOMPUTERGUESS_H_INCLUDED
