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
        

GitHub Repo releases after homework deadline.
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//basic structure of sparse matrix
typedef struct _matrix{
    long double value;
    uint32_t row, col;
} matrix;

//this function will return a pointer pointing to a new empty sparse matrix
//which means it will return a matrix* with sizeof 1, matrix[0] = {row,col,0}
matrix* create_sparseMatrix(uint32_t row , uint32_t col);

//this function will add new element to the target matrix, (pointer type)
//the return value can check if the element is being added successfully
// 0 : success and no cover old value, 1 : success but cover old value, 2 : error(out of range)
// 3 : error(invalid pointer), 4 : error(unexcepted error from copying matrix)
int8_t addElement_sparseMatrix(matrix ** matrixToAdd , 
        uint32_t target_row , uint32_t target_col , long double target_value);

//this function is to copy all the element from matrixToCopy to matrixToApply
//the return value can check if the elements are being copied successfully
// 0 : success and no error, 1 : error( sizeof(matrixToApply) < sizeof(matrixToCopy) ),
// 2 : error( one of row,col of(matrixToCopy) > row,col of(matrixToApply) ), 3 : error(invalid pointer)
int8_t copyMatrix_sparseMatrix(matrix ** matrixToCopy , matrix ** matrixToApply);

//this function display the current sparse matrix
void display_sparseMatrix(matrix * target_matrix);


#endif