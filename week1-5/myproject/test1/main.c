#include "main.h"

int main()
{
	int data1[1000],data2[1000];
    int j;
	srand((int)time(0));
	for(j=0;j<1000;j++)
	{
		data1[j]=1+(int)(10000.0*rand()/(RAND_MAX+1.0));
		data2[j]=data1[j];
	}

	long time1,time2;
	
	time1 = get_qsort_time(data1);
    time2 = get_my_time(data2);
	printf("qsorts time: %ld\nmytime: %ld\n",time1,time2);
    return 0;
}
