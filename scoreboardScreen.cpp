#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <algorithm>
#include "scoreboardScreen.h"

using namespace std;

bool isValidSCChoice(const char& key){
    if(key=='1' || key=='2' || key=='3' || key=='4' || key=='b') return true;
    return false;
}

void ScoreboardScreen(bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints){
    system("cls");
    cout << setw(86) << setfill(' ') << "Note: Scoreboard can only apply to Player vs Computer mode at the moment" << endl;
    cout << setw(52) << setfill(' ') << "1.Easy mode" << endl;
    cout << setw(74) << setfill(' ') << "2.Easy mode(with hints and timer)" << endl;
    cout << setw(52) << setfill(' ') << "3.Hard mode" << endl;
    cout << setw(74) << setfill(' ') << "4.Hard mode(with hints and timer)" << endl;
    cout << endl;
    cout << setw(50) << setfill(' ') << "b.Back" << endl;
    char getKey;
    getKey = _getch();
    while(!isValidSCChoice(getKey)){
        cout << "Invalid key. Please try again." << endl;
        getKey = _getch();
    }
    if(getKey=='1' || getKey=='2' || getKey=='3' || getKey=='4'){
        playBell(checkSound);
        system("cls");
        outputScoreBoard(getKey, ReturnToMenu, checkSound, checkTimer, checkHints);
    }
    if(getKey=='b'){
        playSound(checkSound);
        ReturnToMenu = true;
        return;
    }
}

string getFile(const char& key){
    string file;
    if(key=='1') file = "data/Scoreboard 1.txt";
    else if(key=='2') file = "data/Scoreboard 2.txt";
    else if(key=='3') file = "data/Scoreboard 3.txt";
    else if(key=='4') file = "data/Scoreboard 4.txt";
    return file;
}

void printSecstoTime(const int& secs){
    if(secs>=3600){
        int hour = secs/3600;
        int mins = secs%3600/60;
        int secsLeft  = secs%3600%60;
        if(hour<10) cout << '0' << hour << ":";
        else cout << hour << ":";
        if(mins<10) cout << '0' << mins << ":";
        else cout << mins << ":";
        if(secsLeft<10) cout << '0' << secsLeft;
        else cout << secsLeft;
    }else{
        int mins = secs/60;
        int secsLeft = secs%60;
        if(mins<10) cout << '0' << mins << ":";
        else cout << mins << ":";
        if(secsLeft<10) cout << '0' << secsLeft;
        else cout << secsLeft;
    }
}

void printScoreBoard(const char& key, const vector <string>& inname, const vector <int>& inscore, const vector <int>& index, const vector <int>& timeinsecs, const vector <int>& hints, bool& checkHints, bool& checkTimer){
    if(key=='1' || key=='3'){
        cout << setw(62) << "Name                         Score" << endl;
        for(int i=0; i<inname.size(); i++){
            cout << setw(13) << index[i] << "               " << inname[i] << "                          " << inscore[i] << endl;
        }
    }else if(key=='2' || key=='4'){
        cout << setw(80) << "                            Name                        Score                         Hints                  Time" << endl;
        for(int i=0; i<inname.size(); i++){
            if(inscore[i]>=1000){
                cout << setw(13) << index[i] << "               " << inname[i] << "                          " << inscore[i] << "                           " << hints[i] << "                    ";
                printSecstoTime(timeinsecs[i]);
                cout << endl;
            }else if(inscore[i]<1000 && inscore[i]>=100){
                cout << setw(13) << index[i] << "               " << inname[i] << "                           " << inscore[i] << "                           " << hints[i] << "                    ";
                printSecstoTime(timeinsecs[i]);
                cout << endl;
            }else if(inscore[i]<100 && inscore[i]!=0){
                cout << setw(13) << index[i] << "               " << inname[i] << "                            " << inscore[i] << "                           " << hints[i] << "                    ";
                printSecstoTime(timeinsecs[i]);
                cout << endl;
            }else if(inscore[i]==0){
                cout << setw(13) << index[i] << "               " << inname[i] << "                             " << inscore[i] << "                           " << hints[i] << "                    ";
                printSecstoTime(timeinsecs[i]);
                cout << endl;
            }
        }
    }
}

void SwapElements(int& value1, int& value2, string& name1, string& name2){
    int x;
    string temp;
    x = value1;
    value1 = value2;
    value2 = x;
    temp = name1;
    name1 = name2;
    name2 = temp;
}

void sortScoreBoard(vector <string>& inname, vector <int>& inscore, vector <int>& timeinsecs, vector <int>& hints, bool& checkTimer, bool& checkHints){
    for(int i=0; i<inscore.size()-1; i++){
        for(int j=i+1; j<inscore.size(); j++){
            if(inscore[i]<inscore[j]){
                SwapElements(inscore[i], inscore[j], inname[i], inname[j]);
            }else if(inscore[i]==inscore[j]){
                if(checkHints && checkTimer){
                    if(hints[i]>hints[j]){
                        SwapElements(hints[i], hints[j], inname[i], inname[j]);
                    }else if(hints[i]==hints[j]){
                        if(timeinsecs[i]<timeinsecs[j]){
                            SwapElements(timeinsecs[i], timeinsecs[j], inname[i], inname[j]);
                        }
                    }
                }else if(checkHints && !checkTimer){
                    if(hints[i]>hints[j]){
                        SwapElements(hints[i], hints[j], inname[i], inname[j]);
                    }
                }else if(!checkHints && checkTimer){
                    if(timeinsecs[i]<timeinsecs[j]){
                        SwapElements(timeinsecs[i], timeinsecs[j], inname[i], inname[j]);
                    }
                }
            }
        }
    }
}

void outputScoreBoard(const char& key, bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints){
    /////////////file scoreboard
    if(key=='2' || key=='4'){
        cout << setw(43) << setfill(' ') << "Scoreboard " << key << endl;
        outputCustomSC(key, ReturnToMenu, checkSound, checkTimer, checkHints);
        cout << endl;
        cout << setw(40) << setfill(' ') << "b.Back" << endl;
        char Back;
        Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        if(Back=='b'){
            playSound(checkSound);
            ScoreboardScreen(ReturnToMenu, checkSound, checkTimer, checkHints);
        }
    }
    if(key=='1' || key=='3'){
        cout << setw(43) << setfill(' ') << "Scoreboard " << key << endl;
        outputDefaultSC(key, ReturnToMenu, checkSound, checkTimer, checkHints);
        cout << endl;
        cout << setw(40) << setfill(' ') << "b.Back" << endl;
        char Back;
        Back = _getch();
        while(Back!='b'){
            Back = _getch();
        }
        if(Back=='b'){
            playSound(checkSound);
            ScoreboardScreen(ReturnToMenu, checkSound, checkTimer, checkHints);
        }
    }
}

void outputDefaultSC(const char& key, bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints){
    vector <int> index;
    vector <string> inname;
    vector <int> inscore;
    vector <int> timeinsecs;
    vector <int> hints;
    string filename = getFile(key);
    ifstream inFileScore(filename);
    if(inFileScore.is_open()){
        int countNumberofScore = 1;
        while(!inFileScore.eof()){
            string tempName;
            int x;
            inFileScore >> tempName;
            inFileScore >> x;
            inname.push_back(tempName);
            inscore.push_back(x);
            index.push_back(countNumberofScore);
            countNumberofScore++;
        }
        inname.pop_back();
        inscore.pop_back();
        index.pop_back();
            //print score
            //cout << inname.size() << " " << inscore.size() << endl;
        sortScoreBoard(inname, inscore, timeinsecs, hints, checkTimer, checkHints);
        printScoreBoard(key, inname, inscore, index, timeinsecs, hints, checkTimer, checkHints);
        inFileScore.close();
    }else cout << "Error open file.";
}

void outputCustomSC(const char& key, bool& ReturnToMenu, bool& checkSound, bool& checkTimer, bool& checkHints){
    vector <int> index;
    vector <string> inname;
    vector <int> inscore;
    vector <int> timeinsecs;
    vector <int> hints;
    string filename = getFile(key);
    ifstream inFileScore(filename);
    if(inFileScore.is_open()){
        int countNumberofScore = 1;
        while(!inFileScore.eof()){
            string tempName;
            int x;
            int secs;
            int hintscount;
            inFileScore >> tempName;
            inFileScore >> x;
            inFileScore >> hintscount;
            inFileScore >> secs;
            inname.push_back(tempName);
            inscore.push_back(x);
            timeinsecs.push_back(secs);
            hints.push_back(hintscount);
            index.push_back(countNumberofScore);
            countNumberofScore++;
        }
        timeinsecs.pop_back();
        inname.pop_back();
        inscore.pop_back();
        index.pop_back();
            //print score
            //cout << inname.size() << " " << inscore.size() << endl;
        sortScoreBoard(inname, inscore, timeinsecs, hints, checkTimer, checkHints);
        printScoreBoard(key, inname, inscore, index, timeinsecs, hints, checkTimer, checkHints);
        inFileScore.close();
    }else cout << "Error open file.";
}
