#include <stdio.h>
#include "sparse_matrix.h"
#define START_UP 1

int main(){

    /*
    while(START_UP){
            
    }   
    */

   long double ** b = calloc(5 , sizeof(long double *));
   for(u32 i=0;i<5;i++){
    b[i] = calloc(3 , sizeof(long double));
   }
   b[0][2] = 3.2;
   b[1][1] = 7;
   b[2][0] = 3;
   b[3][1] = 3;
   b[2][2] = 4;

   matrix * a = createFromArr_sparseMatrix(b,5,3);
   display_sparseMatrix(a);

}