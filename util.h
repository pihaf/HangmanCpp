#pragma once

#include <vector>
#include <string>

using namespace std;

int generateRandomNumber(int min, int max);
bool isCharInWord(char ch, string word);
vector<string> readWordListFromFile(const string& filePath);
bool isAllDash(const string& s);
bool isAllNotDash(const string& s);
