/* Aula 18 - C Course */
/* bitwise operations */

#include <stdio.h>

void PrintBinary(int num);

int main(){

    int tA = 10;
    int tB = 7;

    int infoMachine = ( (tA << 4) | tB);

    printf("infoMachine: \n");
    PrintBinary(infoMachine);

    int Mask = 15; //0000 1111

    int get_tA = ( (infoMachine >> 4) & Mask);

    printf("get_tA: \n");
    PrintBinary(get_tA);

    int get_tB = ( infoMachine  & Mask);

    printf("get_tB: \n");
    PrintBinary(get_tB);


    return 0;
}

void PrintBinary(int num){
    int index = 0;
    printf("Dec: %d As Binary: \n",num);
    for (index = 7; index >=0; index--){

        if ( (1 << index) & num) {
            printf("1");
        } else {
            printf("0");
        }

        if (index !=7 && index%4 == 0){
            printf(" ");
        }

    }
    printf("\n");
}