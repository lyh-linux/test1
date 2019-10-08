#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#include <unistd.h>

#define unumber 100

struct arg{
	float ave;
	int sum;
};

void show(int *,int);
void urand(int *,int *,int);
struct arg operater(int *,int);
int compar(const void *a,const void *b);
long get_qsort_time(int *);
long get_my_time(int *);
