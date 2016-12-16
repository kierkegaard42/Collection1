#include<stdio.h>

void main()

{

 int size,psize,usize,n,i=0,j,k,f=0,flag=0,rem;
  
 int parray[100][2]={0},pid,status[100];
  
 char y;
  
 printf("Enter the size of memory:");
  
 scanf("%d",&size);
  
 printf("Enter the fixed partition size:");
  
 scanf("%d",&psize);
  
 n=size/psize;
  
 rem=n;
  
 do
  
  {
     
   printf("Enter 'A' for allocation and 'D' for deallocation and 'F' for calculating for internal fragmentation and 'Q' for quit:");
    
   scanf(" %c",&y);
   
   switch(y)
     
    {
      
     case 'A':
    printf("Enter process ID:");
       
                  scanf("%d",&pid);

                  printf("Enter process size:");
  
                  scanf("%d",&usize);
         
                  if(usize%psize==0)
          
                       j=usize/psize;
        
                  else
      
                       j=(usize/psize)+1;
       
                  if(j<=rem)
       
                      {
           
                       for(k=0;k<n;k++)
       
                          {
    
                           if(i>=j)
     
                              break;
 
                           else
     
                             {
     
                              if(status[k]!=1)
  
                                 {
  
                                  parray[k][0]=pid;  
 
                         	  if(usize>=psize)

                                     {
   
                                      parray[k][1]=0;
   
                                      usize-=psize;
  
                                     }
     
                                  else
  
                                     {
    
                                      parray[k][1]=psize-usize;
  
                                      usize=0;
     
                                     }
      
                                  status[k]=1;
   
                                  rem--;
   
                                  i++;
  
                                 }
     
                              }
     
                          }
    
                       printf("%d partitions allocated successfully\n",j);
     
                      } 
     
                  else
      
                       printf("No enough memory\n");
  
                  break;
 
     case 'D':
    printf("Enter process id:");
   
                  scanf("%d",&pid);
 
                  for(k=0;k<n;k++)
 
                    {
      
                     if(parray[k][0]==pid)
    
                         {
  
                          status[k]=0;
  
                          parray[k][1]=0;

                          flag=1;
  
                          rem++;
     
                         }
  
                    }
 
                  if(flag!=1)
   
                      printf("Memory is not yet allocated for the process %d\n",pid);
    
                  else
        
                      printf("Deallocated successfully\n");
   
                  break;
      
     case 'F':
    f=0;
   
                  for(k=0;k<n;k++)
  
                     {
    
                      if(status[k]==1)

                         f+=parray[k][1];
  
                     }
    
                  printf("Internal fragmented memory %d\n",f);
    
                  break;
   
    }
   
  }while(y!='Q');
 
}

              
               

                  
