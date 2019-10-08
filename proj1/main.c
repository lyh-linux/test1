#include"uhead.h"
int main(){
	int a[unumber],b[unumber];
	long time1,time2;
	struct arg result;
	urand(a,b,unumber);
	show(a,unumber);
	
	time1 = get_qsort_time(a);
    time2 = get_my_time(b);
	printf("qsorts time: %ld\nmytime: %ld\n",time1,time2);
	
	result = operater(a,unumber);
	printf("sum=%d,ave=%f\n",result.sum,result.ave);
	return 0;
}
