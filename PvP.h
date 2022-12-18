#ifndef PVP_H_INCLUDED
#define PVP_H_INCLUDED

#include <iostream>

using namespace std;

string getP1word();
string getLowerCaseString(const string& s);
char getHint(bool markch[], const string& word);
bool contains(const string& word, char guess);
void updateGuessedWord(string& guessedWord, const string& word, char guess, bool markch[]);
bool Yes(const char& key);
bool checkPlayAgain();
void PvP(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic);
struct tm startTime();
struct tm endTime();
void printTimeDiff(double s);
void calculateTime(bool& checkTimer, struct tm start, struct tm endt);


#endif // PVP_H_INCLUDED
