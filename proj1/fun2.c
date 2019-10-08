#include"uhead.h"
struct arg operater(int *a,int n){
	struct arg b;
	int i;
	b.sum=0;
	b.ave=0.0;
	for(i=0;i<n;i++)
		b.sum=b.sum+a[i];
	b.ave=((float)b.sum)/n;
	return b;
}


