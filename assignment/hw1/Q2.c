/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 8;
    int y = 9;
    int z = 10;
    /*Print the values of x, y and z*/
    printf("%d %d %d\n", x,y,z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int k = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("%d\n", k);
    /*Print the values of x, y and z again*/
    printf("%d %d %d\n", x,y,z); 
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}
    
    
