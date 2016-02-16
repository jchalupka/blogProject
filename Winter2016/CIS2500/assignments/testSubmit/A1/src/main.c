/********************************************************
 CIS 2500
 Jordan Chalupka 0928258
 January 24, 2016
 *********************************************************/
 /**
 * Assignment 1
 * This program replaces variables defined in a template file with replacement variables defined in a data file.  The replaced file is then writen in an output file.
 * IN: Two files: templateFile and dataFile.
 * OUT: One file: outputFile.
 * POST: No side effects.
 * ERROR: Order of file arguements must be consistent with order given in README.  See README for more information.
 */

#include "../include/main.h"
int main (int argc, char** argv)
{
    /*Three files used for other functions*/
    FILE* templateFile, * dataFile, * outFile;
    /*Counters for events that occur in the program*/
    int numDataVars, numTempVars, numReplaces, numFails;
    char successful[50];
    numDataVars = 0, numTempVars = 0, numReplaces = 0, numFails = 0;
    
    /*Assign all of the file variables to files*/
    if(readFiles(&templateFile, &dataFile, &outFile, argc, argv))
    {
        printf("Exiting Program\n");
        exit(1);
    }
    
    /*Assign variables and keys in the dataFile*/
    if(readData(&dataFile, &numDataVars))
    {
        printf("Exiting Program\n");
        exit(1);
    }
    
    /*Apply changes to the template file and show changes in the output file*/
    if (changeTemplate(&templateFile, &outFile, &numTempVars, &numReplaces, &numFails, successful))
    {
        printf("Exiting Program\n");
        exit(1);
    }
    
    /*Print out the outcome of the program*/
    if (successMessage(successful, &numDataVars, &numTempVars, &numReplaces, &numFails)) {
        printf("Exiting Program\n");
        exit(1);
    }
    
    /*Close all of the files*/
    fclose(templateFile);
    fclose(dataFile);
    fclose(outFile);
    
    return 0;
}
