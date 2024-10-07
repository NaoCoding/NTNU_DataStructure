Data Structure Programming Homework I
Student ID : 41247001S

Sparse Matrix C Library.

Functions : 
    sparse matrix:
        create empty matrix
        add element to matrix 
        copy elements to matrix_b from matrix_a
        transpose matrix
        multiply two matrices
        add matrices
        create sparse matrix from normal array.

I also wrote the ReLU/Sigmoid activation function.
Basically, I have written and done all the requirements in the homework I.

How to use my code?
After downloading the source folder, just enter make in terminal.
./matrix will be the command for opening the application.

I have also checked the potential memory leak issues, 
for cybersecurity and for user's pc env safety.

Example of normal matrix term
5 3 //row , col
0 2 3
3 1 0
0 0 0
0 4 2
2 3 6

Example of sparse matrix term

3 5 3 //arr[0] (row , col , val)
1 1 1
2 2 2 
3 3 3

