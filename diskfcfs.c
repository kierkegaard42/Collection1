#include<stdio.h>
#include<math.h>
int main()
{
 int seek=0,n;
 printf("\n Enter no. of requests:");
 scanf("%d",&n);
 int arr[n+1],i,s;
 printf("\n Enter starting node:");
 scanf("%d",&s);
 arr[0]=s;
 printf("\n Enter requests in order:");
 for(i=1;i<=n;i++)
   scanf("%d",&arr[i]); 
 for(i=0;i<n;i++)
    seek+=abs(arr[i]-arr[i+1]);
 printf("\n Seek time:%d",seek);
 return 0;
}   
