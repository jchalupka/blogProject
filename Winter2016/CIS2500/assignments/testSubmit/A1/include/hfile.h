#ifndef H_FILE_H
#define H_FILE_H
#include <stdio.h>
#include "uthash.h"
#include "../src/A1_starterfiles/storeval.c"
int functionality (void);
int changeTemplate (FILE** templateFile, FILE** outFile, int* numTempVars, int* numReplaces, int* numFails);
int readData (FILE** dataFile, int* numDataVars);
int readFiles (FILE** templateFile, FILE** dataFile, FILE** outFile, int argc, char** argv);
int successMessage(char* successful, int* numDataVars, int* numTempVars, int* numReplaces, int* numFails);
int successMessage(char* successful, int* numDataVars, int* numTempVars, int* numReplaces, int* numFails);

#endif