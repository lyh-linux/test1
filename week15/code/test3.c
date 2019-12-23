#include"my.h"
int c=100;
pthread_mutex_t mutex;

void *worker1(void *arg)
{
	int ret;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(c>0)
		{
			usleep(1000);
			printf("thread 1 sell ticket:%d\n",c--);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
		ret=pthread_yield();
		if(ret!=0)
		{
			perror("thread 1 yield not success !\n");
		}
	}
	return NULL;
}

void *worker2(void *arg)
{
	int ret;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(c>0)
		{
			usleep(1000);
			printf("thread 2 sell ticket:%d\n",c--);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
		ret=pthread_yield();
		if(ret!=0)
		{
			perror("thread 2 yield not success !\n");
		}
	}
	return NULL;
}

int main()
{
	int ret;
	pthread_t tid[2];
	pthread_mutex_init(&mutex,NULL);
	ret=pthread_create(&tid[0],NULL,worker1,NULL);
	if(ret!=0)
	{
		perror("thread 1 failed!\n");
		exit(1);
	}
	ret=pthread_create(&tid[1],NULL,worker2,NULL);
	if(ret!=0)
	{
		perror("thread 2 failed!\n");
		exit(1);
	}
	for(int i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}

