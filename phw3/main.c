#include "binary_tree.h"
#include <string.h>

int main(){

    while(1){
        printf("\e[1;35mPlease enter an infix expression and press enter:\e[0m\n");
        char infix[1005];
        scanf("%s", infix);
        if(strlen(infix) > 20 || strlen(infix) < 5){
            printf("\e[1;31mError : Length of the infix expression should between 5 ~ 20\n");
        }
    }

}