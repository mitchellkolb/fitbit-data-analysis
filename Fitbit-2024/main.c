/*
 * Mitchell Kolb 6/11/2024
 * CptS 122 PA1 - Analyzing Fitbit Data
 *
 * Purpose: This assignment was orginally completed by me on May 18th 2020 and I remember it being the first assignment that was more than just a topic proof of concept. This was an assingment where I actually had a somewhat real life goal in mind to complete. As of 6/11/2024 I've been uploading my projects to github to complete my resume backlog and I thought it would be cool to remake this assignment to see how much I've changed over college since I'm a graduate now.
 * Stats to beat:
 *      How long it took to complete this assignment
 *          2020 - All 7 Days it was available to me before it was due
 *          2024 - 1 day
 *
 *      Is the assignment complete
 *          2020 - Graded as 80/100, I missed some calculations with the 24hr feature and longest poor sleep and outputting results to .csv file
 *          2024 - All complete in 9 hours and 30mins
*                   ✓  Wrong Patient 12cx7
                    ✓  Dups in the Minute
                    ✓  Empty values to be filled
                Notes: //Checks for Correct Patient which appear on lines 27, 1283
                       //Gets rid of dups in the minute column that should appear on lines 53/54, and 149/150 in fitbitdata.csv
                       //Empty values occur massively on lines 383,384,385     442-457    860-917 and most times at the end

 */

#include "equations.h"


#include <stdio.h>
#include <stdlib.h> //Not used i guess
#include <string.h> //Not used i guess

int main(void)
{
    //Opens file descriptor for read
    FILE *file = fopen("FitbitData.csv", "r");
    if (file == NULL) {
        printf("Error opening file, Please Check filepath.\n");
        return 1;
    }
    //Create the struct for data collection and runs the computation
    FitbitData data[1440];
    printf("Struct Created\n");
    readData(&data, file);
    printf("File Analyzed\n");
    fclose(file);
    printf("Fitbit File closed\n");
    writeResults(&data);
    printf("Results Written to Results.csv\n");
    return 0;
}


