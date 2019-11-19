#include "my.h"
int main()
{
   int pid1,pid2,s1,p1,p2,s2;
   if(((pid1=fork())&&(pid2=fork()))<0)
     {
       perror("failed to fork@\n");
       return -1;
     }
   else if(pid1==0)
     {

       printf("%d : child1 is running now!\n",getpid());
    
       printf("%d : child1 is exit now!\n",getpid());
       //while(1);
       exit(120);

     }
    else if(pid2==0)
     {
       printf("%d : child2 is running now!\n",getpid());
    
       printf("%d : child2 is exit now!\n",getpid());
       //while(1);
       exit(130);

     }
    else
     {
        //sleep(5);
        printf("%d:parent is waiting zombie now\n",getpid());
        p1=wait(&s1);
        p2=wait(&s2);
        if((WEXITSTATUS(s1))==120)
           {
               printf("child1  %d\n",p1);
            }
		if((WEXITSTATUS(s2))==130)
           {
               printf("child2  %d\n",p2);
            }
       /* while((p=waitpid(pid2,&s,WNOHANG))!=-1)
        {
            printf("%d:parent is exiting now\n",getpid());
           
           if(WIFEXITED(s))
            {
              printf("child %d is exiting normally.exit code =%d\n",p,WEXITSTATUS(s));
            }
           else if(WIFSIGNALED(s))
            {
               printf("child %d exit by signal.signal no =%d\n",p,WTERMSIG(s));

            }
           else
            {
                printf("Not know!\n");
            }
           
        
        }*/
      

      printf("parent finished!\n");
     }
     exit(0);

}

