#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define bool uint8_t

bool error(char * command);
bool exix_SIG(char * command);

int main(){

    while(1){
        printf("\e[1;35mPlease enter an infix expression and press enter: \e[0m");
        char infix[1005] = {0};
        scanf("%s", infix);
        if(exix_SIG(infix)) break;
        if(error(infix)) continue;

        node * root = buildTree(infix);

        if(!root) continue;

        printf("\e[1;35mThe level-order of the expression tree: \e[0m\n");
        print_level_order(root);

        printf("\e[1;35mThe postfix expression: \e[0m");
        print_post_order(root);

        printf("\n\e[1;35mThe prefix expression: \e[0m");
        print_pre_order(root);
        printf("\n");

        uint64_t appeared[500] = {0};
        long double value[500] = {0};

        for(uint32_t i=0;i<strlen(infix);i++){
            if(!appeared[infix[i]] && isalpha(infix[i])){
                appeared[infix[i]] = 1;
                printf("\e[1;35mPlease enter the value of %c : \e[0m",infix[i]);
                scanf("%LF" , &value[infix[i]]);
            }
        }

        num_stack * answer = NULL;
        stack * command = NULL;
        treeToPostOrderStack(root , &command);

        while(command){
            char t = pop(&command);
            if(isalpha(t))push_num(&answer , value[t]);
            else{
                long double a = pop_num(&answer);
                long double b = pop_num(&answer);
                if(t=='+')push_num(&answer , a+b);
                if(t=='-')push_num(&answer , a-b);
                if(t=='*')push_num(&answer , a*b);
                if(t=='/')push_num(&answer , a/b);
            }
        }
        
        printf("\e[1;35mThe result = \e[0m%LF\n",pop_num(&answer));

        

    }

}

bool exix_SIG(char * command){
    if(command[0] < 30) return 1;
    return 0;
}

bool error(char * command){

    if(strlen(command) < 5 || strlen(command) > 20){
        printf("\e[1;31mError : Length of the infix expression should between 5 ~ 20\n");
        return 1;
    } 
    return 0;
}