#include <stdio.h>
#include "sparse_matrix.h"
#include <math.h>
#define START_UP 1
#define clear() printf("\e[1;1H\e[2J")

matrix * Z , * X , * W , * B;
u8 didSetUp = 0;

void EXAMPLE();
void displayUI();

int main(){

    

    /*
    EXAMPLE();
    */
    while(START_UP){

        
        u8 command;
        displayUI();
        scanf("%hhu" , &command);

        if(command > 8) continue;
        if(!command) break;
        else if(command == 1){

            //if(didSetUp) free(W); free(X); free(B);
            didSetUp = 1;
            for(u32 t = 0; t < 3 ; t ++){
                clear();
                printf("----------------------------------------------\n");
                printf("Data Structure Programming Homework I\n");
                printf("Student ID : 41247001S\n");
                printf("----------------------------------------------\n");
                printf("Matrix %c : \n",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                printf("Enter the row and col of the matrix %c :",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                u32 row , col;
                scanf("%u", &row);
                scanf("%u" , &col);
                long double ** temp = (long double **)(calloc(row , sizeof(long *)));
                for(u32 i = 0;i<row;i++) temp[i] = (long double *)(calloc(col,sizeof(long double)));
                printf("Enter the whole matrix : \n");
                for(u32 i=0;i<row;i++){
                    for(u32 j=0;j<col;j++) scanf("%LF",&temp[i][j]);
                }
                if(!t) W = createFromArr_sparseMatrix(temp , row , col);
                else if(t == 1) X = createFromArr_sparseMatrix(temp , row , col);
                else B = createFromArr_sparseMatrix(temp , row , col);
                for(u32 i = 0;i<row;i++) free(temp[i]); free(temp);
            }
        }
        else if(command == 2){
            //if(didSetUp) free(W); free(X); free(B);
            didSetUp = 1;
            for(u32 t = 0; t < 3 ; t ++){
                clear();
                printf("----------------------------------------------\n");
                printf("Data Structure Programming Homework I\n");
                printf("Student ID : 41247001S\n");
                printf("----------------------------------------------\n");
                printf("Matrix %c : \n",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                printf("Enter the matrix[0] (row,col,value) of the matrix %c :",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                u32 row , col , val;
                scanf("%u", &row);
                scanf("%u" , &col);
                scanf("%u" , &val);

                if(!t){
                    W = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&W , r ,c ,v);
                    }
                }
                else if(t == 1){
                    X = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&X , r ,c ,v);
                    }
                }
                else{
                    B = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&B , r ,c ,v);
                    }
                }
            }
        }

        else if(command == 3){
            
            if(!didSetUp){
                printf("You should setup the matrice before searching\n");
                printf("Press Enter to back to menu ...\n");
                getchar();
                getchar();
                
            }

            else{
                char M = ' ';
                while(M != 'X' && M != 'W' && M != 'B'){
                    clear();
                    printf("----------------------------------------------\n");
                    printf("Data Structure Programming Homework I\n");
                    printf("Student ID : 41247001S\n");
                    printf("----------------------------------------------\n");
                    printf("Please enter the matrix you want to search : \n");
                    printf("(W , X , B)\n");
                    scanf("%c",&M);
                    if(M>='a') M = M - 'a' + 'A';
                    
                }
                printf("Please enter the row and col you want to search : ");
                u32 row,col;
                scanf("%u",&row); scanf("%u",&col);
                printf("The %u row %u col in Matrix %c is : ",
                    row , col , M);
                if(M == 'W') printf("%LF",(valueOf_sparseMatrix(W  , row , col)));
                else if(M == 'X') printf("%LF",(valueOf_sparseMatrix(X  , row , col)));
                else printf("%LF",(valueOf_sparseMatrix(B  , row , col)));
                printf("\nPress Enter to back to menu ...\n");
                getchar();
                getchar();
            }
        }



        else if(command == 4){
            clear();
            printf("----------------------------------------------\n");
            printf("Data Structure Programming Homework I\n");
            printf("Student ID : 41247001S\n");
            printf("----------------------------------------------\n");
            printf("Matrix W : \n");
            display_sparseMatrix(W);
            printf("----------------------------------------------\n");
            printf("Matrix X : \n");
            display_sparseMatrix(X);
            printf("----------------------------------------------\n");
            printf("Matrix B : \n");
            display_sparseMatrix(B);
            printf("----------------------------------------------\n");
            printf("Press Enter to back to menu ...\n");
            getchar();
            getchar();
        }

        else if(command == 5){

            clear();
            printf("----------------------------------------------\n");
            printf("Data Structure Programming Homework I\n");
            printf("Student ID : 41247001S\n");
            printf("----------------------------------------------\n");

            if(!didSetUp){
                printf("Setup matrices in order to calculate the result.\n");
            }

            else{
                matrix * result = multiply_sparseMatrix(W,X);
            
                if(!result){
                    printf("The matrices cannot multiply!\n");
                }
                else{
                    if(add_sparseMatrix(B , &result)){
                        printf("The row and col of B and W*X are not the same!\n");
                    }
                    else{
                        printf("Result Matrix : \n");
                        display_sparseMatrix(result);
                        free(result);
                    }

                    
                }
            }

            printf("----------------------------------------------\n");
            printf("Press Enter to back to menu ...\n");
            getchar();
            getchar();

        }
        else if(command == 6){
            clear();
            printf("----------------------------------------------\n");
            printf("Data Structure Programming Homework I\n");
            printf("Student ID : 41247001S\n");
            printf("----------------------------------------------\n");

            if(!didSetUp){
                printf("Setup matrices in order to calculate the result.\n");
            }
            else{
                matrix * result1 = multiply_sparseMatrix(W,X);
                matrix * result2 = multiply_sparseMatrix(W,X);
            
                if(!result1 || !result2){
                    printf("The matrices cannot multiply!\n");
                }
                else{
                    if(add_sparseMatrix(B , &result1) || add_sparseMatrix(B , &result2)){
                        printf("The row and col of B and W*X are not the same!\n");
                    }
                    else{
                        printf("Result Matrix with ReLU activative function : \n");
                        for(u32 i=1;i<=result1[0].value;i++){
                            result1[i].value = result1[i].value > 0 ? result1[i].value : 0;
                        }
                        display_sparseMatrix(result1);
                        printf("Result Matrix with Sigmoid activative function : \n");

                        
                        
                        u32 total = result2[0].row * result2[0].col;
                        for(u32 i=1;i<=result2[0].value;i++){

                            result2[i].value = 1/(1+exp(-result2[i].value));
                            if(result2[i].value == 0) total -= 1;

                        }

                        printf("Matrix Size: %ux%u , Sparse Matrix Size: %u\n",
                                result2[0].row , result2[0].col , total);

                        u32 index = 1;
                        
                        for(u32 i=0;i<result2[0].row;i++){
                            for(u32 j=0;j<result2[0].col;j++){

                                if(index <= result2[0].value){
                                    if(result2[index].row == i && result2[index].col == j
                                    ){
                                        if(result2[index].value != 0)
                                            printf("%6s%-5u%-5u%-10LF\n","     ",result2[index].row,result2[index].col,result2[index].value);
                                        index ++;
                                        while(result2[index].value == 0) index ++;
                                    }

                                    else{
                                        printf("%6s%-5u%-5u%-10F\n","     ",i,j,0.5);
                                    }
                                }
                                else{
                                    printf("%6s%-5u%-5u%-10F\n","     ",i,j,0.5);
                                }

                            }
                        }
                        
                        
                        free(result1); free(result2);
                    }

                    
                }
            }

            printf("----------------------------------------------\n");
            printf("Press Enter to back to menu ...\n");
            getchar();
            getchar();
        }
        else if(command == 7){
            //if(didSetUp) free(W); free(X); free(B);
            didSetUp = 1;
            u32 times;
            clear();
            printf("----------------------------------------------\n");
            printf("Data Structure Programming Homework I\n");
            printf("Student ID : 41247001S\n");
            printf("----------------------------------------------\n");
            printf("Enter how many W,B matrices :");
            scanf("%u" , &times);
            if(times<1) break;
            for(u32 t = 0; t < 3 ; t ++){
                clear();
                printf("----------------------------------------------\n");
                printf("Data Structure Programming Homework I\n");
                printf("Student ID : 41247001S\n");
                printf("----------------------------------------------\n");
                printf("Matrix %c : \n",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                printf("Enter the row and col of the matrix %c :",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                u32 row , col;
                scanf("%u", &row);
                scanf("%u" , &col);
                long double ** temp = (long double **)(calloc(row , sizeof(long *)));
                for(u32 i = 0;i<row;i++) temp[i] = (long double *)(calloc(col,sizeof(long double)));
                printf("Enter the whole matrix : \n");
                for(u32 i=0;i<row;i++){
                    for(u32 j=0;j<col;j++) scanf("%LF",&temp[i][j]);
                }
                if(!t) W = createFromArr_sparseMatrix(temp , row , col);
                else if(t == 1) X = createFromArr_sparseMatrix(temp , row , col);
                else B = createFromArr_sparseMatrix(temp , row , col);
                for(u32 i = 0;i<row;i++) free(temp[i]); free(temp);
            }

            matrix * result = multiply_sparseMatrix(W,X);
            
            if(!result){
                printf("The matrices cannot multiply!\n");
            }
            else{
                if(add_sparseMatrix(B , &result)){
                    printf("The row and col of B and W*X are not the same!\n");
                    break;
                }
                else{
                    printf("Result Matrix : \n");
                    display_sparseMatrix(result);
                    
                }

                
            }

            X = result;

            for(;times>1;times--){
                printf("----------------------------------------------\n");
                printf("Press Enter to continue the next time ...\n");
                getchar();
                getchar();
                 for(u32 t = 0; t < 2 ; t ++){
                    clear();
                    printf("----------------------------------------------\n");
                    printf("Data Structure Programming Homework I\n");
                    printf("Student ID : 41247001S\n");
                    printf("----------------------------------------------\n");
                    printf("Matrix %c : \n",(!t ? 'W' : ('B')));
                    printf("Enter the row and col of the matrix %c :",(!t ? 'W' : ('B')));
                    u32 row , col;
                    scanf("%u", &row);
                    scanf("%u" , &col);
                    long double ** temp = (long double **)(calloc(row , sizeof(long *)));
                    for(u32 i = 0;i<row;i++) temp[i] = (long double *)(calloc(col,sizeof(long double)));
                    printf("Enter the whole matrix : \n");
                    for(u32 i=0;i<row;i++){
                        for(u32 j=0;j<col;j++) scanf("%LF",&temp[i][j]);
                    }
                    if(!t) W = createFromArr_sparseMatrix(temp , row , col);
                    else B = createFromArr_sparseMatrix(temp , row , col);
                    for(u32 i = 0;i<row;i++) free(temp[i]); free(temp);
                }

                matrix * result = multiply_sparseMatrix(W,X);
                
                if(!result){
                    printf("The matrices cannot multiply!\n");
                }
                else{
                    if(add_sparseMatrix(B , &result)){
                        printf("The row and col of B and W*X are not the same!\n");
                        break;
                    }
                    else{
                        printf("Result Matrix : \n");
                        display_sparseMatrix(result);
                        
                    }

                    
                }

                X = result;
            }

            printf("----------------------------------------------\n");
            printf("Press Enter to back to menu ...\n");
            getchar();
            getchar();
            

        }
        else if(command == 8){
            ////if(didSetUp) free(W); free(X); free(B);
            didSetUp = 1;
            u32 times;
            clear();
            printf("----------------------------------------------\n");
            printf("Data Structure Programming Homework I\n");
            printf("Student ID : 41247001S\n");
            printf("----------------------------------------------\n");
            printf("Enter how many W,B matrices :");
            scanf("%u" , &times);
            if(times<1) break;
            for(u32 t = 0; t < 3 ; t ++){
                clear();
                printf("----------------------------------------------\n");
                printf("Data Structure Programming Homework I\n");
                printf("Student ID : 41247001S\n");
                printf("----------------------------------------------\n");
                printf("Matrix %c : \n",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                printf("Enter the matrix[0] (row,col,value) of the matrix %c :",(!t ? 'W' : (t == 1 ? 'X' : 'B')));
                u32 row , col , val;
                scanf("%u", &row);
                scanf("%u" , &col);
                scanf("%u" , &val);

                if(!t){
                    W = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&W , r ,c ,v);
                    }
                }
                else if(t == 1){
                    X = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&X , r ,c ,v);
                    }
                }
                else{
                    B = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&B , r ,c ,v);
                    }
                }
            }

            matrix * result = multiply_sparseMatrix(W,X);
            
            if(!result){
                printf("The matrices cannot multiply!\n");
            }
            else{
                if(add_sparseMatrix(B , &result)){
                    printf("The row and col of B and W*X are not the same!\n");
                }
                else{
                    printf("Result Matrix : \n");
                    display_sparseMatrix(result);
                    
                }

                
            }

            X = result;

            for(;times>1;times--){
                 printf("----------------------------------------------\n");
                printf("Press Enter to continue the next time ...\n");
                getchar();
                getchar();
                 for(u32 t = 0; t < 2 ; t ++){
                    clear();
                    printf("----------------------------------------------\n");
                    printf("Data Structure Programming Homework I\n");
                    printf("Student ID : 41247001S\n");
                    printf("----------------------------------------------\n");
                    printf("Matrix %c : \n",(!t ? 'W' : ('B')));
                printf("Enter the matrix[0] (row,col,value) of the matrix %c :",(!t ? 'W' : ('B')));
                u32 row , col , val;
                scanf("%u", &row);
                scanf("%u" , &col);
                scanf("%u" , &val);

                if(!t){
                    W = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&W , r ,c ,v);
                    }
                }
                else{
                    B = create_sparseMatrix(row , col);
                    for(u32 i = 1;i<=val;i++){
                        long double v;
                        u32 r,c;
                        scanf("%u %u %LF",&r,&c,&v);
                        addElement_sparseMatrix(&B , r ,c ,v);
                    }
                }
                }

                matrix * result = multiply_sparseMatrix(W,X);
                
                if(!result){
                    printf("The matrices cannot multiply!\n");
                }
                else{
                    if(add_sparseMatrix(B , &result)){
                        printf("The row and col of B and W*X are not the same!\n");
                    }
                    else{
                        printf("Result Matrix : \n");
                        display_sparseMatrix(result);
                        
                    }

                    
                }
                X = result;
            }

            printf("----------------------------------------------\n");
            printf("Press Enter to back to menu ...\n");
            getchar();
            getchar();
            

        }

    }
   //free(Z); free(X); free(W); free(B);

}


void displayUI(){

    clear();
    printf("----------------------------------------------\n");
    printf("Data Structure Programming Homework I\n");
    printf("Student ID : 41247001S\n");
    printf("----------------------------------------------\n");
    printf("1. Setup Matrices by entering normal matrix terms.\n");
    printf("2. Setup Matrices by entering sparse matrix terms.\n");
    printf("3. Search specific row and col in sparse matrices.\n");
    printf("4. See every current Matrices.\n");
    printf("5. Show the result of calculation.\n");
    printf("6. Bonus: Show the result of calculation with ReLU/Sigmoid activation function.\n");
    printf("7. Bonus: Multiple Matrice(W,B) by entering normal matrix terms.\n");
    printf("8. Bonus: Multiple Matrice(W,B) by entering sparse matrix terms.\n");
    printf("0. Exit the program.\n");
    printf("----------------------------------------------\n");
    printf("Your command : ");


}


/*
5 3
0 2 3
3 1 0
0 0 0
0 4 2
2 3 6

3 3
2 4 6
1 0 0
0 0 3

5 3
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0

*/