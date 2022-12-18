#ifndef CALCULATE_TIME_H_INCLUDED
#define CALCULATE_TIME_H_INCLUDED

#include <iostream>

using namespace std;

struct tm startTime();
struct tm endTime();
void printTimeDiff(double s);
void calculateTime(bool& checkTimer, struct tm start, struct tm endt);

#endif // CALCULATE_TIME_H_INCLUDED
