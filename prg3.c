#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
 int p[2],num[]={153,0};
 int n,r,sum=0,n2;
 int buf;
 if(pipe(p)==0)
  {
   int id=fork();
   if(id)
    {
     printf("\n\t\t\tPARENT PROCESS");
     write(p[1],num,sizeof(num));
     sleep(5);
    }
   else
    {
     printf("\n\t\t\tCHILD PROCESS");
     read(p[0],buf,sizeof(buf));   
     printf("\n Data received:%d",num[0]);  
     n=num[0];
     n2=n;
     while(n!=0)
      {
       r=n%10;
       n=n/10;
       sum+=r*r*r; 
      }
     if(sum==n2)
        printf("\n It is an armstrong number.");
     else
        printf("\n It is not an armstrong number.");
    }   
   printf("\n");
  }
 return 0;
}
