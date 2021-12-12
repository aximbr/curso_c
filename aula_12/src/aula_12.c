/* Decimo segundo programa para estudar C */
/* pointer training */

#include <stdio.h>

int main(){
    int numberOne = 5;
    int numberTwo = 8;

    printf("\nNumberOne = %d \n", numberOne);
    printf("\nAdressess of numberOne is %p \n\n",&numberOne);

    printf("\nNumberTwo = %d \n", numberTwo);
    printf("\nAdressess of numberTwo is %p \n\n",&numberTwo);

    int *pToMyNumber = &numberOne;

    printf("\nThe address of pToMynumber is %p", pToMyNumber);
    printf("\nThe contends of pToMyNumber is %d", *pToMyNumber);

    *pToMyNumber = 6;

    printf("\nNumberOne = %d \n", numberOne);
    
    return 0;
}
