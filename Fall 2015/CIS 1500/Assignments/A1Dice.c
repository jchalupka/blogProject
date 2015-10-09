#include <stdio.h>

void showDice();

int main(){
    int num;
    scanf("%d",&num);
    showDice(num);
return 0;
}

void showDice(int num){
    switch(num){
        case 1:
            printf("+-------+\n"
                   "|       |\n"
                   "|   O   |\n"
                   "|       |\n"
                   "+-------+\n");
            break;
        case 2:
            printf("+-------+\n"
                   "| O     |\n"
                   "|       |\n"
                   "|     O |\n"
                   "+-------+\n");
            break;

        case 3:
            printf("+-------+\n"
                   "| O     |\n"
                   "|   O   |\n"
                   "|     O |\n"
                   "+-------+\n");
            break;
        case 4:
            printf("+-------+\n"
                   "| O   O |\n"
                   "|       |\n"
                   "| O   O |\n"
                   "+-------+\n");
            break;
        case 5:
            printf("+-------+\n"
                   "| O   O |\n"
                   "|   O   |\n"
                   "| O   O |\n"
                   "+-------+\n");
            break;
        case 6:
            printf("+-------+\n"
                   "| O   O |\n"
                   "| O   O |\n"
                   "| O   O |\n"
                   "+-------+\n");
            break;
        default:
        printf("Uh-Oh! Something went wrong!\n");
    }
}
