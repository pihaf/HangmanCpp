#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <iostream>
#include <conio.h>
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
    }
}

int main ()
{
    time_t now;
    struct tm startTime;
    double diffinsecs;
    now = time(NULL);
    startTime = *localtime(&now);
    cout << "Date " << startTime.tm_mday << ":" << startTime.tm_mon+1 << ":" << startTime.tm_year+1900 << endl;
    cout << "Time " << startTime.tm_hour << ":" << startTime.tm_min << ":" << startTime.tm_sec << endl;
    char endGame;
    struct tm endTime;
    endGame = _getch();
    if(endGame=='y'){
        now = time(NULL);
        endTime = *localtime(&now);
        cout << "Date " << endTime.tm_mday << ":" << endTime.tm_mon+1 << ":" << endTime.tm_year+1900 << endl;
        cout << "Time " << endTime.tm_hour << ":" << endTime.tm_min << ":" << endTime.tm_sec << endl;
        diffinsecs = difftime(mktime(&startTime), mktime(&endTime));
        cout << "Difference in seconds: " << abs(diffinsecs) << endl;
        printTimeDiff(abs(diffinsecs));
    }
    return 0;
}
