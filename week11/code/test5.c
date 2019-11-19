#include"my.h"
int main()
{
	FILE *fp;
	int pid1,pid2,p1,p2,s1,s2;
	if((fp=fopen("out.txt","w+")) == NULL)
	{
		printf("Create failed!\n");
		exit(-1);
	}
	
	if((pid1=fork())&&(pid2=fork()) < 0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		printf("%d: child1 running\n",getpid());
		fwrite("123456789",strlen("123456789"),1,fp);
		exit(120);
	}
	else if(pid2 == 0)
	{
		printf("%d: child2 running\n",getpid());
		fwrite("987654321",strlen("987654321"),1,fp);
		exit(130);
	}
	else
	{
		printf("%d:parent is waiting zombie now\n",getpid());
		p1 = wait(&s1);
		if(WEXITSTATUS(s1)==120)
		{
			printf("child1  %d\n",p1);
		}
		p2 = wait(&s2);
		if(WEXITSTATUS(s2)==130)
		{
			printf("child2  %d\n",p2);
		}
		printf("parent finished!\n");
	}
	fclose(fp);
	return 0;
}
