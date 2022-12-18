#ifndef SETTINGSSCREEN_H_INCLUDED
#define SETTINGSSCREEN_H_INCLUDED

#include <iostream>

using namespace std;

void playSound(const bool& checkSound);
void playBell(const bool& checkSound);
bool isValidSettingsKey(const char& key);
bool isValidChoice(const char& key, const char& validKey);
void settingsTimer(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, int& MAX_BAD_GUESSES, bool& checkMusic);
void settingsHints(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, int& MAX_BAD_GUESSES, bool& checkMusic);
void settingsSound(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
void settingsGuesses(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
void settingsMusic(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
void SettingsScreen(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);

#endif // SETTINGSSCREEN_H_INCLUDED
