#include<stdio.h>
int main()
{
 int n,m;
 printf("\n No. of processes:");
 scanf("%d",&n);
 printf("\n No. of resources:");
 scanf("%d",&m);
 int resource[m],claim[n][m],alloc[n][m],rem[n][m],r[n],v[m];
 int i,j,k,p,possible=1;
 for(i=0;i<n;i++)
   r[i]=0;
 printf("\n Resource vector:");
 for(i=0;i<m;i++)
  scanf("%d",&resource[i]); 
 printf("\n Available vector:");
 for(i=0;i<m;i++)
  scanf("%d",&v[i]);
 printf("\n Claim Matrix:");
 for(i=0;i<n;i++)
   for(j=0;j<m;j++)
     scanf("%d",&claim[i][j]);
 printf("\n Allocation Matrix:");
 for(i=0;i<n;i++)
   for(j=0;j<m;j++)
     {
      scanf("%d",&p);
      while(p>claim[i][j])
        {
         printf("\n Wrong value!!Enter again:");
         scanf("%d",&p);
        }
      if(p<=claim[i][j])
         {
          alloc[i][j]=p;
          rem[i][j]=claim[i][j]-alloc[i][j];
         } 
     }
 for(i=0;(i<=n)&&(r[i]==0);i=(i+1)%n)
  {
   printf("\n i=%d   n=%d    r[i]=%d",i,n,r[i]);
   possible=0;
   for(j=0;j<m;j++)
    {
     if(rem[i][j]<=v[j])
        possible++;
     else
        possible=0;
    }
   if(possible==m)
    {
     for(j=0;j<m;j++)
      {
       v[j]=v[j]+alloc[i][j];
       alloc[i][j]=0;
       rem[i][j]=0;
       r[i]=1;
      }
     printf("\n Process %d has completed.",i+1);
     printf("\n Available Resources:");
     for(k=0;k<m;k++)
       printf("%d   ",v[k]);
    }
   else
    {
     printf("\n Not possible for process %d",i+1);
     continue;
    }
  }
 return 0;
} 
