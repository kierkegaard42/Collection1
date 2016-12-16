#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
int front=-1;int rear=-1,pos;
int arr[10];
int pid,cid;
sem_t fc;
sem_t ec;
sem_t mutex;
int produceitem()
{
 static int a=100;
 return a++;
}
/*void push(int t)
{
 if(front==rear)
   {
    if(front==-1)
       front=rear=0;
    else
       rear++;
    arr[rear]=t; 
    return;
   }
 if(front==rear+1)
   {
    printf("\n QUEUE FULL!!"); 
    return;
   }
 if(rear==9)
   {
    if(front==0)
      {
       printf("\n QUEUE FULL!!");
       return;
      }
    else
      {
       rear=0;
       arr[rear]=t;
       return;
      }
   }
 arr[rear++]=t;
 return;
}
int pop()
{
 if(front==-1)
    {
     printf("\n Error!! QUEUE EMPTY!!");
     return;
    }
 int t=arr[front];
 if(front==rear)
    {
     t=arr[front];
     front=rear=-1;
     return t;
    }
 else if(front==9)
    {
     t=arr[front];
     front=0;
     return t;
    }
 else
     {
      t=arr[front];
      front++;    
      return t;
     }
}*/
void push(int t)
{
 if(front==-1)
    front=0;
 rear++;
 rear=rear%10;
 arr[rear]=t;
 return;
}
int pop()
{
 if(front==rear)
    front=rear=-1;
 pos=front;
 front++;
 front%=10;
 return arr[pos];
}
void* produce()
{
 int item;
 while(1)
  {
   item=produceitem();
   sem_wait(&ec);
   sem_wait(&mutex);
   printf("\n\t\t PRODUCER");
   push(item);
   printf("\n Producer inserting data %d in %d",item,rear);
   sem_post(&mutex);
   sem_post(&fc);
  }
}
void* consume()
{
 int item;
 while(1)
  {
   sleep(2);
   sem_wait(&fc);
   sem_wait(&mutex);
   printf("\n\t\t CONSUMER");
   item=pop();
   printf("\n Consumer consumed %d from %d",item,pos);
   sem_post(&mutex);
   sem_post(&ec);
  }
}
int main()
{
 int i;
 pthread_attr_t* attr=NULL;
 pthread_t p_tid;
 pthread_t c_tid;
 sem_init(&mutex,0,1);
 sem_init(&ec,0,10);
 sem_init(&fc,0,0);
 pthread_create(&p_tid,attr,produce,0);
 pthread_create(&c_tid,attr,consume,0);
 pthread_join(p_tid,NULL);
 pthread_join(c_tid,NULL);
 return 0;
}
