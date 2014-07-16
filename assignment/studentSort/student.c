/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "student.h"


void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */

}

void quicksort(struct student* students, int n)
{
    if (n <= 1) return;

    struct student p = students[n/2];
    struct student* l = students;
    struct student* r = students+n-1;
    
    while (l <= r)
    {
        if (l->score < p.score) {l++; continue;}
        if (r->score > p.score) {r--; continue;}
        struct student tem = *l;
        *l++ = *r;
        *r-- = tem;
    }

    quicksort(students, r-students+1);
    quicksort(l, students+n-l);
}

struct student* allocate(int n){
     /*Allocate memory for ten students*/
     struct student *p = malloc(sizeof(struct student)*n);
     // struct student p[10];
     /*return the pointer*/
     return p;
}

// Swap two elements in a array
void swap(int* a, int* b)
{
  int tem = *a;
  *a = *b;
  *b = tem;
}

void generate(struct student* students, int n){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     int *ids = malloc(sizeof(int)*n);
     int a, b;
     srand(time(NULL));

     for (int i = 0; i < n; ++i) ids[i] = i+1;
     
     for (int i = 0; i < 100; ++i)
     {
       a = rand()%10;
       b = rand()%10;
       swap(ids+a, ids+b);
     }

     for (int i = 0; i < n; ++i)
     {
       students[i].id = ids[i];
       students[i].score = rand()%100+1;
     }
}

void output(struct student* students, int n){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     for (int i = 0; i < n; ++i)
     {
       printf("%d %d\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students, int n){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = students[0].score;
     int max = min;
     int sum = 0;
     int average = 0;

     for (int i = 1; i < n; ++i)
     {  
       int tem = students[i].score;
       if (tem < min) min = tem;
       if (tem > max) max = tem;
       sum += tem;
     }

     average = sum/n;
     
     printf("Min: %d\nMax: %d\nAverage: %d\n", min, max, average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    assert(stud);
    free(stud);
}
 