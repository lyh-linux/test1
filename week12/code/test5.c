//验证管道具有原子性
#include "my.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024

int main()
{
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K];
	memset(a,'A',sizeof(a));
	memset(b,'B',sizeof(b));
	memset(c,'C',sizeof(c));
	int fd[2];
	int ret=pipe(fd);
	if(ret==-1)
	{
		fprintf(stderr,"creat pipe error(%s)\n",strerror(errno));
		exit(-1);		
	}
	pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		fprintf(stderr,"first fork error(%s)\n",strerror(errno));//将错误信息以字符串显示
		exit(-2);		
	}
	else if(pid==0)
	{
		close(fd[0]);
		int loop=0;
		while(loop++<10)
		{
			ret=write(fd[1],a,sizeof(a));
			fprintf(stdout,"[child] pid=%d,write %d bytes to pipe.\n",getpid(),ret);
		}

		exit(0);		
	}
	pid=fork();
	if(pid==-1)
	{
		fprintf(stderr,"second fork error(%s)\n",strerror(errno));
		exit(-3);		
	}
	else if(pid==0)
	{
		close(fd[0]);
		int loop=0;
		while(loop++<10)
		{
			ret=write(fd[1],b,sizeof(b));
			fprintf(stdout,"[child] pid=%d,write %d bytes to pipe.\n",getpid(),ret);
		}

		exit(0);		
	}
	
	pid=fork();
	if(pid==-1)
	{
		fprintf(stderr,"third fork error(%s)\n",strerror(errno));
		exit(-4);		
	}
	else if(pid==0)
	{
		close(fd[0]);
		int loop=0;
		while(loop++<10)
		{
			ret=write(fd[1],c,sizeof(c));
			fprintf(stdout,"[child] pid=%d,write %d bytes to pipe.\n",getpid(),ret);
		}

		exit(0);		
	}
	else
	{
		close(fd[1]);
		sleep(2);
		int fd1=open("./test6.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
		char buf[1024*4]={0};
		int n=1;
		while(1)
		{
			ret=read(fd[0],buf,sizeof(buf));
			if(ret==0)
			{
				break;
			}
			printf("n=%02d pid=%d read %d bytes from pipe buf[4095]=%c.\n",n++,getpid(),ret,buf[4095]);
			write(fd1,buf,ret);
		}
	}
	return 0;
}