#include <stdio.h>
#include <stdlib.h>//for random number generator
#include <time.h>//for random number generator



int showDice();
int addScoreTotal();

int main(){
    int rollTotal = 0;
    static int currentDice;
    int gameTotal = 0;
    //scanf("%d",&diceRoll);
    char choiceVar;
    int true = 1;

    //begin program
    printf("-----------------------------\n"
           "-------------PIG-------------\n"
           "-----------------------------\n");
  
        printf("\nWhat is the game total?\n");
        scanf(" %d\n",&gameTotal);
        if(!gameTotal > 0){
            printf("Error: the game total must be greater than 0.\n");
        }    
   
    



    while(true){
        printf("Would you like to roll or hold?\nType R to roll OR type H to hold: ");
        scanf(" %c", &choiceVar);
        
        if(choiceVar == 'R'){
            printf("You have chosen to roll.\n");
            currentDice = showDice();
            printf("%d\n\n",currentDice);
            if(currentDice == 1){
                if(addScoreTotal(rollTotal, gameTotal)==1){
                    break;
                }
                rollTotal = 0;
            }
            
            else{
                rollTotal += currentDice;
            }
        }

        if(choiceVar == 'H'){
            printf("You have chosen to hold.\n");
            if(addScoreTotal(rollTotal, gameTotal) == 1){
                break;
            }
            rollTotal = 0;
        }
        
        if((choiceVar != 'R') && (choiceVar != 'H')){
            printf("You have entered somthing incorectly!\n");
            //return to while loop
        }

    }

return 0;
}

int showDice(void){
    int diceRoll;

    srand(time(NULL));
    diceRoll = (rand() % 6) + 1;

    switch(diceRoll){
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
        return 101;
    }
        return diceRoll;
}

int addScoreTotal(int rollTotal, int gameTotal){
    static int playerTurn = 1;

    static int playerScore1 = 0;
    static int playerScore2 = 0;


    if(playerTurn == 1){
        playerScore1 += rollTotal;
        
    }
    else{
        playerScore2 += rollTotal;
        
    }
    printf("Player 1 has %d points.\nPlayer 2 has %d points.\n",playerScore1, playerScore2);
    
    if((playerScore1 >= gameTotal) ||(playerScore2 >= gameTotal)){
        printf("Player %d has won! Congratulations!\n",playerTurn+1);    
        return 1;
    }


    if(playerTurn == 0){
        printf("It is now Player 2's turn\n");
        playerTurn = 1;
    }
    else{
        printf("It is now Player 1's turn\n");
        playerTurn = 1;
    }
    return 0;
}
