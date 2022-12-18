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
#include "PvP.h"

using namespace std;

//const int MAX_BAD_GUESSES = 9;//////////////////////////////////////////

string getP1word(){
    string p1word;
    cout << "Enter Player 1 word (your word should not have any spaces): ";
    cin >> p1word;
    return p1word;
}

void PvP(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
	string word = getP1word();
	while(word.length()<1){
		cout << "Invalid word. Try again.";
        word = getP1word();
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
        struct tm endPlay = endTime();
        cout << "End Time: ";
        cout << setw(2) << setfill('0') << endPlay.tm_hour << ":";
        cout << setw(2) << setfill('0') << endPlay.tm_min << ":";
        cout << setw(2) << setfill('0') << endPlay.tm_sec << endl;
        calculateTime(checkTimer, startPlay, endPlay);
    }
    cout << endl;
    if(checkPlayAgain()==false){
        ReturnToMenu = true;
        return;
    }
    else{
        PvP(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}
