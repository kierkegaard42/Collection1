#include<stdio.h>
struct process
{
 char name;
 int at;
 int st;
 int ft;
 int rem;
 int status;
}prc[10],arr[10],temp;

int front=-1,rear=-1; 

void push(struct process p)
{
 if(front==-1)
    front=rear=0;
 else
    rear++;
 arr[rear]=p;
}

int pop()
{
 if(front==rear)
    {
     int t=front;
     front=rear=-1;
     return t;
    }
 else
    return front++;
}

int main()
{
 int current,i,j,n,tq,totaltime=0,x;
 printf("\n No. of processes:");
 scanf("%d",&n);
 printf("\n Time Quantum:");
 scanf("%d",&tq);
 for(i=0;i<n;i++)
  {
   printf("\n Arrival Time:"); 
   scanf("%d",&prc[i].at);
   printf("\n Service Time:");
   scanf("%d",&prc[i].st);
   totaltime+=prc[i].st;
   prc[i].rem=prc[i].st;
   prc[i].name='A'+i;
   prc[i].status=0;
  }
/*------------------------------SORTING------------------------------*/
 for(i=0;i<n;i++)
   for(j=0;j<n-i-1;j++)
    {
     if(prc[j].at>prc[j+1].at) 
       {
        temp=prc[j];
        prc[j]=prc[j+1];
        prc[j+1]=temp;
       }
    }
/*-------------------------------------------------------------------*/
 for(current=prc[0].at;current<totaltime+prc[0].at;)
 {
  for(i=0;i<n;i++)
    {
     if((prc[i].at<=current)&&(prc[i].status==0)&&(prc[i].rem!=0))  
       {
        push(prc[i]);
        prc[i].status=1;
       }
    }
  x=pop();
  for(i=0;i<n;i++)
    if(prc[i].name==prc[x].name)
        {
         x=i;
         break;
        }
  if(prc[x].rem>tq)
     {
      prc[x].rem-=tq;
      current+=tq;
      for(i=0;i<n;i++)
       {
        if((prc[i].at<=current)&&(prc[i].status==0)&&(prc[i].rem!=0))  
         {
          push(prc[i]);
          prc[i].status=1;
         }
       }
      push(prc[x]);
     }
  else
     {
      current+=prc[x].rem;
      prc[x].rem=0;
      prc[x].ft=current;
     }
 //printf("\n Process %c",prc[x].name);
 }
 printf("\n\t\t Arrival Time\t Service Time\t Finish Time");
 printf("\n\t\t ************\t ************\t ***********");
 for(i=0;i<n;i++)
   printf("\n\t\b%d\t\t\b%d\t\t\b\b%d",prc[i].at,prc[i].st,prc[i].ft);
 return 0;
} 
