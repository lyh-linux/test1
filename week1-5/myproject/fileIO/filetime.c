#include "main.h"

long int get_time(Pfun p)
{
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);

	p();
	
	gettimeofday(&tv2,&tz);
	//printf("the_time: %d\n",tv2.tv_usec-tv1.tv_usec);
	return tv2.tv_usec-tv1.tv_usec;
}
