#ifndef FUN_MODE_H_INCLUDED
#define FUN_MODE_H_INCLUDED

#include <iostream>

using namespace std;


void timeLimitMode(bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
void playSound(const bool& checkSound);
bool isValidChoice(const char& key, const char& validKey);
void wordsCategories(bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
void funModeScreen(bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);

#endif // FUN_MODE_H_INCLUDED
