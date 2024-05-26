/*
Programmer: Mitchell Kolb
Class: CptS 122, Ssummer 2020; Lab Section ##
Programming Assingment: #1
Date: 5/19/2020
Description: This program reads a lot form a files and does som e calculations

             ***ADDITION***
*/


#include "equations.h"


//MAIN CODE
int main()
{
    //starts the file handles for both in and out
    FILE* infile = NULL, * outfile = NULL;

    //opens the file and delcares it as NULL
    infile = fopen("FitbitData.csv", "r");
    outfile = fopen("Results.csv", "w");

    //This means something broke when reading the file.
    if ((infile == NULL)){
        printf("Could not open %s for reading!\n", "FitbitData.csv");
        printf("Exiting program!\n");}
    if ((outfile == NULL)){
        printf("Could not open %s for writing!\n", "Results.csv");
        printf("Exiting program!\n");}
    
    FitbitData fitbits;
    int FitBitData[1440] = { 0 };

    char temp_char[70];
    char* ptr;
    const char s[2] = ",";
    char* token;
    int check = -1;
    int total_calories = 0;
    int total_distance;
    int total_floors;
    double ave_heart;
    int total_steps;
    int max_steps;
    int sleep;


    //Gets the Label line
    fscanf(infile, "%s", &temp_char);
    puts(temp_char);
    
    for (int i = 0; i < 1445; i++)
    {
        //Gets the first line of actual data
        fscanf(infile, "%s", &temp_char);
        //puts(temp_char);

        /* get the first token */
        //Patient
        token = strtok(temp_char, s);
        *token = check_patient(*token);
        strcpy(fitbits.patient, token);

        //Minute
        token = strtok(NULL, s);
        check = check_minute(*token, FitBitData);

        if (check == 1)
        {
            strcpy(fitbits.minute, token);


            //Calories
            token = strtok(NULL, s);
            fitbits.calories = strtod(token, &ptr);
            total_calories += fitbits.calories;


            //Distance
            token = strtok(NULL, s);
            fitbits.distance = strtod(token, &ptr);
            total_distance += fitbits.distance;



            //Floors
            token = strtok(NULL, s);
            fitbits.floors = atoi(token);
            total_floors += fitbits.floors;



            //Heart_rate
            token = strtok(NULL, s);
            fitbits.heartRate = atoi(token);
            ave_heart += fitbits.heartRate;


            //Steps
            token = strtok(NULL, s);
            fitbits.steps = atoi(token);
            total_steps += fitbits.steps;



            //Sleep_level
            token = strtok(NULL, s);
            fitbits.sleepLevel = atoi(token);
        }

        
    }
    ave_heart = (ave_heart / 24);

    printf("\nTotal Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep");
    printf("\n %d, %d, %d, %d, %lf, %d, %d", total_calories, total_distance, total_floors, total_steps, ave_heart, max_steps, sleep);

    fprintf(outfile, "\nTotal Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep");
    fprintf(outfile, "\n%d, %d, %d, %d, %lf, %d, %d", total_calories, total_distance, total_floors, total_steps, ave_heart, max_steps, sleep);
    

    // Close the reference to the input file.
    fclose(infile);
    // Close the reference to the output file.
    fclose(outfile);

    return 0;
}



