#ifndef __JCHALUPK_PARSER__
#define __JCHALUPK_PARSER__

/**
 * changeTemplate
 * This function exchanges the variables found in the template file with the variables found in the datafile
 * IN:  templateFile: This is the template file which contains the layout and variables.
 outFile:  This is the   file that will be printed to.
 * OUT: The program will return a 1 if any errors are found, and a zero if it completes succesfully.
 * POST: No side effects.
 * ERROR: If variables are not placed within curly braces they will not be found and replaced.
 */
int changeTemplate (FILE** templateFile, FILE** outFile, int* numTempVars, int* numReplaces, int* numFails, char* successful);

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
void doParse (char* input, int* numTempVars, int* numReplaces, int* numFails, int currentPos, int leftPos, int rightPos);

#endif
