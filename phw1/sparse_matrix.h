#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

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


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define u32 uint32_t
#define u8 uint8_t

//basic structure of sparse matrix
typedef struct _matrix{
    long double value;
    u32 row, col;
} matrix;

//this function will return a pointer pointing to a new empty sparse matrix
//which means it will return a matrix* with sizeof 1, matrix[0] = {row,col,0}
matrix* create_sparseMatrix(u32 row , u32 col);


//this function return a trasportation of the matrix
matrix * transpose_sparseMatrix(matrix * matrixTotranspose);

//this function turns a long double arr[][] to sparse matrix
matrix * createFromArr_sparseMatrix(long double ** arr, u32 row , u32 col);

//this function will add new element to the target matrix, (pointer type)
//the return value can check if the element is being added successfully
// 0 : success and no cover old value, 1 : success but cover old value, 2 : error(out of range)
// 3 : error(invalid pointer), 4 : error(unexcepted error from copying matrix)
u8 addElement_sparseMatrix(matrix ** matrixToAdd , 
        u32 target_row , u32 target_col , long double target_value);

//this function will add matrixToAdd to transpose
// 0 : add successfully , 1 : error(row, col not the same)
u8 add_sparseMatrix(matrix * matrixToAdd , matrix ** transpose);

//this function will return a sparse matrix with A*B
//if the return pointer is NULL, means there is error(such as A*B cannot multiply)
//this is the function sparse_matrix_multiply(W, X) in NTNU Data Structure programming homework 1
matrix * multiply_sparseMatrix(matrix * matrixA , matrix * matrixB);


//this function will modify the element (add) in sparse matrix
// 0 : success , 1 : error (transpose[row][col] not exist)
u8 addValue_sparseMatrix(matrix ** transpose , u32 row , u32 col , long double value);

//this function is to copy all the element from matrixToCopy to transpose
//the return value can check if the elements are being copied successfully
// 0 : success and no error, 1 : error( sizeof(transpose) < sizeof(matrixToCopy) ),
// 2 : error( one of row,col of(matrixToCopy) > row,col of(transpose) ), 3 : error(invalid pointer)
u8 copyMatrix_sparseMatrix(matrix ** matrixToCopy , matrix ** transpose);

//this function display the current sparse matrix
void display_sparseMatrix(matrix * target_matrix);

//this function return the value of target_matrix[row][col]
long double valueOf_sparseMatrix(matrix * target_matrix , u32 row , u32 col);





#endif