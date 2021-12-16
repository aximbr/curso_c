/* Aula 20 - C Course */
/* Tic Tac Toe Game */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* Define a board 
int board[25]{
    @,@,@,@,@,
    @,*,*,*,@,
    @,*,*,*,@,
    @,*,*,*,@,
    @,@,@,@,@
}*/

enum { NOUGHTS, CROSSES, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAWN};

const int ConverteTo25[9] = {
    6, 7, 8,
    11, 12, 13,
    16, 17, 18
};


void InitialiseBoard(int *board){
    int index = 0;

    for (index = 0; index < 25; index++){
        board[index] = BORDER;
    }

    for (index = 0; index <9; index++){
        board[ConverteTo25[index]] = EMPTY;
    }
}

void PrintBoard(int *board){
    int index = 0;
    printf("\nBoard\n");
    for (index = 0; index < 25; index++){
        if (index != 0 && index %5 == 0 ){
            printf("\n");
        }
        printf("%4d",board[index]);
    }
    printf("\n");
}

void RungGame(){
    int GameOver = 0;
    int Side = NOUGHTS;
    int LastMoveMade = 0;

    int board[25];

    InitialiseBoard( &board[0] );
    PrintBoard( &board[0] );

    while (!GameOver){
        if (Side==NOUGHTS){
            //get move from human, make move on board, change side
        } else {
            //get move from computer, make move on board, change side
            PrintBoard(&board[0]);
        }

        //if three in row, then GameOver and exists game
        //if no more moves, then Games is drawn
    }
}

int main() {
    
    srand(time(NULL));
    RungGame();

    return 0;

}