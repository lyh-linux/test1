#include"my.h"

static jmp_buf g_stack_env;

static void fun1(void);
static void fun2(void);

int main()
{
	if(setjmp(g_stack_env)==0)
	{
		printf("Normal flow\n");
		fun1();	
	}else{
		printf("Long jump flow\n");
	}
	return 0;
}

static void fun1()
{
	printf("Enter fun1\n");
	fun2();
}

static void fun2()
{
	printf("Enter fun2\n");
	longjmp(g_stack_env,1);
	printf("Leave fun2\n");
}
