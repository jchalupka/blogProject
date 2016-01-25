#include "../include/success.h"
/**
 * successMessage
 * Prints a message to the user that tells them how successful the program was
 * IN: successful: Tells the user if the program ran successfully.
       numDataVars:  Number of variables in the data file.
       numTempVars:  Number of variables in the template file.
       numReplaces:  Number of successful variable replacements made.
       numFails:  Number of failed replacements made.
 * OUT: Returns an int that tells the user if the function was succesful or not.
 * POST: No side effects.
 * ERROR: No found errors.
 */
int successMessage(char* successful, int* numDataVars, int* numTempVars, int* numReplaces, int* numFails)
{
        printf("\n************************************************\n"
           "* The program was %s                *\n"
           "* Number of variables found in DataFile: %d     *\n"
           "* Number of variables found in TemplateFile: %d *\n"
           "* Number of succesful variable replacements: %d *\n"
           "* Number of failed variable replacements: %d    *\n"
           "************************************************\n"
           ,successful, *numDataVars, *numTempVars, *numReplaces, *numFails);
    printf("\n");
    
    return 0;
}