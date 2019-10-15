#include"dylib.h"
#include<stdio.h>
int main()
{
	int a[10];
	urand(a,10);
	show(a,10);
	printf("max=%d\nsum=%d\n",max(a,10),sum(a,10));
	return 0;
}
