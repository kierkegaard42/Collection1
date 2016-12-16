#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
 printf("\n\t\t\tCREATION OF PROCESS");
 pid_t id=fork();
 if(id)
  {
   printf("\n Process ID of Parent:%d",getpid());
   printf("\n Process ID of Child:%d",id);
  }
 else
  {
   printf("\n Process ID of Parent:%d",getppid());
   printf("\n Process ID of Child:%d",getpid());
  }   
 printf("\n");
 return 0;
}
