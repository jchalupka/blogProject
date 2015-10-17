#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
void hold();
void showDice();

int main(){

	int p1Score = 0;
	int p2Score = 0;
	int gameTotal = 0;
	int currentPlayer = 1;
	int rollTotal = 0;
	int diceRoll;
	char choiceVar;
	char playAgain;
	char gameTotalChar = '0';


	printf("\n\nWELCOME TO                   \n"
		   "*********************************\n"
	       "*  THE    $$$$   $$$$$   $$$$   *\n"
           "*  GAME   $   $    $    $       *\n"
		   "*  OF     $$$$     $    $   $$  *\n"
		   "*         $      $$$$$   $$$$   *\n"
		   "*********************************\n\n");



	int playingGame = 1;
	while(playingGame){
		//ask the player if the wish to roll or hold

		if(rollTotal == 0){
			while(gameTotalChar -'0' <=0){

				printf("What is the game total? ");
				scanf(" %c", &gameTotalChar);
			}
			gameTotal = gameTotalChar -'0';

			printf("The Game Total is %d\n"
				   "=================================\n"
				   "Player 1 score = %d\n"
				   "Player 2 score = %d\n"
				   "=================================\n",gameTotal,p1Score,p2Score);
			if(currentPlayer == 1){
				printf("Player 1's turn\n"
				       "---------------------------------\n");
			}
			if(currentPlayer == 2){
				printf("Player 2's turn\n"
				       "---------------------------------\n");
			}
		}


		printf("(r)oll or (h)old?\n> ");
		scanf(" %c\n", &choiceVar);
		//if roll is chosen, use the random number generator to generate a number between 1 and 6
		if(choiceVar == 'R' || choiceVar == 'r'){

			srand(time(NULL));
    		diceRoll = (rand() % 6) + 1;
			printf("dice rolls a %d\n",diceRoll);
			showDice(diceRoll);

			//if the number 1 is rolled go to step 2
			if(diceRoll == 1){
				printf("Sorry, loose a turn!\n"
			           "---------------------------------\n");

				rollTotal = 0;
				//Is one of the players total greater than or equal to the total?

					if(currentPlayer == 1){

						currentPlayer = 2;
					}
					else{
						currentPlayer = 1;
					}
			}

			else{

				rollTotal += diceRoll;
				printf("Roll total: %d\n"
				       "---------------------------------\n", rollTotal);
			}
		}
			//if any of the other numbers are rolled, the value is added to the player's roll total.  Go to setp 1.



		//if hold is chosen, transfer the roll total to the players total.  Go to step 2.
		if(choiceVar == 'H' || choiceVar == 'h'){



			if(currentPlayer == 1){

				p1Score = p1Score +rollTotal;

			}
			else{
				p2Score = p2Score + rollTotal;

			}

			rollTotal = 0;

			//Is one of the players total greater than or equal to the total?
			if(p1Score >= gameTotal || p2Score >= gameTotal){
			//yes the game ends

				printf("The Game Total is %d\n"
					   "=================================\n"
					   "Player 1 score = %d\n"
					   "Player 2 score = %d\n"
					   "=================================\n",gameTotal,p1Score,p2Score);
					if(p1Score > p2Score){
						printf("=================================\n"
						       "Player One Wins!\n"
							   "GAME OVER\n"
					     	   "=================================\n");
					}
					else{
						printf("=================================\n"
						       "Player Two Wins!\n"
							   "GAME OVER\n"
							   "=================================\n");
					}
					//create a loop asking the player if the would like to play another game.
					int replayGame = 1;
					while(replayGame){
						printf("\nWould you like to play again? (Y/N)\n"
							   "> ");
						scanf(" %c", &playAgain);
						if(playAgain == 'Y' || playAgain == 'y'){
							replayGame = 0;
							p1Score = 0;
							p2Score = 0;
							gameTotal = 0;
							currentPlayer = 1;
							rollTotal = 0;
							printf("New Game\n");
						}
						if(playAgain == 'N' || playAgain == 'n'){
							replayGame = 0;
							playingGame = 0;
							printf("Thanks for playing!\n");
						}
					}
			}
			//no go to step 3
			else{
				if(currentPlayer == 1){
					currentPlayer = 2;

				}
				else{
					currentPlayer = 1;

				}
			}

		}
	}
	return 0;

}



void showDice(int diceRoll){
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
    }
}
