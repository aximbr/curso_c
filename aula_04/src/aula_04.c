/* Quarto programa para estudar C */
#include <stdio.h>

int main(){
    //int i;
    char c;

    while (c != 'X')  {
        printf("Entre com uma letra:\n");
        scanf(" %c", &c);
        printf("Sua letra foi: %c\n\n",c);
    
    }
    printf ("FIM\n");

    return 0;
}