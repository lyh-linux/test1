#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<signal.h>
#include<time.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<setjmp.h>
#include<fcntl.h>
#include<pthread.h>
#include<limits.h>
#include<semaphore.h>

#define LOOP 10000000
#define NUM 4
#define TN 100
#define WRITER_FIRST

