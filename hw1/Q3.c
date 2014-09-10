/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two elements in a array
void swap(int* a, int* b)
{
  int tem = *a;
  *a = *b;
  *b = tem;
}

void sort(int* number, int n){
     /*Sort the given array number , of length n*/    
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (number[i] > number[j]) swap(number+i, number+j);	
		}
	}
}

void quicksort(int* number, int n)
{
	if (n <= 1) return;

	int tem = *number;
	int m = 0;
	int *smaller, *larger, *result;

	for (int i=0; i<n; i++) if (tem > number[i]) m++;
	

	result = malloc(sizeof(int)*n);
	smaller = result;
	larger = result+m+1;
	result[m] = tem;

	for (int i=1; i<n; i++)
	{
		if (tem > number[i])
			*smaller++ = number[i];
		else
			*larger++ = number[i];
	}

	for (int i = 0; i < n; ++i) number[i] = result[i];
	// number = result;
	quicksort(number, m);
	quicksort(number+m+1, n-m-1);
}

void quicksort1(int* number, int n)
{
	if (n <= 1) return;

	int p = number[n/2];
	int* l = number;
	int* r = number+n-1;
	
	while (l<=r)
	{
		if (*l < p) {l++; continue;}
		if (*r > p) {r--; continue;}
		int tem = *l;
		*l++ = *r;
		*r-- = tem;
	}

	quicksort1(number, r-number+1);
	quicksort1(l, number+n-l);
}

void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
            continue;
        }
        if (*r > p) {
            r--;
            continue; // we need to check the condition (l <= r) every time we change the value of l or r
        }
        int t = *l;
        *l++ = *r;
        *r-- = t;
    }
    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *a = malloc(sizeof(int)*n);
    /*Fill this array with random numbers between 0 and n, using rand().*/
    srand(time(NULL));
    for (int i = 0; i < n; ++i) a[i] = rand()%n;
    /*Print the contents of the array.*/
    for (int i = 0; i < n; ++i) printf("a[%d] = %d\n", i, a[i]);
    /*Pass this array along with n to the sort() function.*/
	// sort(a, n);
	quicksort1(a, n);
    /*Print the contents of the array.*/    
    for (int i = 0; i < n; ++i) printf("a[%d] = %d\n", i, a[i]);
    
    return 0;
}
