/* Nono programa para estudar C */
/* hangman game */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    srand(time(NULL));  //initialize a random seed

    //Variables definition and initalization

    char guessWord [] [16] = {
        "green",
        "yellow",
        "purple",
        "windows",
        "linux",
        "apple"      
    };

    //create a random int for index
    int randomIndex = rand() % 6; // create a random number from 0 to 6

    //some variables for control
    int numLives = 5;
    int numCorrect = 0;
    int oldCorrect = 0;
    int indexLoop = 0;

    int lengthOfWord = strlen(guessWord[randomIndex]);

    //track the number of correct letters
    int letterGuessed[8] = { 0, 0, 0, 0, 0, 0, 0, 0};

    int quit = 0;

    char guess[16];
    char letterEntered;

    //DEBUG
    printf("The word is %s \n\n", guessWord[randomIndex]);

    //game loop
    while( numCorrect < lengthOfWord){
        printf("Enter a guess letter:");
        printf("\nSo far number of correct letters are: %d\n", numCorrect);

        //Read input from user
        fgets(guess,16, stdin);

        //check for Quit the game
        if (strncmp(guess, "quit", 4) == 0){
            quit = 1;
            break;
        }

        letterEntered = guess[0];

        printf("\nLetter Entered was %c\n", letterEntered);

        oldCorrect = numCorrect;

        //check the entered letter match any letter for the secret word
        for (indexLoop = 0; indexLoop < lengthOfWord; indexLoop++){
            if (letterGuessed[indexLoop] == 1){
                continue;
            }
            if (letterEntered == guessWord[randomIndex][indexLoop]) {
                //correct guess
                letterGuessed[indexLoop] = 1;
                numCorrect++;
            }
        }
        //Decrement Live
        if (oldCorrect == numCorrect){
            numLives--;
            printf("Sorry, wrong guess!\n");
            if (numLives == 0){
                //No more lives. Exit Game Loop
                break;
                }
        }   
            else {
                //Correct letter
                printf("Correct guess!\n");
            }
        

    }//while loop

    //End of game (user quit, No more Lives or Win)
    if (quit == 1){
        printf("\nUser quit early.\n");
    } else if (numLives == 0){
        printf("\nYou lose. The word was: %s\n\n", guessWord[randomIndex]);
    } else {
        printf("\nCongrats, you Win! \n");
    }
    

    return 0;
}