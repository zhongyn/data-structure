/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#ifndef student_h
#define student_h

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n);
void quicksort(struct student* students, int n);
struct student* allocate(int n);
void swap(int* a, int* b);
void generate(struct student* students, int n);
void output(struct student* students, int n);
void summary(struct student* students, int n);
void deallocate(struct student* stud);

#endif 