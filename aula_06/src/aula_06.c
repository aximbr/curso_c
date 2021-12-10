/* Sexto programa para estudar C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int intArray[6];
    int indexNumber = 0;
    int numberEntered = 0;
    int totalEntered = 0;

    char input[16];

    for (indexNumber = 0; indexNumber < 6; indexNumber++){

        printf("Entre com um numero inteiro: ");
        fgets(input, 16, stdin);

        if (strncmp(input,"q",1) == 0) {
            break;
        }

        numberEntered = atoi(input);
        intArray[indexNumber] = numberEntered;
        totalEntered++;

        
    }

    for (indexNumber = 0; indexNumber < totalEntered; indexNumber++){

        printf("intArray[%d] = %d \n\n",indexNumber, intArray[indexNumber]);
    }

    return 0;
}