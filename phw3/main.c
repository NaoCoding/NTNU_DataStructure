#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define bool uint8_t

bool error(char * command);

int main(){

    while(1){
        printf("\e[1;35mPlease enter an infix expression and press enter: \e[0m");
        char infix[1005] = {0};
        scanf("%s", infix);
        if(error(infix)) continue;

        buildTree(infix);

    }

}

bool error(char * command){

    if(strlen(command) < 5 || strlen(command) > 20){
        printf("\e[1;31mError : Length of the infix expression should between 5 ~ 20\n");
        return 1;
    } 
    return 0;
}