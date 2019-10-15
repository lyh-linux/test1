#include "main.h"

void withf()
	{
	FILE *fp,*fd;
	char ch;
	printf("Input the name of file(withf):textf\n");
	if((fd=fopen("textf.txt","w"))==NULL)
	{
		printf("file cannot be opend!\n");
		exit(1);
	}
	if((fp=fopen("/etc/passwd","r"))==NULL)
	{
		printf("file cannot be opend!\n");
		exit(1);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		fputc(ch,fd);
	}
	fclose(fp);
	fclose(fd);
	}

void withoutf()
	{
	int fdsrc,fddes,nbytes;
	int flags =O_CREAT | O_TRUNC | O_WRONLY;
	int z;
	char buf[20],src[20];
	printf("Input the name of file(withoutf):text\n");
	fdsrc = open("/etc/passwd",O_RDONLY);
	if(fdsrc < 0)
	{
		exit(1);
	}
	fddes = open("text.txt",flags,0644);
	if(fddes < 0)
	{
		exit(1);
	}
	while((nbytes=read(fdsrc,buf,20))>0)
	{
		z = write(fddes,buf,nbytes);
		if(z<0)
		{
			perror("write file wrong!\n");
		}
	}
	close(fdsrc);
	close(fddes);
	}
