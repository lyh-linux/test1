#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

long get_qsort_time(int *);
long get_my_time(int *);
int compar(const void *a,const void *b);
