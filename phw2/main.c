#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "IO.h" // input/output parse file
#include "UI.h" // ui file
#include "LINKLIST.h" // link list library
#include "DEBUG.h" // debug file

#define RUNNING while(1)


node * MAIN_NODE;
char INPUT_LIST[2005];


int main(){

    CLEAR
    FOOTER
    START_MESSAGE
    
    //readline(INPUT_LIST , 2000);
    
    
    /* detect error function
    while(readline(INPUT_LIST , 2000)){
        CLEAR
        FOOTER
        START_ERROR_MESSAGE
        START_MESSAGE
        //DEBUG_INPUT_LIST(INPUT_LIST , strlen(INPUT_LIST));
    }
    */

    while(readline(INPUT_LIST , 2000)){
        CLEAR
        FOOTER
        START_ERROR_MESSAGE
        START_MESSAGE
        //DEBUG_INPUT_LIST(INPUT_LIST , strlen(INPUT_LIST));
    }

    
    
    //DEBUG_INPUT_LIST(INPUT_LIST , strlen(INPUT_LIST));

    if(Arr2LinkList(&MAIN_NODE , INPUT_LIST , strlen(INPUT_LIST)) != strlen(INPUT_LIST)){
        ERROR
        return 0;
    }

    node * cursor = (node *)(calloc(1,sizeof(node)));
    cursor->val = '|';

    append(MAIN_NODE , cursor);

    //DEBUG_LINKLIST_DISPLAY(MAIN_NODE);

    //breakpoint
    
    RUNNING{
        CLEAR
        FOOTER
        COMMAND_MESSAGE
        DISPLAY_CURRENT(MAIN_NODE);
        readline(INPUT_LIST , 2000);
        COMMAND(INPUT_LIST , strlen(INPUT_LIST));
    }
    
    

}