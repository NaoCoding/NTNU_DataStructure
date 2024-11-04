#ifndef STACK_H
#define STACK_H

#include <stdlib.h>


typedef struct _STACK
{
    char val;
    struct _STACK * next;
    
} stack;

void stack_push(char val , stack ** target){

    stack * new_node = (stack *)(calloc(1  , sizeof(stack)));
    new_node->val = val;
    new_node->next = *target;
    *target = new_node;

}

char stack_pop(stack ** target){

    if(*target == NULL) return '?';

    char result = (*target)->val;
    stack * temp = *target;
    (*target) = (*target)->next;
    free(temp);

    return result;

}


#endif