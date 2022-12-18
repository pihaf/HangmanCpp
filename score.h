#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

int calScore(int& hintcount, int badGuessesCount, bool won, const int MAX_BAD_GUESSES, bool& checkTimer, bool& checkHints, struct tm& start, struct tm& endt);
void saveScore(const string& filename, int score, int hintcount, double secs, bool& checkHints, bool& checkTimer);

#endif // SCORE_H_INCLUDED
