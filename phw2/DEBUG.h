#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG(x) printf("%s" , x);
#define i64 int64_t

void DEBUG_INPUT_LIST(char input[] , i64 size);
void DEBUG_LINKLIST_DISPLAY(node * start);
void DEBUG_STACK_DISPLAY(stack * start);


void DEBUG_INPUT_LIST(char input[] , i64 size){

    for(i64 i=0;i<size;i++) printf("%c" , input[i]);

}

void DEBUG_STACK_DISPLAY(stack * start){
    stack * cur = start;
    while(cur){
        printf("%c" , cur->val);
        cur = cur->next;
    }
    printf("\n");

}

void DEBUG_LINKLIST_DISPLAY(node * start){
    node * cur = start;
    while(cur){
        printf("%c" , cur->val);
        cur = cur->right;
    }
    printf("\n");
    cur = start;
    while(cur->right) cur = cur->right;
    while(cur){
        printf("%c" , cur->val);
        cur = cur->left;
    }
    printf("\n");
}

#endif