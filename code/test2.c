#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int global1=0;
int global2;

int main()
{
	int i=10;
	static int k=20;
	pid_t result;
	result=fork();
	if(result<0)
	{
		perror("创建子进程失败");
		exit(1);
	}
	else if(result==0)
	{
		printf("return:%d \nchild: \npid=%d \nppid=%d\n",result,getpid(),getppid());
		printf("address: \ni:%p; k:%p; global1:%p; global2:%p\n",&i,&k,&global1,&global2);
		global1=999;
		global2=1000;
		i=12;
		k=19;
		sleep(2);
		printf("global1=%d, global2=%d, i=%d, k=%d\n",global1,global2,i,k);
		exit(0);
	}
	else
	{
		
		printf("return:%d \nparent: \npid=%d \nppid=%d\n",result,getpid(),getppid());
		printf("address: \ni:%p; k:%p; global1:%p; global2:%p;\n",&i,&k,&global1,&global2);
		sleep(10);
		printf("global1=%d, global2=%d, i=%d, k=%d\n",global1,global2,i,k);
	}
}
