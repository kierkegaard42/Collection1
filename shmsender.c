#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
int main()
{
 printf("SENDER");
 char *buf,*shm;
 int key=5000,shmid;
 if((shmid=shmget(key,20,IPC_CREAT|0666))<0)
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
 char msg[5]="Hello";
 for(int i=0;msg[i]!='\0';i++)
    buf[i]=msg[i]+3;
 return 0;
}
