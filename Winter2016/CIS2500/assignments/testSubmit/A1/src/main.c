/********************************************************
 CIS 2500 Assignment 1
 Jordan Chalupka
 January 24, 1016
 This program reads variables and names from a data file, 
 makes alterations to a template file, 
 and outputs the results to an output file.
*********************************************************/

#include "../include/moded.h"
int main (int argc, char** argv)
{
    /*Three files used for other functions*/
    FILE* templateFile, * dataFile, * outFile;
    /*Counters for events that occur in the program*/
    int numDataVars, numTempVars, numReplaces, numFails;
    numDataVars = 0, numTempVars = 0, numReplaces = 0, numFails = 0;
    
    if(readFiles(&templateFile, &dataFile, &outFile, argc, argv))
    {
        printf("Exiting Program1\n");
        exit(1);
    }
    
    if(readData(&dataFile, &numDataVars))
    {
        printf("Exiting Program2\n");
        exit(1);
    }
    
    /*This is too broad*/
    if (changeTemplate(&templateFile, &outFile, &numTempVars, &numReplaces, &numFails))
    {
        printf("Exiting Program3\n");
        exit(1);
    }
    
    char* successful = "successful.  ";
    if (successMessage(successful, &numDataVars, &numTempVars, &numReplaces, &numFails)) {
        printf("Exiting Program4\n");
        exit(1);
    }
    
    fclose(templateFile);
    fclose(dataFile);
    fclose(outFile);
    
    return 0;
}

