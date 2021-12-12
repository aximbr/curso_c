/* Decimo terceiro programa para estudar C */
/* pointer training */

#include <stdio.h>

void changeNumber(int *numberOne, int *numberTwo){

    printf("\nNumberOne was %d\nnumberTwo was %d", *numberOne, *numberTwo);

    *numberOne = 11;
    *numberTwo = 12;

    printf("\nNow numberOne is %d\nnumberTwo is %d\n\n", *numberOne, *numberTwo);

    return;
}

int main(){
    int numberOne = 5;
    int numberTwo = 8;

    printf("\nNumberOne = %d \n", numberOne);
    printf("\nAdressess of numberOne is %p \n\n",&numberOne);

    printf("\nNumberTwo = %d \n", numberTwo);
    printf("\nAdressess of numberTwo is %p \n\n",&numberTwo);

    changeNumber(&numberOne, &numberTwo);

    
    
    return 0;
}
