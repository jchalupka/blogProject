#ifndef __JCHALUPK_PARSER__
#define __JCHALUPK_PARSER__
void doParse (char* input, int* numTempVars, int* numReplaces, int* numFails, int currentPos, int leftPos, int rightPos);
int changeTemplate (FILE** templateFile, FILE** outFile, int* numTempVars, int* numReplaces, int* numFails);

#endif