#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
#define n 5
#define left (i+n-1)%n
#define right (i+1)%5
#define thinking 0
#define hungry 1
#define eating 2
int state[n];
sem_t s[n],mutex;
void test(int i)
{
 if((state[i]==hungry)&&(state[left]!=eating)&&(state[right]!=eating))
  {
   state[i]=eating;
   printf("\n Philosopher %d is eating...",i+1);
   sem_post(&s[i]);
  }
}
void take(int i)
{
 sem_wait(&mutex);
 state[i]=hungry;
 printf("\n Philosopher %d is hungry...",i+1);
 test(i);
 sem_post(&mutex);
 sem_wait(&s[i]);
}
void put(int i)
{
 sem_wait(&mutex);
 state[i]=thinking;
 test(left);
 test(right);
 sem_post(&mutex);
}

void* philosopher(void* i)
{
 int index=(int)i;
 while(1)
  { 
   sleep(1);
   take(index);
   sleep(1);
   put(index);
  }
}
int main()
{
 pthread_attr_t *attr=NULL;
 pthread_t philo[n];
 int i;
 sem_init(&mutex,0,1);
 for(i=0;i<n;i++)
  {
   sem_init(&s[i],0,0);
   pthread_create(&philo[i],attr,philosopher,(void*)i);
   state[i]=thinking;
   printf("\n Philosopher %d is waiting...",i+1);
  }
 for(i=0;i<n;i++)
   pthread_join(philo[i],NULL);
 return 0;
}   
