#include<stdio.h>
int main()
{
 int memsize,frag=0,ch,size,i,j,tot=0,t=0;
 unsigned int pid=1,id;
 printf("\n Enter memory size:");
 scanf("%d",&memsize);
 int n=10;
 int a[n],fr[n];
 for(i=0;i<n;i++)
   {
    a[i]=-1;
    fr[i]=-1;
   }
 while(1)
  {
   printf("\n\t\t\t\t PARTITIONING");
   printf("\n\n 1. Add a process    2. Remove a process   3. Calculate External Fragmentation");
   printf("\n Your choice:");
   scanf("%d",&ch);
   switch(ch)
     {
      case 1:    printf("\n Enter size for process %d:",pid);
                 scanf("%d",&size);
		 if(tot+size>memsize)
		{	printf("\n Sorry, Memory is currently full right now.");
			break;
		}
		tot+=size;
                 for(i=0;i<n;i++)
                   if(a[i]==-1)
                      {
                       	if(a[i+1]==-1)
			{	a[i]=pid;
			       fr[i]=size;		
        	               pid++;
         			break;                 
                      	}
			else if(fr[i]>=size)
			{	for(j=n;j>=i+1;j--)
				{	a[j]=a[j-1];
					fr[j]=fr[j-1];
				}
				fr[i+1]=fr[i]-size;
				a[i]=pid;
				fr[i]=size;
				pid++;
				frag-=size;	
				break;
			}
		       }
	/*	for(i=0;i<n;i++)
			printf("%d\t",a[i]);
		printf("\n");
		 for(i=0;i<n;i++)
			printf("%d\t",fr[i]);		
     */            break;

      case 2:    printf("\n Enter process ID:");
                 scanf("%d",&id);
                 for(i=0;i<n;i++)
                   if(a[i]==id)
                     {
                      a[i]=-1;
		      tot-=fr[i];
		 	if(a[i+1]==-1&&fr[i+1]==-1)
			{	j=i;
				fr[i]=-1;
				while(a[j-1]==-1)
				{	frag-=fr[j-1];
					fr[j-1]=-1;
					j--;
				}
			}
                     	else if((a[i+1]==-1&&fr[i+1]!=-1))
			{	frag+=fr[i];
				fr[i]+=fr[i+1];
				for(j=i+1;j<n-1;j++)
				{	a[j]=a[j+1];
					fr[j]=fr[j+1];
				}
			}
			else if((a[i-1]==-1&&fr[i-1]!=-1))
			{	frag+=fr[i];
				fr[i-1]+=fr[i];
				for(j=i;j<n-1;j++)
				{	a[j]=a[j+1];
					fr[j]=fr[j+1];
				}
			}
			else frag+=fr[i];
		        printf("\n Process has been removed from memory.");
			printf("\n");
			for(i=0;i<n;i++)
				printf("%d\t",a[i]);
			printf("\n");
			 for(i=0;i<n;i++)
				printf("%d\t",fr[i]);		
                	break;
                     }
                 if(i==n)
                    printf("\n Process not found!!");
                 break;
 
      case 3:   printf("\n Total External fragmentation:%d",frag);
                break;
     }
  }
 return 0;
}
 
