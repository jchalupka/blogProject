#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A1_starterfiles/storeval.c"
char *replace_str(char *str, char *orig, char *rep, int start);
int main (int argc, char **argv)
{
    FILE *templateFile, *dataFile, *outFile;
    templateFile = fopen(argv[1], "r");
    
    dataFile = fopen(argv[2], "r");
    
    outFile = fopen(argv[3], "w");
    
    char input[255];
    
    while (fgets(input,254,dataFile) != NULL)
    {
        char *key, *val, *search, *pos;
        search = "=";
        key = strtok(input, search);
        val = strtok(NULL, search);
        
        if ((pos = strchr(val, '\n')) != NULL)
        {
            *pos = '\0';
        }
        
        setValue(key, val);
    }
    
    int start, counter, bracketSpot;
    char keyWord[40], stringWord[40];
    while (fgets(input, 254, templateFile) != NULL)
    {
        for (int z = 0; z <= strlen(input); z++){
            if (input[z] == '{'){
                start = z;
                strcpy(keyWord,"");
                strcpy(stringWord,"");
                counter = 0;
                while (input[z+1] != '}'){
                    keyWord[counter] = input[z+1];
                    counter++;
                    z++;
                }
                printf("%c\n", keyWord[counter]);
            keyWord[counter] = '\0';
                
                
            }
           
        }
        
    }
    fclose(templateFile);
    fclose(dataFile);
    fclose(outFile);
    
    return 0;
}

char *replace_str(char *str, char *orig, char *rep, int start)
{
    static char temp[100];
    static char buffer[100];
    char *p;
    
    strcpy(temp, str + start);
    
    if(!(p = strstr(temp,orig)))
    {
        return temp;
    }
    strncpy(buffer, temp, p-temp);
    buffer[p-temp] = '\0';
    
    sprintf(buffer + (p-temp), "%s%s", rep,p + strlen(orig));
    sprintf(str + start, "%s", buffer);
    
    return str;
    
}
