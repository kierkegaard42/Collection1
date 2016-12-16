#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
int main()
{
 printf("RECEIVER");
 char *buf,*shm;
 int key=5000,shmid;
 if((shmid=shmget(key,20,0666))<0)
    {
     printf("\n Error in getting memory!!");
     return -1;
    }
 if((shm=shmat(shmid,NULL,0))==(char*)-1)
    {
     printf("\n Error!!");
     return -1;
    }
 buf=shm;
printf("\n Message received: ");
 while(*buf!='\0')
  {
   printf("%c",(*buf++)-3);   
  }
 printf("\n");
 return 0;
}
