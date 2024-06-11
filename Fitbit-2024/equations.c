//
// Created by mkolb on 6/11/2024.
//

#include "equations.h"


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This function is to test out output
void sayHello() {
    printf("Mitchell Test!\n");
}

//Closes program
void exitProgram() {
    printf("Exiting the program.\n");
}

// Function to check for duplicate minute values
int checkDups(FitbitData *data, int index, const char *checkMinute) {
    if (index > 1 && strcmp(data[index - 1].minute, checkMinute) == 0) {
        //printf("dup index: %d\n", index);
        return 1; //If this returns 1 that means there is a dup in the minutes. I don't want that to occur.
    }
    return 0;
}

void readData(FitbitData *data, FILE *file) {

    char line[256];//For *file to get current line
    int index = 0;//To keep track of the array that we're in for data struct
    int skipped = 0;//I wanted to display the number of lines in the file skipped
    char saved[8][20];//Along with number skipped this stores the strings of the ones that are skipped
    int nextSaved = 0;//int to hold the next empty space in saved[][]

    // Read the first line and print it
    if (fgets(line, 256, file)) {
        printf("Columns: %s", line);
    }

    while (fgets(line, sizeof(line), file)) {
        if (index >= 1440) break; // don't go past array bounds
        int recordSkip = 0; //To trigger the if to record the skip if a row is skipped
        char wasSkipped[10];


        // Verify the contents of the line
        char checkPatient[10], checkMinute[9];
        double calories = -1.0, distance = -1.0;
        int floors = -1, heartRate = -1, steps = -1;
        Sleep sleepLevel = NONE;

        // Parse the line
        sscanf(line, "%9[^,],%8[^,],%lf,%lf,%d,%d,%d,%d",
               checkPatient, checkMinute, &calories, &distance, &floors, &heartRate, &steps, (int*)&sleepLevel);
        // Checks for Correct Patient
        if (strcmp(checkPatient, "12cx7") == 0) {

            // Gets rid of dups in the minute column
            if (checkDups(data, index, checkMinute) == 0) {

                strcpy(data[index].patient, checkPatient);
                strcpy(data[index].minute, checkMinute);

                data[index].calories = (calories >= 0) ? calories : 0;
                data[index].distance = (distance >= 0) ? distance : 0;
                data[index].floors = (floors >= 0) ? floors : 9999;
                data[index].heartRate = (heartRate >= 0) ? heartRate : 9999;
                data[index].steps = (steps >= 0) ? steps : 9999;
                data[index].sleepLevel = (sleepLevel >= NONE && sleepLevel <= REALLYAWAKE) ? sleepLevel : NONE;
            }
            else {
                //Minute value is not right which means its probably a duplicate so lets skip it
                recordSkip = 1;
                strcpy(wasSkipped, "Dup Min");
                //If not minute is a duplicate then the indice is repeated again
                index--;
            }
        }
        else {
            //Patient value is not right so lets skip it
            recordSkip = 1;
            strcpy(wasSkipped, checkPatient);
            //If not right patient 12cx7 then the indice is repeated again
            index--;
        }
        if(recordSkip == 1) {
            // --- This adds the skipped rows only for the Patient value to an array so I can view it ---
            char tempString[20], tempLineNumStr[10];
            // Putting line word into the array
            strcpy(tempString, "Line ");
            //Typecasting int index to char then adds it to array
            sprintf(tempLineNumStr, "%d", (index + skipped));
            //Concat "Line " and Index number together
            strcat(tempString, tempLineNumStr);
            //Add it to the array
            strcpy(saved[nextSaved], tempString);
            nextSaved++;
            //Putting what was skipped as a string into the array
            strcpy(saved[nextSaved], wasSkipped);
            nextSaved++;
            //Adding 1 to the skipped count. Each count has two items added. (line number and what was skipped)
            skipped++;
            // ---
        }

        index++;
    }
    printf("---\n");
    for (int i = 0; i < 8; i=i+2) {
        printf("Around %s  -  %s\n", saved[i], saved[i+1]);
    }

    printf("Skipped: %d\nFinal Min: %s\n", skipped, data[1439].minute);
    printf("---\n");
}

void writeResults(FitbitData *data) {
    double totalCalories = 0.0;
    double totalDistance = 0.0;
    unsigned int totalFloors = 0;
    unsigned int totalSteps = 0;
    unsigned int totalHeartRate = 0;
    unsigned int heartRateCount = 0;
    unsigned int maxSteps = 0;
    int maxStepsMinute = 0;
    int poorSleepStart = -1;
    int poorSleepEnd = -1;


    // In the loop where totals and maximums are calculated
    for (int i = 0; i < 1440; i++) {
        totalCalories += data[i].calories;
        totalDistance += data[i].distance;
        totalFloors += data[i].floors;
        totalSteps += data[i].steps;

        if (data[i].heartRate > 0 && data[i].heartRate != 9999) {
            totalHeartRate += data[i].heartRate;
            heartRateCount++;
        }

        if (data[i].steps > maxSteps && data[i].steps != 9999) {
            maxSteps = data[i].steps;
            maxStepsMinute = i;
        }

        if (data[i].sleepLevel == 3) {
            if (poorSleepStart == -1) {
                poorSleepStart = i;
            }
            poorSleepEnd = i;
        }
    }

    // Calculation of the average heart rate remains the same
    double averageHeartRate = (heartRateCount > 0) ? (double) totalHeartRate / heartRateCount : 0.0;

    // Open results.csv for writing
    FILE *results_file = fopen("results.csv", "w");
    if (results_file == NULL) {
        printf("Failed to open results.csv for writing\n");
        return;
    }

    // Write the header and values to the CSV file
    fprintf(results_file, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Total Steps, Sleep\n");
    fprintf(results_file, "%.2f, %.2f, %u, %u, %.2f, %u, %s:%s\n",
            totalCalories, totalDistance, totalFloors, totalSteps,
            averageHeartRate, maxSteps,
            data[poorSleepStart].minute, data[poorSleepEnd].minute);

    // Close the file
    fclose(results_file);

    // Print the results to the screen
    printf("Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Total Steps, Sleep\n");
    printf("%.2f, %.2f, %u, %u, %.2f, %u, %s:%s\n",
           totalCalories, totalDistance, totalFloors, totalSteps,
           averageHeartRate, maxSteps,
           data[poorSleepStart].minute, data[poorSleepEnd].minute);

    printf("Data successfully exported to results.csv\n");
}
