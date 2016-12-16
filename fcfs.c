#include<stdio.h>
struct process
{
 int at;
 int st;
 int status;
 int ft;
}prc[10];

int dispatcher(int n,int* time)
{
 int i,index=-1;
 for(i=0;i<n;i++)
  {
   if(prc[i].status!=1)
     {
      if(prc[i].at<=(*time))
          index=i;
      else
         {
          index=i;
          *time=prc[i].at;
         }
      break;
     }
  }
 return index;
}
   
int main()
{
 int n,i,current,pid;
 printf("\n Enter no. of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
   {
    printf("\n Arrival time of process %d:",i+1);
    scanf("%d",&prc[i].at);
    printf("\n Service time of process %d:",i+1);
    scanf("%d",&prc[i].st);
    prc[i].status=0;
   }
 i=0;
 current=0;
 while(i<n)
  {
   pid=dispatcher(n,&current);
   prc[pid].ft=current+prc[pid].st;  
   prc[pid].status=1;
   current+=prc[pid].st;
   i++; 
  } 
 printf("\n\t\t  FIRST COME FIRST SERVED");
 printf("\n Arrival time\tService Time\tFinish Time");
 printf("\n ************\t************\t***********");
 for(i=0;i<n;i++)
   printf("\n\t\b%d\t\t\b%d\t\t\b\b%d\t",prc[i].at,prc[i].st,prc[i].ft);
return 0;
}  
 
