#include<stdio.h>

struct proc
{

 char n;

 int at,st,ft,tt,pt,rt,flag;
	
}p[20],r[20],pp;
 
int front=-1,rear=-1;

void push(struct proc v)

{
 
if(front==-1)

  front++;
rear++;

 r[rear]=v;

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

 char m;

 int i,cur=0,in,n,sl,j,k,total=0;

 printf("Enter no of processes:");

 scanf("%d",&n);

 printf("Enter slicing time:");

 scanf("%d",&sl);

 for(i=0;i<n;i++)
     {
      printf("\nEnter arrival time:");

      scanf("%d",&p[i].at);
	
      printf("Enter service time:");

      scanf("%d",&p[i].st); 
      total+=p[i].st; p[i].rt=p[i].st;
     }

 p[i].n='A'+i;

 p[i].flag=0;

 p[i].pt=0;

 for(i=0;i<n;i++)
    
for(j=0;j<n-i-1;j++)

       if(p[j].at>p[j+1].at)
       
	  {
           pp=p[j];
        
   p[j]=p[j+1];
 
	   p[j+1]=pp;
          }


 
for(cur=p[0].at;cur<total+p[0].at;)

   {
  
  for(j=0;j<n;j++)

 	if(p[j].at<=cur&&p[j].rt!=0&&p[j].flag==0)
   
	     {
              push(p[j]);
              p[j].flag=1;
             }
    

in=pop();
 
   for(k=0;k<n;k++)
	
	if(p[k].n==r[in].n)
	
  	   {
            in=k; 
            break;
           }
 

   if(p[in].rt>sl)
  
	{
         p[in].rt-=sl;
  
 	 cur+=sl;
 
	 for(j=0;j<n;j++)

 	     if(p[j].at<=cur&&p[j].rt!=0&&p[j].flag==0)
		
		{
                 push(p[j]);
                 p[j].flag=1; 
                }

         push(p[in]);

	}

    else 
	
	{
         cur+=p[in].rt;
 
	 p[in].rt=0;
        }
    
printf("\nProcess %c  ",p[in].n);
   
}
 

return 0;

}
	

  
