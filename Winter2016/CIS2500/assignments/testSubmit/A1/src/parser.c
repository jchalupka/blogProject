#include "../include/parser.h"

/**
 * changeTemplate
 * This function exchanges the variables found in the template file with the variables found in the datafile
 * IN:  templateFile: This is the template file which contains the layout and variables.
        outFile:  This is the   file that will be printed to.
 * OUT: The program will return a 1 if any errors are found, and a zero if it completes succesfully.
 * POST: No side effects.
 * ERROR: If variables are not placed within curly braces they will not be found and replaced.
 */

int changeTemplate (FILE** templateFile, FILE** outFile, int* numTempVars, int* numReplaces, int* numFails)
{
    char input[255];
    /*Read in the template file*/
    
    while (fgets(input, 254, *templateFile) != NULL) {
        //printf("%s",input);
        
        /*A bunch of stuff around parsing*/
        /*Modularize this*/
        
        if (strchr(input, '{') != NULL) {
            int leftPos, rightPos, currentPos;
            currentPos = 0;
            while (input[currentPos] != '\0') {
                if (strlen(input) == 0) {
                    printf("Something went wront!\n");
                    return 1;
                }
                
                if (input[currentPos] ==  '{') {
                    leftPos = currentPos;
                    
                }
                if (input[currentPos] == '}') {
                    rightPos = currentPos;
                    /*Put in a mod here*/
                    doParse(input, numTempVars, numReplaces, numFails, currentPos, leftPos, rightPos);
                    
                }
                currentPos++;
            }
        }
        fprintf(*outFile, "%s",input);
        
        
    }
    return 0;
}

/**
 * doParse
 * doParse handles finding and repacing variable keys with their values.
 * IN: input: The line read in from the template file.
       output:  This variable acts as the variable that is being altered in the input line.
       numTempVars, numReplaces, numFails: Variables to keep track of number of variables, number of succesful replacements, and number of failed replacements.
       leftPos, rightPos:  Keeps track of the positions of the right and left brackets.
       currentPos: Keeps track of where the parser is in the input string as a while loop is being incremented.
 * OUT: void.
 * POST: No side effects.
 * ERROR: If no value is found for the key variable in the template file the value will be made "MISSING_DATA".
 */
void doParse (char* input, int* numTempVars, int* numReplaces, int* numFails, int currentPos, int leftPos, int rightPos)
{
    char output[255];
    
    currentPos = 0;
    *numTempVars = *numTempVars + 1;    //A template variable has been found

    /*Find out what to parse*/
    for (int currentPos = leftPos+1; currentPos < rightPos; currentPos++) {
        output[currentPos-leftPos-1] = input[currentPos];
    }
    output[rightPos-leftPos-1]='\0';    //Make sure the last position is NULL.
    
    
    
    /*Check to see if it actually exists*/
    if (getValue(output)) {     //getValue(output) will return 0 if output is not a key in the hashmap
        *numReplaces = *numReplaces + 1;
        strcpy(output,getValue(output));    //Switch out the key for the value in the hashmap
    }
    else{
        *numFails = *numFails + 1;
        strcpy(output, "MISSING_DATA");    //If the key is not in the hashmap set output to MISSING_DATA
    }

    int replaceLen = (rightPos - leftPos + 1);
    
    currentPos = rightPos+1;
    while (input[currentPos] != '\0'){
        
        input[currentPos-(rightPos - leftPos+1)] = input[currentPos];
        currentPos++;
    }
    input[strlen(input) - replaceLen] = '\0';
    /*Now I am left with the input minus everything in and including brackets*/
    //printf("%s\n",input);
    /*Mod this*/
    currentPos = 0;
    
    int oldLen = strlen(input);
    
    input[strlen(input) + strlen(output)] = '\0';
    input[strlen(input)] = ' ';//Get rid of the old null character
    
    int position = oldLen-1;
    
    
    while (position >= leftPos) {
        
        input[position+strlen(output)] = input[position];
        position--;
    }
    
    position = leftPos;
    while (position < leftPos + strlen(output)) {
        input[position] = output[position - leftPos];
        position++;
    }
}