#include "sparse_matrix.h"

/*
Sparse Matrix C Library By NaoCoding(Andy Lu).
For NTNU Data Structure 2024 course.

Date: 2024/10/05

Functions : 
    sparse matrix:
        create empty matrix
        add element to matrix 
        copy elements to matrix_b from matrix_a
        

GitHub Repo releases after homework deadline.
*/

//this function will add new element to the target matrix, (pointer type)
//the return value can check if the element is being added successfully
// 0 : success and no cover old value, 1 : success but cover old value, 2 : error(out of range)
// 3 : error(invalid pointer), 4 : error(unexcepted error from copying matrix)
int8_t addElement_sparseMatrix(matrix * matrixToAdd , 
        uint32_t target_row , uint32_t target_col , long double target_value){

    if(!matrixToAdd) return 3;
    if(matrixToAdd[0].row < target_row ||
        matrixToAdd[0].col < target_col)
            return 2;

    uint32_t i = 1;
    
    if(matrixToAdd[0].value){
        while(matrixToAdd[i].row < target_row && i <= matrixToAdd[0].value) i++;
        if(i <= matrixToAdd[0].value){
            while(matrixToAdd[i].row == target_row && i <= matrixToAdd[0].value){
                if(matrixToAdd[i].col < target_col) i++;
                else break;
            } 
        }
        if(i <= matrixToAdd[0].value){
            if(matrixToAdd[i].row == target_row &&
                matrixToAdd[i].col == target_col){
                matrixToAdd[i].value = target_value;
                return 1;
            }
        }

    }



    matrix* new_matrixPointer = calloc(matrixToAdd[0].value + 1 , sizeof(matrix));
    new_matrixPointer[0].row = matrixToAdd[0].row;
    new_matrixPointer[0].col = matrixToAdd[0].col;
    new_matrixPointer[0].value = matrixToAdd[0].value + 1;

    if(copyMatrix_sparseMatrix(matrixToAdd , new_matrixPointer))
        return 4;
    
    //display_sparseMatrix(matrixToAdd);

    free(matrixToAdd);
    matrixToAdd = new_matrixPointer;

    for(uint32_t j = matrixToAdd[0].value ; j>i;j++){
        matrixToAdd[j].value = matrixToAdd[j-1].value;
        matrixToAdd[j].row = matrixToAdd[j-1].row;
        matrixToAdd[j].col = matrixToAdd[j-1].col;
    }

    matrixToAdd[i].row = target_row;
    matrixToAdd[i].col = target_col;
    matrixToAdd[i].value = target_value;

    //display_sparseMatrix(matrixToAdd);

    return 0;



}


//this function is to copy all the element from matrixToCopy to matrixToApply
//the return value can check if the elements are being copied successfully
// 0 : success and no error, 1 : error( sizeof(matrixToApply) < sizeof(matrixToCopy) ),
// 2 : error( one of row,col of(matrixToCopy) > row,col of(matrixToApply) ), 3 : error(invalid pointer)
int8_t copyMatrix_sparseMatrix(matrix * matrixToCopy , matrix * matrixToApply){

    if(!matrixToApply || !matrixToCopy) return 3;

    if(matrixToCopy[0].row > matrixToApply[0].row) return 2;
    if(matrixToCopy[0].col > matrixToApply[0].col) return 2;
    if(matrixToCopy[0].value > matrixToApply[0].value) return 1;

    for(uint32_t i = 1;i<=matrixToCopy[0].value;i++){
        matrixToApply[i].row = matrixToCopy[i].row;
        matrixToApply[i].col = matrixToCopy[i].col;
        matrixToApply[i].value = matrixToCopy[i].value;
    }

    return 0;

}

//this function display the current sparse matrix
void display_sparseMatrix(matrix * target_matrix){

    if(!target_matrix) return;
    printf("Matrix Size: %ux%u , Sparse Matrix Size: %u\n",
            target_matrix[0].row , target_matrix[0].col , (uint32_t)target_matrix[0].value);
    for(uint32_t i = 1;i<=target_matrix[0].value;i++){
        printf("%5u%5u%10LF",target_matrix[i].row,target_matrix[i].col,target_matrix[i].value);
    }
}

//this function will return a pointer pointing to a new empty sparse matrix
//which means it will return a matrix* with sizeof 1, matrix[0] = {row,col,0}
matrix* create_sparseMatrix(uint32_t row , uint32_t col){  

    matrix* new_matrixPointer = (matrix*) calloc(1 , sizeof(matrix));
    new_matrixPointer[0].row = row;
    new_matrixPointer[0].col = col;
    new_matrixPointer[0].value = 0;

    return new_matrixPointer;
}

