#ifndef __JCHALUPK_FUNCTIONALITY__
#define __JCHALUPK_FUNCTIONALITY__
int readData (FILE** dataFile, int* numDataVars);
int readFiles (FILE** templateFile, FILE** dataFile, FILE** outFile, int argc, char** argv);

#endif