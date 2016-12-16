#include<stdio.h>
int main()
{
 int memsize,psize,frag,ch,size,i;
 unsigned int pid=1,id;
 printf("\n Enter memory size:");
 scanf("%d",&memsize);
 printf("\n Enter partition size:");
 scanf("%d",&psize);
 int n=memsize/psize;
 int a[n],fr[n];
 for(i=0;i<n;i++)
   {
    a[i]=-1;
    fr[i]=0;
   }
 while(1)
  {
   printf("\n\t\t\t\t PARTITIONING");
   printf("\n\n 1. Add a process    2. Remove a process   3. Calculate Internal Fragmentation");
   printf("\n Your choice:");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1:    printf("\n Enter size for process %d:",pid);
                 scanf("%d",&size);
                 if(size>psize)
                      {
                       printf("\n Process Size is greater than partition size!!");
                       continue;
                      }
                 for(i=0;i<n;i++)
                   if(a[i]==-1)
                      {
                       a[i]=pid;
                       pid++;
                       fr[i]=psize-size; 
                       printf("\n Process %d has been allocated partition %d",pid-1,i+1);   
                       break;                   
                      }
                 if(i==n)
                    printf("\n Sorry, Memory is currently full right now.");
                 break;

      case 2:    printf("\n Enter process ID:");
                 scanf("%d",&id);
                 for(i=0;i<n;i++)
                   if(a[i]==id)
                     {
                      a[i]=-1;
                      fr[i]=0; 
                      printf("\n Process has been removed from memory.");
                      break;
                     }
                 if(i==n)
                    printf("\n Process not found!!");
                 break;
 
      case 3:   frag=0;
                for(i=0;i<n;i++)
                    frag+=fr[i];
		printf("\n Total Internal fragmentation:%d",frag);
                break;
     }
  }
 return 0;
}
 
