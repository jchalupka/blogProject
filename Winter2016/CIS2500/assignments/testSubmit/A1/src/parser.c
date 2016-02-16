#include "../include/parser.h"

int changeTemplate (FILE** templateFile, FILE** outFile, int* numTempVars, int* numReplaces, int* numFails, char* successful)
{
    char input[255];
    /*Read in the template file*/
    
    while (fgets(input, 254, *templateFile) != NULL) {
        if (strchr(input, '{') != NULL) { //check if there are any braces in the input
            int leftPos, rightPos, currentPos;
            currentPos = 0;
            while (input[currentPos] != '\0') {
                if (strlen(input) == 0) {
                    printf("Something went wront!\n");
                    return 1;
                }
                if (input[currentPos] ==  '{') {  //Find the positions of the left and right brackets
                    leftPos = currentPos;
                }
                if (input[currentPos] == '}') {
                    rightPos = currentPos;
                    /*doParse will replace what is between the brackets with the matching value in the hash map*/
                    doParse(input, numTempVars, numReplaces, numFails, currentPos, leftPos, rightPos);
                }
                currentPos++;
            }
        }
        fprintf(*outFile, "%s",input);
    }
    
    strcpy( successful,"successful.  ");
    
    return 0;
    
}


void doParse (char* input, int* numTempVars, int* numReplaces, int* numFails, int currentPos, int leftPos, int rightPos)
{
    char output[255];
    
    currentPos = 0;
    *numTempVars = *numTempVars + 1;    //A template variable has been found

    /*Find out what to parse*/
    for (int currentPos = leftPos+1; currentPos < rightPos; currentPos++)
    {
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

    int replaceLen = (rightPos - leftPos + 1);  //Length that must be shifted
    
    currentPos = rightPos + 1;
    
    while (input[currentPos] != '\0'){
        
        input[currentPos-(rightPos - leftPos+1)] = input[currentPos]; //shift everything to the left to remove the key value
        currentPos++;
    }
    
    input[strlen(input) - replaceLen] = '\0';
    /*Now I am left with the input minus everything in and including brackets*/
    currentPos = 0;
    
    int oldLen = strlen(input);
    
    input[strlen(input) + strlen(output)] = '\0';
    input[strlen(input)] = ' ';//Get rid of the old null character
    
    int position = oldLen-1;
    
    /*shift the characters after the left bracket over by the length of the new variable*/
    while (position >= leftPos) {
        input[position+strlen(output)] = input[position];
        position--;
    }
    /*Replace the characters that were shifted with the new variable*/
    position = leftPos;
    while (position < leftPos + strlen(output)) {
        input[position] = output[position - leftPos];
        position++;
    }
}
