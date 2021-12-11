/* Decimo primeiro programa para estudar C */
/* function training */

#include <stdio.h>

int movePlayer(char Direction, int inc, int CurrentPosition);

int main(){

    printf("\nMain start Main \n\n");

    char inputIn[4] ="xxx";
    int positionIndex = 0;

    while (inputIn[0] != 'Q') {

        printf("\nEnter the direction (N, S, E, W):\n");
        fgets(inputIn, 4, stdin);

        switch (inputIn[0])
        {
        case 'N':
            positionIndex = movePlayer(inputIn[0], 1, positionIndex);
            break;

        case 'S':
            positionIndex = movePlayer(inputIn[0], -1, positionIndex);
            break;

        case 'E':
            positionIndex = movePlayer(inputIn[0], 8, positionIndex);
            break;

        case 'W':
            positionIndex = movePlayer(inputIn[0], -8, positionIndex);
            break;

        case 'Q':

        break;

        default:
            printf("\nCommand unknown: %c", inputIn[0]);
        break;

        } 
    }

    printf("\nmain() End of program ...\n");
    return 0;
}

//My Functions
int movePlayer(char Direction, int inc, int CurrentPosition){
    int newPos = CurrentPosition + inc;
    printf("\nplayer moved direction %c, new position %d", Direction, newPos);
    return newPos;
}