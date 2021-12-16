/* Aula 19 - C Course */
/* Tic Tac Toe Game */

#include <stdio.h>

/* Define a board 
int board[25]{
    @,@,@,@,@,
    @,*,*,*,@,
    @,*,*,*,@,
    @,*,*,*,@,
    @,@,@,@,@
}*/

const int NOUGHTs = 1;
const int CROSSES = 2;
const int BORDER = 3;
const int EMPTY = 0;

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

int main() {
    int board[25];

    InitialiseBoard( &board[0] );
    PrintBoard( &board[0] );

    return 0;

}