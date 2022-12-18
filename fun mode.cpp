#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <MMsystem.h>
#include "PvCPlayerGuess.h"
#include "draw.h"
#include "fun mode.h"

using namespace std;

void timeLimitMode(bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char option;
    string filename;
    cout << setw(63) << setfill(' ') << "Guess words with time limit" << endl;
    cout << setw(63) << setfill(' ') << "d.Default (30s)" << endl;
    cout << setw(63) << setfill(' ') << "c.Custom" << endl;
    cout << endl;
    cout << setw(63) << setfill(' ') << "b.Back" << endl;
    option = _getch();
    while(!isValidChoice(option , 'd') && !isValidChoice(option , 'c') && !isValidChoice(option , 'b')){
        cout << "Invalid key. Please try again." << endl;
        option = _getch();
    }
    if(isValidChoice(option, 'd')){
        playSound(checkSound);
        filename = "data/Random.txt";
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(option, 'c')){
        playSound(checkSound);
        filename = "data/Random.txt";
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(option, 'b')){
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }
}

void wordsCategories(bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    cout << setw(65) << setfill(' ') << "Choose word categories" << endl;
    cout << setw(55) << setfill(' ') << "1.Food" << endl;
    cout << setw(56) << setfill(' ') << "2.Music" << endl;
    cout << setw(58) << setfill(' ') << "3.Objects" << endl;
    cout << endl;
    cout << setw(55) << setfill(' ') << "b.Back" << endl;
    char getKey;
    string filename;
    getKey = _getch();
    while(getKey!='1' && getKey!='2' && getKey!='3' && getKey!='b'){
        cout << "Invalid key. Please try again." << endl;
        getKey = _getch();
    }
    if(isValidChoice(getKey, '1')){
        playSound(checkSound);
        filename = "data/Food.txt";
        if(checkMusic) PlaySound(TEXT("C:\\Users\\DEll\\Desktop\\Things\\Code\\Hangman\\data\\HopesAndDreamsUndertaleOST-TobyFox-4536106.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
        PlaySound(0,0,0);
    }
    if(isValidChoice(getKey, '2')){
        playSound(checkSound);
        filename = "data/Music.txt";
        if(checkMusic) PlaySound(TEXT("C:\\Users\\DEll\\Desktop\\Things\\Code\\Hangman\\data\\HopesAndDreamsUndertaleOST-TobyFox-4536106.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
        PlaySound(0,0,0);
    }
    if(isValidChoice(getKey, '3')){
        playSound(checkSound);
        filename = "data/Objects.txt";
        if(checkMusic) PlaySound(TEXT("C:\\Users\\DEll\\Desktop\\Things\\Code\\Hangman\\data\\HopesAndDreamsUndertaleOST-TobyFox-4536106.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
        PlaySound(0,0,0);
    }
    if(isValidChoice(getKey, 'b')){
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }
}

void funModeScreen(bool& checkTimer, bool& ReturnToMenu, bool& checkSrand, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    cout << setw(65) << setfill(' ') << "1.Guess words by categories               " << "2.Guess words with Vietnamese descriptions" << endl;
    cout << endl;
    cout << setw(60) << setfill(' ') << "b.Back" << endl;
    char getMode;
    getMode = _getch();
    while(getMode!='1' && getMode!='2' && getMode!='b'){
        cout << "Invalid key. Please try again." << endl;
        getMode = _getch();
    }
    if(isValidChoice(getMode, '1')){
        playSound(checkSound);
        wordsCategories(checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(getMode, '2')){
        playSound(checkSound);
        system("cls");
        cout << "Sorry, this mode is being fixed." << endl;
        ReturnToMenu = true;
        return;
        /////////////////
    }
    if(isValidChoice(getMode, 'b')){
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }
}
