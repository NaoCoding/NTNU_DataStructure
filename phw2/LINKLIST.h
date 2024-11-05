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
void COMMAND(char t[] , i64 size , node ** main_node , stack ** cmd , stack ** undo , bool mode);
node * getCursor();

void COMMAND(char t[] , i64 size , node ** main_node , stack ** cmd , stack ** undo , bool mode){

    if(size!=1){
        //printf("%d" , size);
        INPUT_LARGER_THAN_1_ERROR
        breakpoint
        return;
    }

    if(t[0] == 27) exit(0);

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

        if(!(mode%2)) stack_push('1' , cmd);

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

        if(!(mode%2)) stack_push('2' , cmd);

    }

    else if(t[0] == '0'){

        node * target = getCursor(*main_node);
        if(!target) return;
        if(!(target->right)) return;

        char deleted_char = target->right->val;

        node * temp = target->right;
        
        if(temp->right){
            target->right = temp->right;
            target->right->left = target;
        }
        
        else{
            target->right = NULL;
        }
        free(temp);
         

        

        
        if(!(mode%2)) stack_push(deleted_char , cmd);
        if(!(mode%2)) stack_push('0' , cmd);

    }

    else if(t[0] == '9'){

        node * target = getCursor(*main_node);

        DISPLAY_CURRENT(target);
        

        if(!target) return;
        
        if(!(target->left)){
            return;
        }
        //printf("%c" , target->left->val);
        

        char deleted_char = target->left->val;

        node * temp = target->left;
        
        if(temp->left){
            target->left = temp->left;
            target->left->right = target;
        }
        
        else{
            *main_node = target;
            target->left = NULL;
        }

        free(temp);
        
        

        

        
        if(!(mode%2)) stack_push(deleted_char , cmd);
        if(!(mode%2)) stack_push('9' , cmd);

    }


    else if(INPUT_VALID(t[0])){

        node * target = getCursor(*main_node);

        node * temp = target->left;

        target->left = (node *)(calloc(1,sizeof(node)));
        target->left->val = t[0];
        target->left->left = temp;
        target->left->right = target;
        if(target->left->left)target->left->left->right = target->left;
        else (*main_node) = target->left;



        if(!(mode%2)) stack_push(t[0] , cmd);
    

    }

    else if(t[0] == '3'){
        if(!(*undo)){
            UNDO_EMPTY
            breakpoint
        }

        char ToDo[] = {stack_pop(undo)};
        
        COMMAND(ToDo , 1 , main_node , cmd , undo , 2);

    }

    else if(t[0] == '4'){
        if(!(*cmd)){
            COMMAND_EMPTY
            breakpoint
        }

        char ToDo = stack_pop(cmd);
        if(ToDo == '0' || ToDo == '9'){

            char * target_char = calloc(1, sizeof(char));
            target_char[0] = stack_pop(cmd);

            if(ToDo == '0'){
                COMMAND(target_char , 1 , main_node , cmd , undo ,1);
                COMMAND("1" , 1 , main_node , cmd , undo , 1);
                stack_push('0' , undo);
            }
            else{
                COMMAND(target_char , 1 , main_node , cmd , undo ,1);
                COMMAND("2" , 1 , main_node , cmd , undo , 1);
                stack_push('9' , undo);
            }
            free(target_char);
        }

        else if(ToDo == '1'){
            COMMAND("2" , 1 , main_node , cmd , undo , 1);
            stack_push('1' , undo);
        }
        else if(ToDo == '2'){
            COMMAND("1" , 1 , main_node , cmd , undo , 1);
            stack_push('2' , undo);
        } 
        else if(INPUT_VALID(ToDo)){
            COMMAND("9" , 1 , main_node , cmd , undo , 1);
            stack_push(ToDo , undo);
        }

    }

    if(!mode && t[0] != '4' && t[0] != '3'){
        while(*undo){
            stack_pop(undo);
        }
    }

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
    cur->left = NULL;
    cur->right = NULL;

    //DEBUG_NODE(cur);

    while(Arr_IDX < size){

        cur->right = (node *)(calloc(1 , sizeof(node)));
        cur->right->left = cur;
        cur = cur->right;
        cur->val = target[Arr_IDX++];
        cur->right = NULL;
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