#include"my.h"
int main()
{
	pid_t r;
	int r_num,i;
	int pipefd[2];
	char w_buf[4097];
	char r_buf[4097];
	memset(w_buf,0,sizeof(w_buf));
	for(i=0;i<4097;i++)
	{
		w_buf[i]='1';
	}
	memset(r_buf,0,sizeof(r_buf));
	if(pipe(pipefd) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r=fork();
	if(r<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(r == 0)
	{
		sleep(10);
		close(pipefd[1]);
		if((r_num=read(pipefd[0],r_buf,sizeof(r_buf))) > 0)
			printf("child read from pipe: %s,total=%d\n",r_buf,r_num);
		close(pipefd[0]);
		exit(0);
	}
	else
	{
		close(pipefd[0]);
		if((write(pipefd[1],w_buf,sizeof(w_buf))) != -1)
			printf("parent write ok!\n");
		close(pipefd[1]);
		return 0;
	}
}
