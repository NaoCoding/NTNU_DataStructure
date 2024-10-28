#ifndef IO_H
#define IO_H

#define CLEAR printf("\e[H\e[2J");
#define START_MESSAGE printf("Please enter an initial string consisting a/A-z/Z and space:");

void readline(char target[] , int size){

    for(int i=0;i<size;i++) target[i] = 0;

    int idx = 0;
    while(idx < size){
        char t;
        scanf("%c" , &t);
        if(t >= 32)target[idx++] = t;
        else break;
    }
}

#endif

