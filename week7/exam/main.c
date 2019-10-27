#include<stdio.h>
#include"head.h"
int main()
{
	int n;
	while(1)
	{
		printf("********************************\n");
		printf("0. 退出\n1. 创建新文件\n2. 写文件\n3. 读文件\n4. 修改文件权限\n5. 查看当前文件的权限修改文件权限\n");
		printf("********************************\n");
		printf("Please input your choice(0-5):");
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		switch(n)
		{
		case 1:
			create_1();
			break;
		case 2:
			write_1();
			break;
		case 3:
			read_1();
			break;
		case 4:
			modify_1();
			break;
		case 5:
			seemodify_1();
			break;
		}
	}
	return 0;
}
