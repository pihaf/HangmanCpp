#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <conio.h>

#include "util.h"
#include "guesser.h"
#include "draw.h"
#include "PvCComputerGuess.h"

using namespace std;

//#define MAX_GUESSES 9 //////////////////////////////////////////

int TIME_LIMIT_displayFinalResultAI = 10;

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

int getUserWordLength(){
    int wordLength;
    cout << "Enter your word length (your word should always have at least one vowel): ";
    cin >> wordLength;
    return wordLength;
}

void initialize(int& wordLength, string& secretWord, int& incorrectGuess, set<char>& previousGuesses, bool& stop){
    wordLength = getUserWordLength();
    secretWord = string(wordLength, '-');
    incorrectGuess = 0;
    previousGuesses = set<char>();
    stop = false;
}

string getUserAnswer(char guess){
    string answer;
    cout << endl << "I guess " << guess << ", please enter your mask: ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return answer;
}

bool isGoodMask(char guess, const string& mask, const string& secretWord){
    if (mask.length() != secretWord.length()) return false;
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-') {
            if (mask[i] != guess)
                return false;
            if (secretWord[i] != '-' && secretWord[i] != mask[i])
                return false;
        }
    return true;
}

void updateSecretWord(const string& mask, string& secretWord){
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-')
            secretWord[i] = mask[i];
}

void update(char guess, const string& mask, int& incorrectGuess, set<char>& previousGuesses, string& secretWord, bool& stop, int& MAX_BAD_GUESSES){
    if (!isGoodMask(guess, mask, secretWord))
        throw invalid_argument("mistake entering answer");

    previousGuesses.insert(guess);
    if (isAllDash(mask)) {
        incorrectGuess ++;
        if (incorrectGuess == MAX_BAD_GUESSES) stop = true;
    } else {
        updateSecretWord(mask, secretWord);
        if (isAllNotDash(secretWord)) stop = true;
    }
}

void render(int incorrectGuess, const set<char>& previousGuesses, const string& secretWord){
    system("cls");
    cout << "Incorrect guess: " << incorrectGuess
         << "   Previous guesses: ";
    for(char c : previousGuesses)
        cout << c;
    cout << "   Secret word: " << secretWord << endl;
    if(incorrectGuess>7) cout << FIGURE[7] << endl;
    else cout << FIGURE[incorrectGuess] << endl;
}

void playAnimation(bool isLosing, const string& word, bool& checkSound){
    system("cls");
    while(TIME_LIMIT_displayFinalResultAI!=0){
        system("cls");
        if (isLosing)
            cout <<  "I lost :(. My best word is: " << word << endl;
        else
            cout <<  "Haha, I win :D. The word is: " << word << endl;
        cout << (isLosing ? getNextHangMan() : getNextDancingMan());
        this_thread::sleep_for(chrono::milliseconds(300));
        TIME_LIMIT_displayFinalResultAI--;
    }
    playBell(checkSound);
    TIME_LIMIT_displayFinalResultAI = 10;
}

void PvCComputerGuessMain(bool& ReturnToMenu, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    int wordLength;
    string secretWord;
    int incorrectGuess;
    set<char> previousGuesses;
    bool stop;
    initialize(wordLength, secretWord, incorrectGuess, previousGuesses, stop);

    render(incorrectGuess, previousGuesses, secretWord);
    do{
        char guess = getNextGuess(previousGuesses, secretWord);
        if(guess == 0){
            cout << "I give up, hang me." << endl;
            break;
        }

        do{
            try{
                string mask = getUserAnswer(guess);
                update(guess, mask, incorrectGuess, previousGuesses, secretWord, stop, MAX_BAD_GUESSES);
                break;
            }catch (std::invalid_argument e){
                cout << "Invalid mask, try again." << endl;
            }
        }while(true);
        render(incorrectGuess, previousGuesses, secretWord);
    }while(!stop);
    playAnimation(incorrectGuess == MAX_BAD_GUESSES, secretWord, checkSound);
    cout << endl;
    if(checkPlayAgain()==false){
        ReturnToMenu = true;
        return;
    }
    else{
        PvCComputerGuessMain(ReturnToMenu, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}
