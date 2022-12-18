#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "SettingsScreen.h"

using namespace std;

bool isValidSettingsKey(const char& key){
    if(key!='1' && key!='2' && key!='3' && key!='4' && key!='5' && key!='b') return false;
    return true;
}

void settingsTimer(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char timer;
    cout << setw(58) << setfill(' ') << "Timer" << endl;
    cout << setw(65) << setfill(' ') << "Yes            No" << endl;
    cout << endl;
    cout << setw(58) << setfill(' ') << "b.Back" << endl;
    timer = _getch();
    while(!isValidChoice(timer, 'y') && !isValidChoice(timer, 'n') && !isValidChoice(timer, 'b')){
        cout << "Invalid key. Please try again." << endl;
        timer = _getch();
    }
    if(timer=='y'){
        playBell(checkSound);
        checkTimer = true;
        system("cls");
        cout << setw(90) << setfill(' ') << "               Timer has been activated. Now you can see your played time." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(timer=='n'){
        playBell(checkSound);
        checkTimer = false;
        system("cls");
        cout << setw(68) << setfill(' ') << "Timer has been deactivated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(timer=='b'){
        playSound(checkSound);
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}

void settingsHints(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char hints;
    cout << setw(58) << setfill(' ') << "Hints" << endl;
    cout << setw(65) << setfill(' ') << "Yes            No" << endl;
    cout << endl;
    cout << setw(58) << setfill(' ') << "b.Back" << endl;
    hints = _getch();
    while(!isValidChoice(hints, 'y') && !isValidChoice(hints, 'n') && !isValidChoice(hints, 'b')){
        cout << "Invalid key. Please try again." << endl;
        hints = _getch();
    }
    if(hints=='y'){
        playBell(checkSound);
        checkHints = true;
        system("cls");
        cout << setw(68) << setfill(' ') << "Hints have been activated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(hints=='n'){
        playBell(checkSound);
        checkHints = false;
        system("cls");
        cout << setw(68) << setfill(' ') << "Hints have been deactivated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(hints=='b'){
        playSound(checkSound);
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}

void settingsSound(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char sound;
    cout << setw(58) << setfill(' ') << "Sound" << endl;
    cout << setw(65) << setfill(' ') << "Yes            No" << endl;
    cout << endl;
    cout << setw(58) << setfill(' ') << "b.Back" << endl;
    sound = _getch();
    while(!isValidChoice(sound, 'y') && !isValidChoice(sound, 'n') && !isValidChoice(sound, 'b')){
        cout << "Invalid key. Please try again." << endl;
        sound = _getch();
    }
    if(sound=='y'){
        playBell(checkSound);
        checkSound = true;
        system("cls");
        cout << setw(67) << setfill(' ') << "Sound has been activated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(sound=='n'){
        playBell(checkSound);
        checkSound = false;
        system("cls");
        cout << setw(67) << setfill(' ') << "Sound has been deactivated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(sound=='b'){
        playSound(checkSound);
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}

void settingsGuesses(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char lkey;
    cout << setw(63) << setfill(' ') << "Wrong guesses limit" << endl;
    cout << setw(60) << setfill(' ') << "d.Default(7)" << endl;
    cout << setw(56) << setfill(' ') << "c.Custom" << endl;
    cout << setw(80) << setfill(' ') << "Notes: if the limit is different from default, you wont be able to save your score" << endl;
    cout << endl;
    cout << setw(58) << setfill(' ') << "b.Back" << endl;
    lkey = _getch();
    while(!isValidChoice(lkey, 'd') && !isValidChoice(lkey, 'c') && !isValidChoice(lkey, 'b')){
        cout << "Invalid key. Please try again." << endl;
        lkey = _getch();
    }
    if(lkey=='d'){
        playBell(checkSound);
        MAX_BAD_GUESSES = 7;
        system("cls");
        cout << setw(73) << setfill(' ') << "Wrong guesses limit has been changed to " << MAX_BAD_GUESSES << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(lkey=='c'){
        system("cls");
        cout << setw(67) << "Enter your wrong guesses limit: ";
        cin >> MAX_BAD_GUESSES;
        playBell(checkSound);
        system("cls");
        cout << setw(73) << setfill(' ') << "Wrong guesses limit has been changed to " << MAX_BAD_GUESSES << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(lkey=='b'){
        playSound(checkSound);
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}

void settingsMusic(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char music;
    cout << setw(58) << setfill(' ') << "Music" << endl;
    cout << setw(65) << setfill(' ') << "Yes            No" << endl;
    cout << endl;
    cout << setw(58) << setfill(' ') << "b.Back" << endl;
    music = _getch();
    while(!isValidChoice(music, 'y') && !isValidChoice(music, 'n') && !isValidChoice(music, 'b')){
        cout << "Invalid key. Please try again." << endl;
        music = _getch();
    }
    if(music=='y'){
        playBell(checkSound);
        checkMusic = true;
        system("cls");
        cout << setw(67) << setfill(' ') << "Music has been activated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(music=='n'){
        playBell(checkSound);
        checkMusic = false;
        system("cls");
        cout << setw(67) << setfill(' ') << "Music has been deactivated." << endl;
        cout << endl;
        cout << setw(58) << setfill(' ') << "b.Back" << endl;
        char Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(music=='b'){
        playSound(checkSound);
        SettingsScreen(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
}

void SettingsScreen(bool& checkTimer, bool& ReturnToMenu, bool& checkHints, bool& checkSound, int& MAX_BAD_GUESSES, bool& checkMusic){
    system("cls");
    char settingsKey;
    cout << setw(70) << setfill(' ') << "1.Timer (only works in some modes)" << endl;
    cout << setw(70) << setfill(' ') << "2.Hints (only works in some modes)" << endl;
    cout << setw(43) << setfill(' ') << "3.Sound" << endl;
    cout << setw(57) << setfill(' ') << "4.Wrong guesses limit" << endl;
    cout << setw(43) << setfill(' ') << "5.Music" << endl;
    cout << endl;
    cout << setw(50) << setfill(' ') << "b.Back" << endl;
    settingsKey = _getch();
    while(!isValidSettingsKey(settingsKey)){
        cout << "Invalid key. Please try again." << endl;
        settingsKey = _getch();
    }
    if(isValidChoice(settingsKey, '1')){
        playSound(checkSound);
        settingsTimer(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(settingsKey, '2')){
        playSound(checkSound);
        settingsHints(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(settingsKey, '3')){
        playSound(checkSound);
        settingsSound(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(settingsKey, '4')){
        playSound(checkSound);
        settingsGuesses(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(settingsKey, '5')){////////////
        playSound(checkSound);
        settingsMusic(checkTimer, ReturnToMenu, checkHints, checkSound, MAX_BAD_GUESSES, checkMusic);
    }
    if(isValidChoice(settingsKey, 'b')){
        playSound(checkSound);
        ReturnToMenu = true;
    }
}
