/* Terceiro programa para estudar C */
#include <stdio.h>

int main(){
    int i;
    char c;

    for (i = 0; i < 5; i++) {
    printf("Entre com uma letra:\n");
    scanf(" %c", &c);
    printf("Sua letra foi: %c\n\n",c);
    
    }
    return 0;
}