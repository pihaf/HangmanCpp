#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <vector>
#include "draw.h"

using namespace std;

int TIME_LIMIT_displayFinalResult = 10;

const string FIGURE[]={
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };

void renderGame(const string& guessedWord, const string& badGuesses, const string& guesses, string& longGuess, bool& checkTimer, bool& checkHints, struct tm start, const string& word, bool markch[], int& hintcount){
	system("cls");
	int badGuessCount = badGuesses.length();
	if(checkTimer){
        cout << "Start Time: ";
        cout <<  setw(2) << setfill('0') << start.tm_hour << ":";
        cout <<  setw(2) << setfill('0') << start.tm_min << ":";
        cout <<  setw(2) << setfill('0') << start.tm_sec << endl;
    }
    if(checkHints){
        cout << "Hints allow. Type 'hints' to get a hint." << endl;
    }
    if(badGuessCount>7) cout << FIGURE[7] << endl;
	else cout << FIGURE[badGuessCount] << endl;
	cout << "Secret word: " << guessedWord << endl;
	cout << "Your guess was " << guesses << endl;
	if (badGuessCount > 0) {
		cout << "You've made " << badGuessCount << " wrong ";
		cout << (badGuessCount == 1 ? "guess" : "guesses");
		cout << ": " << badGuesses << endl;
	}
    if(longGuess.length()>1){
        if(!checkHints) cout << "You can only guess one character." << endl;
        else if(checkHints && longGuess!="hints") cout << "You can only guess one character." << endl;
        else if(longGuess=="hints" && checkHints){
            char hint = getHint(markch, word);
            cout << "Hint: " << hint << endl;
            hintcount++;
        }
	}
}

char getHint(bool markch[], const string& word){
    vector <char> hintCh;
    char result;
    for(int i=0; i<word.length(); i++){
        if(markch[i]==0) hintCh.push_back(word[i]);
    }
    result = hintCh[0];
    return result;
}

const string& getNextDancingMan(){
    const static string figure[]={
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,


    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

const string& getNextHangMan(){
    const static string figure[]={
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O      \n"
    "   |   /|\\    \n"
    "   |   / \\    \n"
    "   |        \n"
    " -----      \n" ,
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
    "   ------------+     \n"
    "   |      \\         \n"
    "   |      O          \n"
    "   |     /|\\        \n"
    "   |     / \\        \n"
    "   |      \n"
    " -----    \n",
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n"
    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

void displayFinalResult(bool won, const string& word, bool& checkSound){
    while(TIME_LIMIT_displayFinalResult!=0){
        system("cls");
        if(won) cout << "Congratulations! You win! The word was " << word << endl;
        else cout << "You lost. The correct word is " << word << endl;
        cout << (won ? getNextDancingMan() : getNextHangMan());
        this_thread::sleep_for(chrono::milliseconds(300));
        TIME_LIMIT_displayFinalResult--;
    }
    playBell(checkSound);
    TIME_LIMIT_displayFinalResult = 10;
}
