#include "../include/functionality.h"

/**
 * readData
 * Reads data in from the data file and records the number of data variables.
 * IN: dataFile: A pointer to a file that will holds the data.
       numDataVars:  Number of variables found in the data file.
 * OUT:  Returns a 1 if an error is found, a zero otherwise.
 * POST: No side effects.
 * ERROR: No known errors.
 */
int readData (FILE** dataFile, int* numDataVars)
{
    char input[255];
    *numDataVars = 0;
    while (fgets(input,254, *dataFile) != NULL)
    {
        char *key, *val, *search, *pos;
        search = "=";
        key = strtok(input, search);
        
        val = strtok(NULL, "\n");
        
        if ((pos = strchr(val, '\n')) != NULL)
        {
            *pos = '\0';
        }
        //printf("Key: %s Value: %s\n",key, val);
        setValue(key, val);
        *numDataVars = *numDataVars+1;
    }
    
    return 0;

}

/**
 * readFiles
 * Assigns all of the files to file type variables and checks for errors.
 * IN: templateFile: File to hold the text from the template file.
       dataFile:  File to hold the text from the data file.
       outFile:  File to hold the text that will be the output.
       argc:  The number of arguments.
       argv:  An array of string arguements.
 * OUT: Returns a 1 if any errors are found, and zero otherwise.
 * POST: No side effects found.
 * ERROR: Checks to see the correct number of arguements have been entered and that all files exist.
 */
int readFiles (FILE** templateFile, FILE** dataFile, FILE** outFile, int argc, char** argv)
{
    if (argc != 4)
    {
        printf("Not correct number of files: %d instead of 3\n",argc-1);
        return 1;
    }
    
    /*Open all of the files*/
    
    *templateFile = fopen(argv[1],"r");
    
    if (*templateFile == NULL)
    {
        printf("The file does not exist\n");
        return 1;
    }
    
    *dataFile = fopen(argv[2],"r");
    if (*dataFile == NULL)
    {
        printf("The file does not exist\n");
        return 1;
    }
    
    *outFile = fopen(argv[3],"w+");
    if (*outFile == NULL)
    {
        printf("The file does not exist\n");
        return 1;
    }
    
    return 0;
}