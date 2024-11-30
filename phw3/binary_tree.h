#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

//node : the structure for binary tree
typedef struct _tree{
    char val;
    struct _tree * left;
    struct _tree * right;
    
} node;

//stack : the structure for stack
typedef struct _stack{
    char val;
    struct _stack * next;

} stack;

//node_stack : the structure for stack which store node
typedef struct _queue{
    struct _tree * val;
    struct _queue * next;

} node_queue;

void push(stack ** head , char target);
char pop(stack ** head);
node * pop_node(node_queue ** head);
void push_node(node_queue ** head , node * target);
uint8_t operators_priority(char t);
void print_stack(stack * head);
void print_queue(node_queue * head);
uint8_t isFull(node * cur);
void print_level_order(node * root);
void print_post_order(node * root);
void print_pre_order(node * root);
void print_in_order(node * root);
void DEBUG(node * root);
node * postfixToTree(stack ** postfix);

//buildTree : build a binary tree by the infix expression
void buildTree(char command[]){

    
    
    stack * operators = NULL;
    stack * postfix = NULL;

    //printf("%d\n", strlen(command));

    for(int64_t i=strlen(command)-1;i>=0;i--){

        
        /*
        printf("command : %c\n",command[i]);
        printf("postfix : ");
        print_stack(postfix);
        printf("operators : ");
        print_stack(operators);
        */

        if(isalpha(command[i]) || command[i] == ')'){
            if(isalpha(command[i])) push(&postfix , command[i]);
            else push(&operators , command[i]);
        }
            
        else if(command[i] == '('){
            char last = pop(&operators);
            while(last != ')'){
                if(last == '?'){
                    printf("\e[1;31mError : This is not a valid infix expression\n");
                    return;
                }
                push(&postfix , last);
                last = pop(&operators);
            }
        }

        else{
            char last = pop(&operators);
            while(last != ')' && last != '?' && operators_priority(last) > operators_priority(command[i])){
                push(&postfix , last);
                last = pop(&operators);
            }
            if(last != '?') push(&operators , last);
            push(&operators , command[i]);
        } 

    }
    while(operators){
        push(&postfix , pop(&operators));
    }

    print_stack(postfix);

    node * root = postfixToTree(&postfix);
    

    printf("\e[1;35mThe level-order of the expression tree: \e[0m\n");
    print_level_order(root);

    printf("\e[1;35mThe postfix expression: \e[0m");
    print_post_order(root);

    printf("\n\e[1;35mThe prefix expression: \e[0m");
    print_pre_order(root);
    printf("\n");

    /*
    printf("\n\e[1;35mThe Inorder expression: \e[0m");
    print_in_order(root);
    printf("\n");
    */

    //DEBUG(root);
    
    
}

void DEBUG(node * root){
    if(!root) return;
    DEBUG(root->left);
    DEBUG(root->right);
    if(!root->left && !root->right)printf("%c" , root->val);
}

void print_post_order(node * root){

    if(!root) return;
    print_post_order(root->left);
    print_post_order(root->right);
    printf("%c",root->val);

}

void print_in_order(node * root){
    if(!root) return;
    print_in_order(root->left);
    printf("%c",root->val);
    print_in_order(root->right);
    
}

void print_pre_order(node * root){

    if(!root) return;
    printf("%c",root->val);
    print_pre_order(root->left);
    print_pre_order(root->right);
    
}

node * postfixToTree(stack ** postfix){

    node * cur = (node *)malloc(sizeof(node));
    cur->val = pop(postfix);
    if(isalpha(cur->val)) return cur;
    cur->left = postfixToTree(postfix);
    cur->right = postfixToTree(postfix);
    return cur;
}


void print_level_order(node * root){

    node_queue * waitList = NULL;
    push_node(&waitList , root);

    node_queue * next = NULL;

    while(waitList){
        node * cur = pop_node(&waitList);
        
        printf("%c " , cur->val);
        if(cur->left) push_node(&next , cur->left);
        if(cur->right) push_node(&next , cur->right);
        if(!waitList){
            printf("\n");
            waitList = next;
            next = NULL;
            continue;
        }
    }

}

uint8_t isFull(node * cur){
    if(!cur) return 0;
    if(isalpha(cur->val)) return 1;
    return isFull(cur->left) * isFull(cur->right);
}

uint8_t operators_priority(char t){
    if(t == '+' || t == '-') return 1;
    else return 2;
}

void print_stack(stack * head){
    while(head){
        printf("%c" , head->val);
        head = head->next;
    }
    printf("\n");
}

void print_queue(node_queue * head){
    while(head){
        if(head->val) printf("%c" , head->val->val);
        else printf("\n");
        head = head->next;
    }
    printf("\n");
}

node * pop_node(node_queue ** head){

    if(*head == NULL) return NULL;

    node * result = (*head)->val;
    node_queue * temp = (*head);
    (*head) = (*head)->next;
    free(temp);

    return result;

}

//pop the last element in the stack
char pop(stack ** head){

    if(*head == NULL) return '?';

    char result = (*head)->val;
    stack * temp = (*head);
    (*head) = (*head)->next;
    free(temp);

    return result;

}

void push_node(node_queue ** head , node * target){

    if(!(*head)){
        *head = (node_queue *)(calloc(1  , sizeof(node_queue)));
        (*head)->val = target;
        return;
    }
    
    node_queue * new_node = (node_queue *)(calloc(1  , sizeof(node_queue)));
    new_node->val = target;
    node_queue * temp = *head;
    while(temp->next) temp = temp->next;
    temp->next = new_node;

}

//push target to the tail of the stack
void push(stack ** head , char target){
    
    stack * new_node = (stack *)(calloc(1  , sizeof(stack)));
    new_node->val = target;
    new_node->next = *head;
    *head = new_node;

}

//freeTree : free memory of tree where root ptr is pointing to
void freeTree(node * root){
    if(!root) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


#endif