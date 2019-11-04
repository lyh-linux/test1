#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
	system("/home/rlk/week9/code/test");
	printf("after calling\n");
}
