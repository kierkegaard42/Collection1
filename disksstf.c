#include<stdio.h>
#include<math.h>
int main()
{
 int s,seek=0,min=1000,n,i,tot,j=0,k=0,pos=-1;
 printf("\n Enter total no. of disks:");
 scanf("%d",&tot);
 printf("\n Enter head position:");
 scanf("%d",&s);
 printf("\n Enter no. of requests:");
 scanf("%d",&n);
 int arr[n],a[n];
 printf("\n Enter requests in order:");
 for(i=0;i<n;i++)
     {
      scanf("%d",&arr[i]);
      if(arr[i]>=tot)
        {
         printf("\n Wrong value!!Enter again...");
         while(arr[i]>=tot)
            scanf("%d",&arr[i]);
        }
      a[i]=0;
     }
 for(i=0;i<n;i++)
  {
   min=1000;
   for(j=0;j<n;j++)
      if((abs(s-arr[j])<min)&&a[j]!=1)
           {
            min=abs(s-arr[j]);
            pos=j;
           } 
   seek+=min;
   a[pos]=1;
   s=arr[pos]; 
   printf("%d\t",arr[pos]);
  }
 printf("\n Total seektime:%d",seek);           
 return 0;
}
