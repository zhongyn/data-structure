#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("-1/5 = %d\n", -1/5);
	printf("-1@5 = %d\n", -1%5);
	int a[]={1,2,3};
	printf("a[-1] = %d\n", a[0]);
	return 0;
}