#include"head.h"
void create_1()
{
	int fd;
	int flags =O_CREAT | O_TRUNC | O_RDWR;
	char filename[20];
	printf("Please input the name of file:");
	scanf("%s",filename);
	fd = open(filename,flags,0664);
	if(fd == -1)
	{
		perror("Create failed!\n");
		exit(1);
	}
	else
	{
		printf("Create successfully!\n");
	}
	close(fd);
}

void write_1()
{
	int fd;
	int flags =O_CREAT | O_APPEND | O_RDWR;
	char filename[20],text[100];
	printf("Please input the name of file:");
	scanf("%s",filename);
	fd = open(filename,flags,0664);
	if(fd == -1)
	{
		perror("Open failed!\n");
		exit(1);
	}
	printf("Please input the content to be written:");
	scanf("%s",text);
	if((write(fd,text,strlen(text)))!=(strlen(text)))
	{
		perror("Write failed!\n");
	}
	else
	{
		printf("Write successfully!\n");
	}
	close(fd);
}

void read_1()
{
	int fd,nbytes,i;
	int flags = O_RDONLY;
	char filename[20],buf[20];
	printf("Please input the name of file:");
	scanf("%s",filename);
	fd = open(filename,flags);
	if(fd == -1)
	{
		perror("Open failed!\n");
		exit(1);
	}
	while((nbytes=read(fd,buf,20))>0)
	{
		for(i=0;i<nbytes;i++)
		{
			printf("%c",buf[i]);
		}
	}
	printf("\n");
	close(fd);
}

void modify_1()
{
	char filename[20];
	printf("Please input the name of file:");
	scanf("%s",filename);
	if(chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)   //"rw-r--r--" 
	{
		exit(1);
	}
	printf("Successful set mode to rw-r--r--\n");
}

void seemodify_1()
{
	struct stat statbuf;
	char filename[20],str[12];
	printf("Please input the name of file:");
	scanf("%s",filename);
	if(stat(filename,&statbuf)<0)
	{
		exit(1);
	}
	printf("原文件权限：%o\n",statbuf.st_mode);
	mode_to_letter(statbuf.st_mode,str);
	printf("原文件权限：%s\n",str);
	if(chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)    //"rw-r--r--" 
	{
		exit(1);
	}
	printf("Successful set mode to rw-r--r--\n");
	if(stat(filename,&statbuf)<0)
	{
		exit(1);
	}
	printf("修改后权限：%o\n",statbuf.st_mode);
	mode_to_letter(statbuf.st_mode,str);
	printf("修改后权限：%s\n",str);
}

void mode_to_letter(int mode,char *str)				//把模式值转化为字符串
{
	str[0]='-'; 									//判断模式属性
	if(S_ISDIR(mode)) str[0]='d';					//文件夹
	if(S_ISCHR(mode)) str[0]='c';					//字符设备
	if(S_ISBLK(mode)) str[0]='b';					//块设备
	if(mode & S_IRUSR) str[1]='r';					//用户的三个属性
	else str[1]='-';
	if(mode & S_IWUSR) str[2]='w';
	else str[2]='-';
	if(mode & S_IXUSR) str[3]='x';
	else str[3]='-';
	if(mode & S_IRGRP) str[4]='r';					//组的三个属性
	else str[4]='-';
	if(mode & S_IWGRP) str[5]='w';
	else str[5]='-';
	if(mode & S_IXGRP) str[6]='x';
	else str[6]='-';
	if(mode & S_IROTH) str[7]='r';					//其他人的三个属性
	else str[7]='-';
	if(mode & S_IWOTH) str[8]='w';
	else str[8]='-';
	if(mode & S_IXOTH) str[9]='x';
	else str[9]='-';
	str[10]='\0';
}
