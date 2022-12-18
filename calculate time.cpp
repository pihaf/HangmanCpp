#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void printTimeDiff(double s){
    int secs = s;
    if(secs>=3600){
        int hour = secs/3600;
        int mins = secs%3600/60;
        int secsLeft  = secs%3600%60;
        cout << "Your time is ";
        cout << hour << ":";
        cout << setw(2) << setfill('0') << mins << ":";
        cout << setw(2) << setfill('0') << secsLeft;
    }else{
        int mins = secs/60;
        int secsLeft = secs%60;
        cout << "Your time is ";
        cout << "00" << ":";
        cout << setw(2) << setfill('0') << mins << ":";
        cout << setw(2) << setfill('0') << secsLeft;
        cout << endl;
    }
}

struct tm startTime(){
    time_t now;
    struct tm startTime;
    now = time(NULL);
    startTime = *localtime(&now);
    return startTime;
}

struct tm endTime(){
    time_t now;
    struct tm endTime;
    now = time(NULL);
    endTime = *localtime(&now);
    return endTime;
}

void calculateTime(bool& checkTimer, struct tm start, struct tm endt){
    if(checkTimer){
        double diffinsecs;
        diffinsecs = difftime(mktime(&start), mktime(&endt));
        printTimeDiff(abs(diffinsecs));
    }else return;
}
