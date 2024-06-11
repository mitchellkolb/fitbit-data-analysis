//
// Created by mkolb on 6/11/2024.
//

#ifndef EQUATIONS_H
#define EQUATIONS_H


#include <stdio.h>

typedef enum sleep {
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

void sayHello();
void exitProgram();
int checkDups(FitbitData *data, int index, const char *checkMinute);
void readData(FitbitData *data, FILE *file);
void writeResults(FitbitData *data);


#endif //EQUATIONS_H
