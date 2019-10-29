#include"head.h"
void create_1()
{
	FILE *fd;
	char filename[20];
	printf("Please input the name of file:");
	scanf("%s",filename);
	if((fd = fopen(filename,"w")) == NULL)
	{
		printf("Create failed!\n");
		exit(1);
	}
	else
	{
		printf("Create successfully!\n");
	}
	fclose(fd);
}

void write_1()
{
	FILE *fd;
	char filename[20],text[100];
	printf("Please input the name of file:");
	scanf("%s",filename);
	if((fd = fopen(filename,"a+")) == NULL)
	{
		printf("Open failed!\n");
		exit(1);
	}
	printf("Please input the content to be written:");
	scanf("%s",text);
	if( !fwrite(text,strlen(text),1,fd) )
	{
		printf("Write failed!\n");
	}
	else
	{
		printf("Write successfully!\n");
	}
	fclose(fd);
}

void read_1()
{
	FILE *fd;
	char ch;
	char filename[20];
	printf("Please input the name of file:");
	scanf("%s",filename);
	if((fd = fopen(filename,"r")) == NULL)
	{
		printf("Open failed!\n");
		exit(1);
	}
	while((ch=fgetc(fd)) != EOF)
	{
		printf("%c",ch);
	}
	printf("\n");
	fclose(fd);
}

void modify_1()
{
	FILE *fd;
	int fp;
	char filename[20];
	printf("Please input the name of file:");
	scanf("%s",filename);
	if((fd = fopen(filename,"r+")) == NULL)
	{
		printf("Open failed!\n");
		exit(1);
	}
	fp = fileno(fd);
	if(fchmod(fp,0644) < 0 )   //"rw-r--r--" 
	{
		printf("Modify failed!\n");
		exit(1);
	}
	printf("Successful set mode to rw-r--r--\n");
}

void seemodify_1()
{
	struct stat statbuf;
	FILE *fd;
	int fp;
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
	if((fd = fopen(filename,"r+")) == NULL)
	{
		printf("Open failed!\n");
		exit(1);
	}
	fp = fileno(fd);
	if(fchmod(fp,0644) < 0 )   //"rw-r--r--" 
	{
		printf("Modify failed!\n");
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
