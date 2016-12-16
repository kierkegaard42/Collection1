#include<stdio.h>

int main()
{
 int size,p,psize,i,inf,rem,x,np,pars;
 printf("enter memory size:");
 scanf("%d",&size);
 int a[20]={0};i=0;
 printf("enter partition size:");
 scanf("%d",&pars);int pid;
 np=size/pars;rem=np;inf=0;
 while(1)
  {
   printf("enter process size:");
   scanf("%d",&psize);
   a[i]=psize;i++;
   x=psize/pars;
   if(psize%pars!=0)
     x++;
   if(rem>x)
     {  
      rem-=x;
      printf("Memory allocated\n");
     }
   else 
     {
      printf("memory overflow");
      break;
     }
   if(psize%pars!=0)
     inf+=(pars-(psize%pars));
   printf("Total internal fragmentation:%d\n",inf);
   printf("enter process to be deleted:");
   scanf("%d",&pid); 
   while(pid>19)
    {
     printf("\n Wrong value.... Enter again:");
     scanf("%d",&pid);
    }
   if(a[pid]==0)
      continue;
   x=a[pid]/pars;
   if(a[pid]%pars!=0)
      x++;
   if(a[pid]%pars!=0)
      inf-=(pars-(a[pid]%pars));
   rem+=x;
   a[pid]=0;
   printf("Process deleted:%d\n",inf);
  }
 return 0;
}
