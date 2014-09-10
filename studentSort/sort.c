/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(){
    struct student* stud = NULL;
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    stud = allocate(n);
    /*Generate random IDs and scores for the n students, using rand().*/
    generate(stud,n);
    /*Print the contents of the array of n students.*/
    output(stud,n);
    /*Pass this array along with n to the sort() function*/
    quicksort(stud,n);
    /*Print the contents of the array of n students.*/
    output(stud,n);
    return 0;
}
