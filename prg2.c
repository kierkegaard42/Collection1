#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
 int p[2];
 void* buf;
 printf("\n\t\t\tCREATION OF PROCESS");
 if(pipe(p)==0)
  {
   pid_t id=fork();
   if(id)
    {
     printf("\n Process ID of Parent:%d",getpid());
     printf("\n Process ID of Child:%d",id);
     write(p[1],"Hello",5);
    }
   else
    {
     printf("\n Process ID of Parent:%d",getppid());
     printf("\n Process ID of Child:%d",getpid());
     read(p[0],buf,5);
     printf("\n String received:%s",buf);  
    }   
   printf("\n");
  }
 return 0;
}
