#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
int front=-1;int rear=-1,pos;
int arr[10];
int pid,cid;
sem_t fc;
sem_t ec;
sem_t pc;
sem_t mutex;
int produceitem()
{
 static int a=100;
 return a++;
}

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
void* produce(void* arg)
{
 int item;
 int i=(int)arg;
 while(1)
  {
   item=produceitem();
   sem_wait(&pc);
   sem_wait(&ec);
   sem_wait(&mutex);
   printf("\n\t\t PRODUCER");
   push(item);
   sem_post(&pc);
   printf("\n Producer %d inserting data %d in %d",i,item,rear);
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
 pthread_t p_tid[5];
 pthread_t c_tid;
 sem_init(&mutex,0,1);
 sem_init(&ec,0,10);
 sem_init(&fc,0,0);
 sem_init(&pc,0,1);
 for(i=0;i<5;i++)
    pthread_create(&p_tid[i],attr,produce,(void*)i);
 pthread_create(&c_tid,attr,consume,0);
 for(i=0;i<5;i++)
     pthread_join(p_tid[i],NULL);
 pthread_join(c_tid,NULL);
 return 0;
}
