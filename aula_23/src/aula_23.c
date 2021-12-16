/* Aula 23 - C Course */
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

//List of positions to be Empty
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

int HasEmpty(const int *board){
    int index = 0;

    for (index =0; index < 9; index++){
        if (board[ConverteTo25[index]] == EMPTY) return 1;
    }
    return 0;
    
}

void MakeMove( int *board, const int sq, const int side){
    board[sq] = side;
}

int GetHumanMove(const int *board){

    char userInput[4];
    int moveOK = 0;
    int move = -1;

    while(moveOK == 0){
        printf("Please enter a move from 1 to 9:");
        fgets(userInput, 3, stdin);
        fflush(stdin); //clear stdin buffer

        if (strlen(userInput) != 2) {
            printf("invalid strlen() \n");
            continue;
        }

        if (sscanf(userInput, "%d", &move) != 1) {
            move = -1;
            printf("invalid sscanf() \n");
            continue;
        }

        if (move <1 || move >9){
            move = -1;
            printf("invalid range \n");
            continue;
        }

        move --;  //Zero indexing

        if (board[ConverteTo25[move]] != EMPTY) {
            move = -1;
            printf("Square not available \n");
            continue;
        }

        moveOK = 1;
    }

    printf("Making move...%d\n", (move+1));
    return ConverteTo25[move];

}
void PrintBoard(int *board){
    int index = 0;
    char pceChars[] = "oX|-";

    printf("\n\nBoard\n\n");
    for (index = 0; index < 9; index++){
        if (index != 0 && index%3 == 0 ){
            printf("\n\n");
        }
        printf("%4c",pceChars[board[ConverteTo25[index]]]);
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
            GetHumanMove(&board[0]); //get move from human, make move on board, change side
        } else {
            //get move from computer, make move on board, change side
            PrintBoard(&board[0]);
        }

        //if three in row, then GameOver and exits game
        //if no more moves, then Games is drawn
    }
}

int main() {
    
    srand(time(NULL));
    RungGame();

    return 0;

}