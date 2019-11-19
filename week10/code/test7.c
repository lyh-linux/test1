#include"my.h"
int g=999;
int main(){
	int i=888;
	static int k=777;
	pid_t pid;
	pid=vfork();
	int s;
	if(pid<0)
	{
		perror("vfork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		sleep(2);
		printf("child is running!\n");
		printf("child pid=%d : \n&g=%16p \n&i=%16p \n&k=%16p\n",getpid(),&g,&i,&k);
		execl("./test","test",NULL);
		printf("child after execl!\n");
		_exit(12);		
	}
	else
	{
		wait(&s);
		printf("parent is running! exit code=%d\n",WEXITSTATUS(s));
		printf("parent will finish!\n");
		return 0;
	}
}
