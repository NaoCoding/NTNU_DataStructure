#ifndef IO_H
#define IO_H

#define bool uint8_t
#define i64 int64_t
#define breakpoint scanf("%c");

bool INPUT_VALID(char target);
bool INPUT_RETURN(char target);
bool readline(char target[] , int size);
bool readlineCommand(char target[] , int size);
i64 i64len(i64 target[]);

bool readlineCommand(char * target , int size){

    bool validVersion = 1;

    for(int i=0;i<size;i++) target[i] = 0;

    int idx = 0;
    while(idx < size){

        char t;
        scanf("%c" , &t);

        //printf("%d" , INPUT_VALID(t));
    
        if(INPUT_VALID(t) ||('4' >= t && t >= '0') || t == '9')target[idx++] = t;
        else if(INPUT_RETURN(t))break;
        else validVersion = 0;
        
    }
    //breakpoint

    return validVersion;

}


bool readline(char * target , int size){

    bool validVersion = 1;

    for(int i=0;i<size;i++) target[i] = 0;

    int idx = 0;
    while(idx < size){

        char t;
        scanf("%c" , &t);

        //printf("%d" , INPUT_VALID(t));
    
        if(INPUT_VALID(t))target[idx++] = t;
        else if(INPUT_RETURN(t))break;
        else validVersion = 0;
        
    }
    //breakpoint

    return validVersion;

}

bool INPUT_VALID(char target){

    //printf("%c" , target);

    if(target >= 'a' && target <= 'z') return 1;
    if(target >= 'A' && target <= 'Z') return 1;
    if(target == ' ') return 1;
    return 0;

}

bool INPUT_RETURN(char target){

    if(target <= 19) return 1;
    return 0;

}

i64 i64len(i64 target[]){
    
    i64 size = 0;
    while(INPUT_VALID(target[size++])){}

    return size;

}

#endif

