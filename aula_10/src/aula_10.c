/* Decimo programa para estudar C */
/* function training */

#include <stdio.h>


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
            positionIndex += 1;
            printf("\nplayer moved direction %c new position %d", inputIn[0], positionIndex);
            break;

        case 'S':
            positionIndex -= 1;
            printf("\nplayer moved direction %c new position %d", inputIn[0], positionIndex);
            break;

        case 'E':
            positionIndex += 8;
            printf("\nplayer moved direction %c new position %d", inputIn[0], positionIndex);
            break;

        case 'W':
            positionIndex -= 8;
            printf("\nplayer moved direction %c new position %d", inputIn[0], positionIndex);
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