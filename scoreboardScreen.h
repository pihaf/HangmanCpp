#ifndef SCOREBOARDSCREEN_H_INCLUDED
#define SCOREBOARDSCREEN_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

void playSound(const bool& checkSound);
void playBell(const bool& checkSound);
bool isValidSCChoice(const char& key);
void ScoreboardScreen(bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints);
string getFile(const char& key);
void printSecstoTime(const int& secs);
void printScoreBoard(const char& key, const vector <string>& inname, const vector <int>& inscore, const vector <int>& index, const vector <int>& timeinsecs, const vector <int>& hints, bool& checkHints, bool& checkTimer);
void SwapElements(int& value1, int& value2, string& name1, string& name2);
void sortScoreBoard(vector <string>& inname, vector <int>& inscore, vector <int>& timeinsecs, vector <int>& hints, bool& checkTimer, bool& checkHints);
void outputScoreBoard(const char& key, bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints);
void outputCustomSC(const char& key, bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints);
void outputDefaultSC(const char& key, bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints);

#endif // SCOREBOARDSCREEN_H_INCLUDED
