


/*
Programmer: Mitchell Kolb
Class: CptS 122, Ssummer 2020; Lab Section ##
Programming Assingment: #1
Date: 5/19/2020
Description: This program reads a lot form a files and does som e calculations 

             ***ADDITION***
*/

//LIBRARIES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()
#include <string.h> //string stuff

//Structs
typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;

typedef struct fitbit
{
    char patient[10]; 
    char minute[9]; 
    double calories; 
    double distance; 
    unsigned int floors; 
    unsigned int heartRate; 
    unsigned int steps; 
    Sleep sleepLevel; 
}FitbitData;


//DEFFINITIONS FOR VALUES

//FUNCTION DELCARATIONS FOR PA
int check_patient(char token);
int check_minute(char token, int FitBitData[]);