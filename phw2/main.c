#include <stdio.h>
#include <stdlib.h>

#include "IO.h" // input/output parse file
#include "DEBUG.h" // debug file
#include "UI.h" // ui file
#include "LINKLIST.h" // link list library


#define RUNNING while(1)


char initial_string[2000];


int main(){

    CLEAR
    FOOTER
    START_MESSAGE
    readline(initial_string , 2000);

    node * p = (node *)calloc(2 , sizeof(node));
    p[1].val = 'A';
    p[0].val = 'B';

    append(&p[0] , &p[1]);

    printf("%d" , p[0].right.val);


    /*
    RUNNING{
        CLEAR
        FOOTER
        readline(initial_string , 2000);
    }
    */
    

}