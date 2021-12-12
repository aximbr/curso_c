/* Decimo quarto programa para estudar C */
/* pointer training */

#include <stdio.h>


int main(){
    char MyText[] = "This is my Text";
    char *pChar = &MyText[0];

    while( *pChar){
        printf("  %c at address %p\n",*pChar, pChar);
        pChar++;
    }

    return 0;
}
