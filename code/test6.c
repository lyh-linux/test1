#include"my.h"
int g=10;
int main(){
	int s=20;
	static int k=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("failed vfork!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		sleep(2);
		printf("child pid=%d : \n&g=%16p \n&k=%16p \n&s=%16p\n",getpid(),&g,&k,&s);
		g=100;
		s=200;
		k=300;
		printf("child pid=%d : g=%d,s=%d,k=%d\n",getpid(),g,s,k);
		while(g!=400)
		{
			printf("%d:waiting for g=400!\n",getpid());
		}
		_exit(0);
	}
	else
	{
		g=400;
		printf("parent pid=%d : \n&g=%16p \n&k=%16p \n&s=%16p\n",getpid(),&g,&k,&s);
		printf("parent pid=%d : g=%d,s=%d,k=%d\n",getpid(),g,s,k);
		return 0;
	}
}
