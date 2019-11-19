#include "my.h"

int main(){
	FILE *fp;
	int status,p;
	pid_t pid;
	if((fp = fopen("vforktest.txt","a+"))==NULL)
	{
		perror("create failed!\n");
		return -1;	
	}
	pid = vfork();
	if(pid<0)
	{
		perror("fork dailed!\n");
		exit(-1);	
	}
	else if(pid == 0){
		printf("child %d writing!\n",getpid());
		fwrite("123456789",strlen("123456789"),1,fp);
		printf("child finished!\n");
		exit(0);
	}
	else{
		p=wait(&status);
		if(WEXITSTATUS(status)==0)
		{
			printf("child  %d\n",p);
		}
		printf("parent %d writing!\n",getpid());
		fwrite("987654321",strlen("987654321"),1,fp);
		printf("parent finished!\n");
	}
	return 0;
}
