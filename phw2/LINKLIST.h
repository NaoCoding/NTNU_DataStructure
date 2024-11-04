#ifndef LINKLIST_H
#define LINKLIST_H

#define DEBUG_NODE(x) printf("%c" , x->val);
#define i64 int64_t


#define INPUT_LARGER_THAN_1_ERROR printf("\e[1;31mError : Input length should be 1!\nPress Enter to Continue.\e[0m\n");

typedef struct _LINKLIST{
    char val;
    struct _LINKLIST * left;
    struct _LINKLIST * right;
} node;

void append(node * left , node * right);
bool Arr2LinkList(node ** start_position , char target[] , i64 size);
void _LINKLIST_DISPLAY(node * start);
void DISPLAY_CURRENT(node * start);
void COMMAND(char t[] , i64 size , node ** main_node , stack ** cmd , stack ** undo);
node * getCursor();

void COMMAND(char t[] , i64 size , node ** main_node , stack ** cmd , stack ** undo){

    if(size!=1){
        printf("%d" , size);
        INPUT_LARGER_THAN_1_ERROR
        breakpoint
        return;
    }

    if(t[0] == '1'){

        node * target = getCursor(*main_node);
        if(target == NULL) return;
        if(target->left == NULL) return;
        else{
            
            node * nRight = target->left;
            nRight->right = target->right;
            target->left = nRight->left;
            target->right = nRight;
            nRight->left = target;
            if(target->left) target->left->right = target;
            else *main_node = target;
            if(nRight->right) nRight->right->left = nRight;
            
        }

        stack_push('1' , cmd);

    }

    else if(t[0] == '2'){

        node * target = getCursor(*main_node);
        if(target == NULL) return;
        if(target->right == NULL) return;
        else{
            
            node * nLeft = target->right;
            nLeft->left = target->left;
            target->right = nLeft->right;
            target->left = nLeft;
            nLeft->right = target;
            if(target->right) target->right->left = target;
            
            if(nLeft->left) nLeft->left->right = nLeft;
            else *main_node = nLeft;
            
        }

        stack_push('2' , cmd);

    }

    else if(t[0] == '0'){

        node * target = getCursor(*main_node);
        if(!(target->right)) return;
        char deleted_char = target->right->val;

        node * temp = target->right;
        target->right = temp->right;
        if(target->right)
        target->right->left = target;
        free(temp);
         

        

        stack_push('0' , cmd);
        stack_push(deleted_char , cmd);

    }

    else if(t[0] == '9'){

        node * target = getCursor(*main_node);
        if(!(target->left)){
            return;
        }
        char deleted_char = target->left->val;

        node * temp = target->left;
        target->left = temp->left;
        if(temp->left)
        target->left->right = target;
        free(temp);
        

        

        stack_push('9' , cmd);
        stack_push(deleted_char , cmd);

    }

    else return;

}


node * getCursor(node * target){

    node * cur = target;
    while(cur){
        if(cur->val == '|') return cur;
        cur = cur->right;
    }
    return NULL;

}


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