#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A1_starterfiles/storeval.c"

char *replace_str(char *str, char*orig, char *rep, int start);

int main(int argc, char **argv)
{
    FILE *templateFile;
    FILE *dataFile;
    FILE *outFile;
    char *input;
    
    if (argc != 4)
    {
        printf("Not correct number of args: (%d)\n",argc);
        exit(1);
    }
    
    templateFile = fopen(argv[1],"r");
    if (templateFile == NULL)
    {
        /*This is the template file*/
        printf("The file does not exist\n");
        exit(1);
    }
    
    dataFile = fopen(argv[2],"r");
    if (dataFile == NULL)
    {
        printf("The file does not exist\n");
        exit(1);
    }
    
    outFile = fopen(argv[3],"w");
    if (outFile == NULL)
    {
        printf("The file does not exist\n");
        exit(1);
    }
    
    
    /*Read in the datafile*/
    while (fgets(input, 254, dataFile) != NULL)
    {
        
            /*Found a variable in the DATAFILE like a dictionary*/
            /*use setValue(const char* key, const char* value)*/
            char *key;
            char *val;
            char *search = "=";
            key = strtok(input, search);
            val = strtok(NULL, search);
            char *pos;
            if ((pos = strchr(val, '\n')) != NULL)
            {
                *pos = '\0';
            }
            setValue(key,val);
            //printf("Key: %s, Val: %s\n", key, val);
        
    }
    int counter;
    char keyWord[20];
    int bracketSpot;
    char stringWord[20];
    int start;
    char *output;
    while (fgets(input, 254, templateFile) != NULL)
    {
        
        for (int z = 0; z < strlen(input); z++){
            
            if (input[z] == '{')
            {
                start = z;
                strcpy(keyWord,"");
                strcpy(stringWord,"");
                counter = 0;
                while (input[z+1] != '}'){
                    keyWord[counter] = input[z+1];
                    counter++;
                    z++;
                }
                keyWord[counter] = '\0';
                /*add a null character*/
                /*This is the finished key word*/
                printf("%s=%s\n",keyWord,getValue(keyWord));
                
                /*
                input = replace_str(input, keyWord, getValue(keyWord),start);
                if(input[z] == '{'){bracketSpot = z;}
                input = replace_str(input,"{", "cow",bracketSpot);
                
                if(input[z] == '}'){bracketSpot = z;}
                input = replace_str(input, "}","b",bracketSpot);
                 */
            }
            //printf("%c\n", input[start]);
            //fprintf(outFile, "%s", input);
        }
    }
    
    fclose(templateFile);
    fclose(dataFile);
    fclose(outFile);
    
    printf("No Errors!\n");
    
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
