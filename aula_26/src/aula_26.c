/* Aula 26 - C Course */
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

    0,   1,  2,  3,  4,
    5,   6,  7,  8,  9,
    10, 11, 12, 13, 14,
    15, 16, 17, 18, 19,
    20, 21, 22, 23, 24
}*/

enum { NOUGHTS, CROSSES, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAWN};

const int Directions[4] = { 1, 5, 4, 6};

//List of positions to be Empty
const int ConverteTo25[9] = {
    6, 7, 8,
    11, 12, 13,
    16, 17, 18
};

int GetNumForDir(int StartSq, const int dir, const int *board, const int us){
    int found = 0;
    while (board[StartSq] != BORDER){
        if (board[StartSq] != us) {
            break;
        }
        found++;
        StartSq += dir;
    }
    return found;
}

int FindThreeInARow (const int *board, const int ourindex, const int us){
    int DirIndex = 0;
    int Dir = 0;
    int ThreeCount = 1;

    for (DirIndex =0; DirIndex <4; ++DirIndex){
        Dir = Directions[DirIndex];
        ThreeCount += GetNumForDir(ourindex + Dir, Dir, board, us);
        ThreeCount += GetNumForDir(ourindex + Dir * -1, Dir * -1, board, us);
        if (ThreeCount == 3){
            break;
        }
        ThreeCount = 1;
    }
    return ThreeCount;
}

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

int GetWinningMove( int *board, const int side) {

    int ourMove = -1;
    int winFound = 0;
    int index = 0;

    for (index = 0; index <9; ++index) {
       if (board[ConverteTo25[index]] == EMPTY){
           ourMove = ConverteTo25[index];
           board[ourMove] = side;

           if (FindThreeInARow( board, ourMove, side) == 3){
               winFound = 1;
           }
           board[ourMove] = EMPTY;
           if (winFound == 1) {
               break;
           }
           ourMove = -1;
       };
   }
    return ourMove;
}

int GetComputerMove(int *board, const int side){
    int index = 0;
    int numFree = 0;
    int availableMoves[9];
    int randMove = 0;

    randMove = GetWinningMove( board, side);

    if (randMove != -1){
        return randMove;
    }

    randMove = 0;

   for (index = 0; index <9; ++index) {
       if (board[ConverteTo25[index]] == EMPTY){
           availableMoves[numFree++] = ConverteTo25[index];
       };
   }

   randMove = (rand() % numFree);
   return availableMoves[randMove];
}


void PrintBoard(int *board){
    int index = 0;
    char pceChars[] = "oX|-";

    printf("\n\nBoard\n\n");
    for (index = 0; index < 9; ++index){
        if (index != 0 && index%3 == 0 ){
            printf("\n\n");
        }
        printf("%4c",pceChars[board[ConverteTo25[index]]]);
    }
    printf("\n");
}

void RungGame(){
    int GameOver = 0;
    int side = NOUGHTS;
    int LastMoveMade = 0;
    int board[25];

    InitialiseBoard( &board[0] );
    PrintBoard( &board[0] );

    while (!GameOver){
        if (side==NOUGHTS){
            LastMoveMade = GetHumanMove(&board[0]); //get move from human, make move on board, change side
            MakeMove(&board[0], LastMoveMade, side);
            side = CROSSES;
            
        } else {
            LastMoveMade = GetComputerMove(&board[0], side); //get move from computer, make move on board, change side
            MakeMove(&board[0], LastMoveMade, side);
            side = NOUGHTS;
            PrintBoard(&board[0]);
        }

        //if three in row, then GameOver and exits game
        if (FindThreeInARow(board, LastMoveMade, side ^ 1) == 3){
            printf("Game over!\n");
            GameOver = 1;
            if (side == NOUGHTS){
                printf("Computer wins!\n");
            } else {
                printf("Human wins!\n");
            }
        }
        //if no more moves, then Games is drawn
        if (!HasEmpty(&board[0])){
            printf("Game is over!\n");
            GameOver = 1;
            printf("It is a drawn\n");
        }
    }
    PrintBoard(&board[0]);
}

int main() {
    
    srand(time(NULL));
    RungGame();

    return 0;

}