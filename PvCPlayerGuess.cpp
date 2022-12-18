#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <time.h>
#include <string>
#include "draw.h"
#include "PvCPlayerGuess.h"
#include "scoreboardScreen.h"
#include "score.h"

using namespace std;

//const int MAX_BAD_GUESSES = 9;//////////////////////////////////////////////////

bool checkSaveScore(){
    char key;
    cout << "Do you want to save your score? y/n" << endl;
    key = _getch();
    while(key!='y' && key!='n'){
        cout << "Invalid key. Please try again." << endl;
        key = _getch();
    }
    if(Yes(key)) return true;
    if(!Yes(key)) return false;
}

bool checkPlayAgain(){
    char key;
    cout << "Play again? y/n" << endl;
    key = _getch();
    while(key!='y' && key!='n'){
        cout << "Invalid key. Please try again." << endl;
        key = _getch();
    }
    if(Yes(key)) return true;
    if(!Yes(key)) return false;
}

bool checkFunMode(const string& filename){
    if(filename=="data/Food.txt" || filename=="data/Music.txt" || filename=="data/Objects.txt" || filename=="data/Random.txt") return true;
    return false;
}

void PvCPlayerGuessMain(const string& filename, bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
	if(!checkSrand) srand(time(0));
	string word = chooseWord(filename);
	if(word.length()<1){
		cout << "Error reading vocabulary file " << filename;
	}
	string guessedWord = string(word.length(), '-');
	string badGuesses = "";
	string guesses = "";
	string longGuess = "";
	bool markch[word.length()];
	for(int i=0; i<word.length(); i++){ //khoi tao mang danh dau phan tu
        markch[i] = 0;
	}
    struct tm startPlay = startTime();
    struct tm endPlay;
    int hintcount = 0;

    do {
        char guess;
		renderGame(guessedWord, badGuesses, guesses, longGuess, checkTimer, checkHints, startPlay, word, markch, hintcount);
		guesses = "";
		cin >> longGuess;
		if(longGuess.length()>1) continue;//neu nhap 1 chuoi se in lai man hinh cu kem thong bao
		if(longGuess.length()==1) guess = longGuess[0];
		if(contains(word, guess)) updateGuessedWord(guessedWord, word, guess, markch);
		else{
			badGuesses += guess;
		}
		guesses+=guess;//co the dung set
	}while(badGuesses.length()<MAX_BAD_GUESSES && word!=guessedWord);
    displayFinalResult(badGuesses.length()<MAX_BAD_GUESSES, word, checkSound);
    if(checkTimer){
        cout << "Start Time: ";
        cout <<  setw(2) << setfill('0') << startPlay.tm_hour << ":";
        cout <<  setw(2) << setfill('0') << startPlay.tm_min << ":";
        cout <<  setw(2) << setfill('0') << startPlay.tm_sec << endl;
        endPlay = endTime();
        cout << "End Time: ";
        cout << setw(2) << setfill('0') << endPlay.tm_hour << ":";
        cout << setw(2) << setfill('0') << endPlay.tm_min << ":";
        cout << setw(2) << setfill('0') << endPlay.tm_sec << endl;
        calculateTime(checkTimer, startPlay, endPlay);
    }
    if(checkHints) cout << "Hints used: " << hintcount << endl;
    int score = calScore(hintcount, badGuesses.length(), badGuesses.length()<MAX_BAD_GUESSES, MAX_BAD_GUESSES, checkTimer, checkHints, startPlay, endPlay);
    if((badGuesses.length()==0 && hintcount!=0) || MAX_BAD_GUESSES!=7) score = 0;
    if(MAX_BAD_GUESSES==7){
        cout << "Your score is: " << score;/////////////////////////////
        cout << endl;
        if(!checkFunMode(filename)){
            if(checkSaveScore()==true){
                saveScore(filename, score, hintcount, abs(difftime(mktime(&startPlay), mktime(&endPlay))), checkHints, checkTimer);
            }
        }
    }
    cout << endl;
    if(checkPlayAgain()==false){
        ReturnToMenu = true;
        return;
    }
    else{
        checkSrand = true;
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}

string getLowerCaseString(const string& s){
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}

string chooseWord(const string& fileName){
	vector<string> wordList;
	ifstream file(fileName);
  	if(file.is_open()){
	    string word;
		while(file >> word){
            wordList.push_back(word);
        }
    	file.close();
  	}else return "Error file";//check bug
  	if(wordList.size()>0){
  		int randomIndex = rand() % wordList.size();
    	return getLowerCaseString(wordList[randomIndex]);
	}else return "";//check bug
}

bool contains(const string& word, char c){
	return(word.find_first_of(c) != string::npos);
}

void updateGuessedWord(string& guessedWord, const string& word, char guess, bool markch[]){
	for (int i=word.length()-1; i>=0; i--){
        if(word[i] == guess){
            guessedWord[i] = guess;
            markch[i] = 1;
        }
    }
}
