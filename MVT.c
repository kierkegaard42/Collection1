#include<stdio.h>
struct pro
{int st,size;
}p[20];
int rem1=0;
int main()
{
int size,psize,inf,rem,x,np,pars;
printf("enter memory size:");
scanf("%d",&size);rem=size;
int a[20]={0};int i=0,z=0,pid;
struct pro p[20]={0,0};
while(1)
{
 ava(p);
 printf("\nenter process size:");
 scanf("%d",&psize);
 
 if(rem1>=psize || rem>=psize)
  {printf("\nMemory allocated");rem-=psize;p[z].st=1;p[z].size=psize;z++;}
 else
  {printf("\nMemory Overflow");}
printf("\n Memory :");
for(i=0;i<20;i++)
 if(p[i].st==1)
  printf("%d ",p[i].size);

 printf("\nenter pid to delete:");scanf("%d",&pid);
 p[pid].st=0;

for(i=0;i<20;i++)
 if(p[i].st==1)
  printf("%d ",p[i].size);
printf("\nremaining memory:%d",rem);
}
}

int ava(struct pro p[])
{ rem1=0;
 int i,rem=0;
 for(i=0;i<20;i++)
 {
  if(p[i].st==1)
    rem=0;
  else {rem+=p[i].size;}
  if(rem1<rem)
   rem1=rem;
}
printf("\nlargest:%d",rem1);
 


}
