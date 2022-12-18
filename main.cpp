#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <MMsystem.h>
#include "draw.h"
#include "PvCPlayerGuess.h"
#include "PvCComputerGuess.h"
#include "PvP.h"
#include "calculate time.h"
#include "SettingsScreen.h"
#include "scoreboardScreen.h"
#include "score.h"
#include "fun mode.h"

using namespace std;

bool ReturnToMenu = false;
bool endGame = false;
bool checkMusic = true;
bool checkSound = true;
bool checkTimer = false;
bool checkHints = false;
bool checkSrand = false;
int timeLimit = 30;
int MAX_BAD_GUESSES = 7;/////////////////////////////////////////////////
const char DATA_FILE[] = "Random.txt";

bool isValidFirstScreenKey(const char& key);
bool isValidGameMode(const char& key);
bool isValidChoice(const char& key, const char& validKey);
bool Yes(const char& key);
void PvC();
void GameModeChoice();
void FirstScreenAnimation();
void MenuScreen();
void playSound(const bool& checkSound);
void playBell(const bool& checkSound);
void difficultyChoice(string& filename);

void playSound(const bool& checkSound){
    if(checkSound){
        Beep(150, 200);
    }
}

void playBell(const bool& checkSound){
    if(checkSound){
        cout << '\a';
    }
}

bool isValidMenuScreenKey(const char& key){
    if(key!='p' && key!='e' && key!='s' && key!='b') return false;
    return true;
}

bool isValidGameMode(const char& key){
    if(key=='1' || key=='2' || key=='b') return true;
    return false;
}

bool isValidChoice(const char& key, const char& validKey){
    if(key==validKey) return true;
    return false;
}

bool Yes(const char& key){
    if(key=='y') return true;
    if(key=='n') return false;
}

void difficultyChoice(string& filename){
    system("cls");
    cout << setw(61) << setfill(' ') << "Player vs Computer" << endl;
    cout << setw(58) << setfill(' ') << "Player Guess" << endl;
    cout << setw(30) << setfill(' ') << "e.Easy" << "                 " << "h.Hard" << "            " << "f.Fun mode" << endl;
    cout << endl;
    cout << setw(49) << setfill(' ') << "b.Back" << endl;
    char difficultyKey;
    difficultyKey = _getch();
    while(!isValidChoice(difficultyKey, 'e') && !isValidChoice(difficultyKey, 'h') && !isValidChoice(difficultyKey, 'b') && !isValidChoice(difficultyKey, 'f')){
        cout << "Invalid key. Please try again." << endl;
        difficultyKey = _getch();
    }
    if(isValidChoice(difficultyKey, 'e')){
        playSound(checkSound);
        filename = "data/Easy.txt";
    }
    if(isValidChoice(difficultyKey, 'h')){
        playSound(checkSound);
        filename = "data/Hard.txt";
    }
    if(isValidChoice(difficultyKey, 'f')){
        playSound(checkSound);
        funModeScreen(checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(difficultyKey, 'b')){
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }
}

void PvC(){
    system("cls");
    cout << setw(61) << setfill(' ') << "Player vs Computer" << endl;
    cout << setw(40) << setfill(' ') << "1.Player Guess" << "                         " << "2.Computer Guess" << endl;
    cout << endl;
    cout << setw(49) << setfill(' ') << "b.Back" << endl;
    char guessChoicePvC;
    guessChoicePvC = _getch();
    string filename;
    while(!isValidChoice(guessChoicePvC, '1') && !isValidChoice(guessChoicePvC, '2') && !isValidChoice(guessChoicePvC, 'b')){
        cout << "Invalid key. Please try again." << endl;
        guessChoicePvC = _getch();
    }
    if(isValidChoice(guessChoicePvC, '1')){
        playSound(checkSound);
        system("cls");
        difficultyChoice(filename);
        if(ReturnToMenu) return;
        if(checkMusic) PlaySound(TEXT("C:\\Users\\DEll\\Desktop\\Things\\Code\\Hangman\\data\\HopesAndDreamsUndertaleOST-TobyFox-4536106.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
        PvCPlayerGuessMain(filename, checkTimer, ReturnToMenu, checkSrand, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
        PlaySound(0,0,0);
    }
    if(isValidChoice(guessChoicePvC, '2')){////////////////////////////////////
        playSound(checkSound);
        system("cls");
        if(checkMusic) PlaySound(TEXT("C:\\Users\\DEll\\Desktop\\Things\\Code\\Hangman\\data\\HopesAndDreamsUndertaleOST-TobyFox-4536106.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
        PvCComputerGuessMain(ReturnToMenu, checkSound, MAX_BAD_GUESSES, checkMusic);
        PlaySound(0,0,0);
    }
    if(isValidChoice(guessChoicePvC, 'b')){////////////////////////////////////
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }
}

void GameModeChoice(){
    system("cls");
    cout << setw(59) << setfill(' ') << "Choose Gamemode" << endl;
    cout << setw(40) << setfill(' ') << "1.Player vs Computer" << "                         " << "2.Player vs Player" << endl;
    cout << endl;
    cout << setw(50) << setfill(' ') << "b.Back" << endl;
    char GameModeKey;
    GameModeKey = _getch();
    while(!isValidGameMode(GameModeKey)){
        cout << "Invalid key. Please try again." << endl;
        GameModeKey = _getch();
    }
    if(isValidChoice(GameModeKey, '1')){
        playSound(checkSound);
        PvC();
    }
    if(isValidChoice(GameModeKey, '2')){
        playSound(checkSound);
        system("cls");
        if(checkMusic) PlaySound(TEXT("C:\\Users\\DEll\\Desktop\\Things\\Code\\Hangman\\data\\HopesAndDreamsUndertaleOST-TobyFox-4536106.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
        PvP(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
        PlaySound(0,0,0);
    }
    if(isValidChoice(GameModeKey, 'b')){
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }

}

void FirstScreenAnimation(){
    int TIME_LIMIT_FIRST_SCREEN = 20;
    while(TIME_LIMIT_FIRST_SCREEN!=0){
        system("cls");
        cout << setw(65) << setfill(' ') << "Hangman the Game" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        TIME_LIMIT_FIRST_SCREEN--;
    }
}

void MenuScreen(){
    char MenuScreenKey;
    system("cls");
    cout << setw(65) << setfill(' ') << "Hangman the Game" << endl;
    cout << setw(59) << setfill(' ') << "p.Play" << endl;
    cout << setw(65) << setfill(' ') << "b.Scoreboard" << endl;
    cout << setw(63) << setfill(' ') << "s.Settings" << endl;
    cout << setw(59) << setfill(' ') << "e.Exit" << endl;
    MenuScreenKey = _getch();
    while(!isValidMenuScreenKey(MenuScreenKey)){
        cout << "Invalid key. Please try again." << endl;
        MenuScreenKey = _getch();
    }
    if(isValidChoice(MenuScreenKey, 'p')){
        playSound(checkSound);
        GameModeChoice();
    }
    if(isValidChoice(MenuScreenKey, 'e')){
        playSound(checkSound);
        endGame = true;
    }
    if(isValidChoice(MenuScreenKey, 's')){
        playSound(checkSound);
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(MenuScreenKey, 'b')){
        playSound(checkSound);
        ScoreboardScreen(ReturnToMenu, checkSound, checkTimer, checkHints);
    }
}
////////////////
/////////////////

int main(){
    FirstScreenAnimation();
    MenuScreen();
    while(!endGame){
        if(ReturnToMenu){
            ReturnToMenu = false;
            MenuScreen();
        }
    }
    if(endGame){
        endGame = false;
        return 0;
    }
}

