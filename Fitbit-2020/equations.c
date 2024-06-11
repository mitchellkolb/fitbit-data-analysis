
/*
Programmer: Mitchell Kolb
Class: CptS 122, Ssummer 2020; Lab Section ##
Programming Assingment: #1
Date: 5/19/2020
Description: This program reads a lot form a files and does som e calculations

             ***ADDITION***
*/

#include "equations.h"


int check_patient(char token)
{
    char temp = "12cx7";
    if (strcmp(token, temp) != 0)
    {
        strcpy(token, "12cx7");
    }
    return token;
}

int check_minute(char token, int FitBitData[])
{
    int temp1, temp2;
    const char s[2] = ":";
    char* finder;
    finder = strtok(token, s);
    temp1 = atoi(finder);
    finder = strtok(NULL, s);
    temp2 = atoi(finder);
    //temp1 is hours, temp2 is minutes.
    temp1 = (temp1 * 60);
    temp2 = (temp1 + temp2);
    if (FitBitData[temp2] != 1)
    {
        //This means its a new minute
        FitBitData[temp2] = 1;
        return 1;
    }
    else
        return 0;
}