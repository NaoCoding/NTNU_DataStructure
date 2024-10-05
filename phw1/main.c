#include <stdio.h>
#include "sparse_matrix.h"
#define START_UP 1

int main(){

    /*
    while(START_UP){
            
    }   
    */

   matrix * a = create_sparseMatrix(5 , 3);
   display_sparseMatrix(a);
   printf("%u\n" , addElement_sparseMatrix(&a , 3 , 3 , 10.3));
   display_sparseMatrix(a);
   //free(a);

}