#ifndef PVCPLAYERGUESS_H_INCLUDED
#define PVCPLAYERGUESS_H_INCLUDED

#include <iostream>

using namespace std;

string chooseWord(const string&  fileName);
bool checkFunMode(const string& filename);
string getLowerCaseString(const string& s);
char getHint(bool markch[], const string& word);
bool contains(const string& word, char guess);
void updateGuessedWord(string& guessedWord, const string& word, char guess, bool markch[]);
bool Yes(const char& key);
bool checkSaveScore();
bool checkPlayAgain();
void PvCPlayerGuessMain(const string& filename, bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
struct tm startTime();
struct tm endTime();
void printTimeDiff(double s);
void calculateTime(bool& checkTimer, struct tm start, struct tm endt);

#endif // PVCPLAYERGUESS_H_INCLUDED
