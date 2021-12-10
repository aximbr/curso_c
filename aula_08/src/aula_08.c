/* Oitavo programa para estudar C */
#include <stdio.h>
#include <string.h>

int main(){

    char word [] [7] = {
        "loaded",
        "LOADED"      
    };
    
    printf("word[0] is %s, the lenght is %d, the size is %d \n", 
            word[0], 
            (int) strlen(word[0]), 
            (int) sizeof(word[0]) 
            );

    printf("word[1] is %s, the lenght is %d, the size is %d \n", 
            word[1], 
            (int) strlen(word[1]), 
            (int) sizeof(word[1]) 
            );
    

    return 0;
}