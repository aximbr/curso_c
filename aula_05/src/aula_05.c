/* Quinta programa para estudar C */
#include <stdio.h>
#include <string.h>

int main(){
    char userInput[64];
    
    printf("\nProgram Start...\n\n\n");

    while (fgets(userInput, 64, stdin))  {
        printf("%s\n", userInput);

        if (strncmp(userInput, "quit", 4) == 0){

            //usuário digitou quit
            printf("saindo... \n");
            break;
        } 
    
    }
    printf ("FIM\n");

    return 0;
}