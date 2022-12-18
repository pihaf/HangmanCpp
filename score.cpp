#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include "score.h"

using namespace std;

int calScore(int& hintcount, int badGuessesCount, bool won, const int MAX_BAD_GUESSES, bool& checkTimer, bool& checkHints, struct tm& start, struct tm& endt){
    int score = 0;
    if(won){
        score += 1000;
        score += (MAX_BAD_GUESSES-badGuessesCount)*100;
        if(checkTimer){
            double secs;
            secs = difftime(mktime(&start), mktime(&endt));
            if(secs<=60){
                score+=1000;
            }else if(secs<=120){
                score+=500;
            }else if(secs>120 && secs<=300) score+=100;
            else if(secs>300) score+=0;
        }
        if(checkHints){
            if(hintcount==7) score = 0;
            else if(hintcount<7){
                score = score - hintcount*100;
            }
        }
    }
    if(score<0) score = 0;
    return score;
}

void saveScore(const string& filename, int score, int hintcount, double secs, bool& checkHints, bool& checkTimer){
    if(filename=="data/Easy.txt"){
        if(!checkHints && !checkTimer){
            ofstream outFile("data/Scoreboard 1.txt", std::ios::app);
            string name;
            cout << "Enter your name (3 letters only) : ";
            cin >> name;
            if(name.length()>3){
                string newname = "";
                newname += name[0]+name[1]+name[2];
                name = newname;
            }else if(name.length()==1){
                name+="..";
            }else if(name.length()==2){
                name+=".";
            }
            if(outFile.is_open()){
                outFile << name << endl;
                outFile << score << endl;;
            }
            outFile.close();
        }
        if(checkHints || checkTimer){
            ofstream outFile("data/Scoreboard 2.txt", std::ios::app);
            string name;
            cout << "Enter your name (3 letters only) : ";
            cin >> name;
            if(name.length()>3){
                string newname = "";
                for(int i=0; i<3; i++){
                    newname += name[i];
                }
                name = newname;
            }else if(name.length()==1){
                name+="..";
            }else if(name.length()==2){
                name+=".";
            }
            if(outFile.is_open()){
                outFile << name << endl;
                outFile << score << endl;
                if(checkHints) outFile << hintcount << endl;
                if(!checkHints) outFile << 0 << endl;
                if(checkTimer) outFile << secs << endl;
                if(!checkTimer) outFile << 0 << endl;
            }
            outFile.close();
        }
    }
 //////////////////////////////////////////////////////////
    if(filename=="data/Hard.txt"){
        if(!checkHints && !checkTimer){
            ofstream outFile("data/Scoreboard 3.txt", std::ios::app);
            string name;
            cout << "Enter your name (3 letters only) : ";
            cin >> name;
            if(name.length()>3){
                string newname = "";
                for(int i=0; i<3; i++){
                    newname += name[i];
                }
                name = newname;
            }else if(name.length()==1){
                name+="..";
            }else if(name.length()==2){
                name+=".";
            }
            if(outFile.is_open()){
                outFile << name << endl;
                outFile << score << endl;;
            }
            outFile.close();
        }
        if(checkHints || checkTimer){
            ofstream outFile("data/Scoreboard 4.txt", std::ios::app);
            string name;
            cout << "Enter your name (3 letters only) : ";
            cin >> name;
            if(name.length()>3){
                string newname = "";
                for(int i=0; i<3; i++){
                    newname += name[i];
                }
                name = newname;
            }else if(name.length()==1){
                name+="..";
            }else if(name.length()==2){
                name+=".";
            }
            if(outFile.is_open()){
                outFile << name << endl;
                outFile << score << endl;
                if(checkHints) outFile << hintcount << endl;
                if(!checkHints) outFile << 0 << endl;
                if(checkTimer) outFile << secs << endl;
                if(!checkTimer) outFile << 0 << endl;
            }
            outFile.close();
        }
    }
}
