#include<stdio.h>
void sort(int a[],int n)
{
 int i,j;
 for(i=0;i<=n;++i)
    for(j=0;j<n-i;++j)
      if(a[j]>a[j+1])
	{
	 int t=a[j+1];
	 a[j+1]=a[j];
	 a[j]=t;
        }
}
int main()
{
 int tot=0,n,cur,track,i,pos;
 printf("Enter the no of tracks : ");
 scanf("%d",&track);	
 printf("Enter initial head position : ");
 scanf("%d",&cur);
 while(cur>track)
   {
    printf("Invalid positon!!!\n");
    printf("Enter initial head position : ");
    scanf("%d",&cur);
   }
 printf("Enter the no of requests : ");
 scanf("%d",&n);
 int a[n+1];
 a[0]=cur;
 printf("Enter the track requests :\n");
 for(i=1;i<=n;++i)
   {	 
    scanf("%d",&a[i]);
    while(a[i]>track)
      {
       printf("Invalid track!!!\n");		
       scanf("%d",&a[i]);
      }
   }
 sort(a,n+1);
 for(i=0;i<=n;i++)
    if(a[i]==cur)
       {
        pos=i;
        break;
       }
 for(i=pos;i<=n;i++)
     printf("%d-->",a[i]);
 printf("0");
 for(i=0;i<pos;i++)       
     printf("-->%d",a[i]);
 printf("\n\n\n");     
 for(i=0;i<=n;++i)
    if(a[i]==cur)
	break;
 cur=i;
 tot+=a[n]-a[cur];
 tot+=a[cur-1]+a[n];
 printf("The total seek time : %d\n",tot);
 return 0;
}