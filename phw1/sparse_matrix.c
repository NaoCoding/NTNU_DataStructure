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
        transpose matrix
        multiply two matrices
        add matrices
        create sparse matrix from normal array.
        

GitHub Repo releases after homework deadline.
*/


//this function will add matrixToAdd to matrixToApply
// 0 : add successfully , 1 : error(row, col not the same)
//this is the function sparse_matrix_add(Y,B) in NTNU_DataStructure Programming Homework 1
u8 add_sparseMatrix(matrix * matrixToAdd , matrix ** matrixToApply){

    if((*matrixToApply)[0].row != matrixToAdd[0].row) return 1;
    if((*matrixToApply)[0].col != matrixToAdd[0].col) return 1;

    u32 total = 0;

    u32 i1 = 1 , i2 = 1;

    while(i1 <= matrixToAdd[0].value && i2 <= (*matrixToApply)[0].value){

        if(matrixToAdd[i1].row == (*matrixToApply)[i2].row){
            if(matrixToAdd[i1].col == (*matrixToApply)[i2].col){
                total += 1;
                i1 ++ ; i2 ++;
            }
            else if(matrixToAdd[i1].col < (*matrixToApply)[i2].col){
                total += 1;
                i1 ++;
            }
            else{
                i2 ++;
                total += 1;
            }
        }
        else if(matrixToAdd[i1].row < (*matrixToApply)[i2].row){
            total += 1;
            i1 ++;
        }
        else{
            total += 1;
            i2 ++;
        }
    
    }
    for(;i1 <= matrixToAdd[0].value;i1++) total++;
    for(;i2 <= (*matrixToApply)[0].value;i2++) total++;

    i1 = 1; i2 = 1;




    /*
    

    for(u32 i = 1 ; i <= matrixToAdd[0].value ; i ++){
        if(addValue_sparseMatrix(matrixToApply , 
        matrixToAdd[i].row , matrixToAdd[i].col , 
        matrixToAdd[i].value))
        addElement_sparseMatrix(matrixToApply , 
        matrixToAdd[i].row , matrixToAdd[i].col,
        matrixToAdd[i].value);
    }

    return 0;*/

}

//this function will append the matrix taret to the matrixToApply
// 0 : success , 1 : error(null pointer)
u8 append_sparseMatrix(matrix ** matrixToApply , matrix target){

    if(!(*matrixToApply)) return 1;

    matrix * mN = (matrix *)(calloc((*matrixToApply)[0].value + 2 , sizeof(matrix)));
    for(u32 i=0;i<=(*matrixToApply)[0].value;i++){
        mN[i] = (*matrixToApply)[i];
        if(!i) mN[i].value += 1;
    }
    mN[(u32)mN[0].value] = target;

    free(*matrixToApply);
    *matrixToApply = mN;
    return 0;
}



//this function will return a sparse matrix with A*B
//if the return pointer is NULL, means there is error(such as A*B cannot multiply)
//this is the function sparse_matrix_multiply(W, X) in NTNU Data Structure programming homework 1
matrix * multiply_sparseMatrix(matrix * matrixA , matrix * matrixB){

    if(matrixA[0].col != matrixB[0].row) return NULL;

    matrix * newB = transpose_sparseMatrix(matrixB); 
    matrix * mM = create_sparseMatrix(matrixA[0].row , matrixB[0].col);

    for(u32 i = 1;i <= matrixA[0].value ; i ++){
        for(u32 j = 1 ; j <= newB[0].value ; j ++){
            if(matrixA[i].col == newB[j].col){
                if(addValue_sparseMatrix(&mM , 
                matrixA[i].row , newB[j].row , 
                matrixA[i].value * newB[j].value))
                addElement_sparseMatrix(&mM , 
                matrixA[i].row , newB[j].row , 
                matrixA[i].value * newB[j].value);
            }
        }
    }
    
    free(newB);
    return mM;

}


//this function return a trasportation of the matrix
matrix * transpose_sparseMatrix(matrix * matrixTotranspose){

    matrix * mT = create_sparseMatrix(matrixTotranspose[0].col , matrixTotranspose[0].row);

    for(u32 i = 1; i <= matrixTotranspose[0].value;i++){
        //printf("%u" , i);
        //printf("%u %u %LF",matrixTotranspose[i].col , matrixTotranspose[i].row , matrixTotranspose[i].value);
        if(addElement_sparseMatrix(&mT , matrixTotranspose[i].col , matrixTotranspose[i].row , matrixTotranspose[i].value))
            //Unexcepted ERROR
            return NULL;
    }

    return mT;

}



//this function will modify the element (add) in sparse matrix
// 0 : success , 1 : error (matrixToApply[row][col] not exist)
u8 addValue_sparseMatrix(matrix ** matrixToApply , u32 row , u32 col , long double value){

    u32 i = 1;
    
    while(i <= (*matrixToApply)[0].value){
        if((*matrixToApply)[i].row > row) break;
        else if((*matrixToApply)[i].row < row) i += 1;
        else{
            if((*matrixToApply)[i].col > col) break;
            else if((*matrixToApply)[i].col == col){
                (*matrixToApply)[i].value += value;
                return 0;
            }
            else i += 1;
        }
    }

    return 1;


}


//this function turns a long double arr[][] to sparse matrix
matrix * createFromArr_sparseMatrix(long double ** arr, u32 row , u32 col){

    matrix * new_sparseMatrix = create_sparseMatrix(row , col);
    for(u32 i = 0;i<row;i++){
        for(u32 j=0;j<col;j++){
            if(arr[i][j] != 0){
                addElement_sparseMatrix(&new_sparseMatrix , i , j , arr[i][j]);
            }
        }
    }
    return new_sparseMatrix;

}

//this function will add new element to the target matrix, (pointer type)
//the return value can check if the element is being added successfully
// 0 : success and no cover old value, 1 : success but cover old value, 2 : error(out of range)
// 3 : error(invalid pointer), 4 : error(unexcepted error from copying matrix)
u8 addElement_sparseMatrix(matrix ** matrixToAdd , 
        u32 target_row , u32 target_col , long double target_value){


    if(!*matrixToAdd) return 3;
    if((*matrixToAdd)[0].row < target_row ||
        (*matrixToAdd)[0].col < target_col)
            return 2;

    u32 i = 1;
    
    while(i <= (*matrixToAdd)[0].value){
        if((*matrixToAdd)[i].row > target_row) break;
        else if((*matrixToAdd)[i].row < target_row) i += 1;
        else{
            if((*matrixToAdd)[i].col > target_col) break;
            else if((*matrixToAdd)[i].col == target_col){
                (*matrixToAdd)[i].value = target_value;
                return 1;
            }
            else i += 1;
        }
    }



    

    matrix* new_matrixPointer = (matrix *)calloc(((u32)((*matrixToAdd)[0].value)) + 2 , sizeof(matrix));
    
    //printf("%LF\n" , new_matrixPointer[0].value);
    //display_sparseMatrix(new_matrixPointer);
    //printf("%u" , sizeof(new_matrixPointer) / sizeof(matrix));

    for(u32 j=0;j<=(*matrixToAdd)[0].value;j++){
        new_matrixPointer[j].row = (*matrixToAdd)[j].row;
        new_matrixPointer[j].col = (*matrixToAdd)[j].col;
        new_matrixPointer[j].value = ((*matrixToAdd)[j].value) + (j==0);
    }
    
    //display_sparseMatrix(matrixToAdd);
    //display_sparseMatrix(new_matrixPointer);
    

    free(*matrixToAdd);  
    *matrixToAdd = new_matrixPointer;

    for(u32 j = (*matrixToAdd)[0].value ; j>i;j--){
        (*matrixToAdd)[j].value = (*matrixToAdd)[j-1].value;
        (*matrixToAdd)[j].row = (*matrixToAdd)[j-1].row;
        (*matrixToAdd)[j].col = (*matrixToAdd)[j-1].col;
    }

    (*matrixToAdd)[i].row = target_row;
    (*matrixToAdd)[i].col = target_col;
    (*matrixToAdd)[i].value = target_value; 

    //printf("%LF\n" , (*matrixToAdd)[0].value);

    //display_sparseMatrix(matrixToAdd);
    //display_sparseMatrix(new_matrixPointer);
    //free(new_matrixPointer);

    return 0;



}


//this function return the value of target_matrix[row][col]
long double valueOf_sparseMatrix(matrix * target_matrix , u32 row , u32 col){

    u32 i = 1;

    if(!target_matrix) return 0;


    while(i <= target_matrix[0].value){
        if(target_matrix[i].row > row) return 0;
        if(target_matrix[i].row == row){
            if(target_matrix[i].col == col) return target_matrix[i].value;
            if(target_matrix[i].col > col) return 0;
            i ++;
        }
        else i++;
    }
    return 0;

}


//this function is to copy all the element from matrixToCopy to matrixToApply
//the return value can check if the elements are being copied successfully
// 0 : success and no error, 1 : error( sizeof(matrixToApply) < sizeof(matrixToCopy) ),
// 2 : error( one of row,col of(matrixToCopy) > row,col of(matrixToApply) ), 3 : error(invalid pointer)
u8 copyMatrix_sparseMatrix(matrix ** matrixToCopy , matrix ** matrixToApply){

    if(!(*matrixToApply) || !(*matrixToCopy)) return 3;

    if((*matrixToApply)[0].row < (*matrixToCopy)[0].row) return 2;
    if((*matrixToApply)[0].col < (*matrixToCopy)[0].col) return 2;
    if((*matrixToApply)[0].value < (*matrixToCopy)[0].value) return 1;

    for(u32 i = 1;i<=(*matrixToCopy)[0].value;i++){
        (*matrixToApply)[i].row = (*matrixToCopy)[i].row;
        (*matrixToApply)[i].col = (*matrixToCopy)[i].col;
        (*matrixToApply)[i].value = (*matrixToCopy)[i].value;
    }

    return 0;

}

//this function display the current sparse matrix
void display_sparseMatrix(matrix * target_matrix){

    if(!target_matrix) return;
    printf("Matrix Size: %ux%u , Sparse Matrix Size: %u\n",
            target_matrix[0].row , target_matrix[0].col , (u32)target_matrix[0].value);
    for(u32 i = 1;i<=target_matrix[0].value;i++){
        printf("%6s%-5u%-5u%-10LF\n","     ",target_matrix[i].row,target_matrix[i].col,target_matrix[i].value);
    }

}

//this function will return a pointer pointing to a new empty sparse matrix
//which means it will return a matrix* with sizeof 1, matrix[0] = {row,col,0}
matrix* create_sparseMatrix(u32 row , u32 col){  

    matrix* new_matrixPointer = (matrix*) calloc(1 , sizeof(matrix));
    new_matrixPointer[0].row = row;
    new_matrixPointer[0].col = col;
    new_matrixPointer[0].value = 0;

    return new_matrixPointer;
}

