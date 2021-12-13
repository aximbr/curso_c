/* Aula 16 - C Course */
/* bitwise operations */

#include <stdio.h>
                         //  ABCD
int StatusOfMachine = 6;  // 0110
int CheckSwitchA    = 8;  // 1000
int CheckSwitchB    = 4;  // 0100
int CheckSwitchC    = 2;  // 0010
int CheckSwitchD    = 1;  // 0001

//Local functions prototype
void PrintOnOff ( char Name, int SwitchNum);
void PrintStatus ();


int main(){
    
    PrintStatus();

    //StatusOfMachine |= CheckSwitchA;
    StatusOfMachine = StatusOfMachine & ~CheckSwitchC; //Turn off C Switch

    PrintStatus();
    

    return 0;
}

//Implementation Local functions
void PrintOnOff ( char Name, int SwitchNum){
    if (StatusOfMachine & SwitchNum){
        printf("%c: ON\n",Name);
    } else { printf("%c: OFF\n",Name);
    }
}

void PrintStatus () {
    printf("\nMachine Status:\n");
    PrintOnOff('A', CheckSwitchA);
    PrintOnOff('B', CheckSwitchB);
    PrintOnOff('C', CheckSwitchC);
    PrintOnOff('D', CheckSwitchD);
    printf("\n");
}