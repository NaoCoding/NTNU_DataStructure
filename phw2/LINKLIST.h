#ifndef LINKLIST_H
#define LINKLIST_H

#define DEBUG_NODE(x) printf("%c" , x->val);
#define i64 int64_t

typedef struct _LINKLIST{
    char val;
    struct _LINKLIST * left;
    struct _LINKLIST * right;
} node;

void append(node * left , node * right);
bool Arr2LinkList(node ** start_position , char target[] , i64 size);
void _LINKLIST_DISPLAY(node * start);
void DISPLAY_CURRENT(node * start);


void append(node * left , node * right){

    while(left->right) left = left->right;
    while(right->left) right = right->left;
    left->right = right;
    right->left = left;

}

bool Arr2LinkList(node ** start_position , char target[] , i64 size){

    if(size <= 0) return 0;

    node * cur = (node *)(calloc(1 , sizeof(node)));

    *start_position = cur;
    i64 Arr_IDX = 0;
    cur->val = target[Arr_IDX++];

    //DEBUG_NODE(cur);

    while(Arr_IDX < size){

        cur->right = (node *)(calloc(1 , sizeof(node)));
        cur->right->left = cur;
        cur = cur->right;
        cur->val = target[Arr_IDX++];
        //DEBUG_NODE(cur);

    }

    

    return size;

}

void _LINKLIST_DISPLAY(node * start){

    node * cur = start;
    while(cur){
        printf("%c" , cur->val);
        cur = cur->right;
    }
    printf("\n");

}

void DISPLAY_CURRENT(node * start){

    printf("Current Status: ");

    while(start){
        if(start->val == '|'){
            printf("\e[1;36m|\e[0m");
        }
        else printf("%c" , start->val);
        start = start->right;
    }
    printf("\n");

}

#endif