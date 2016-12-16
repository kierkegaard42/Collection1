#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

int i,person=5,j;
sem_t forks[5];
void *philosopher(void *j)
{
int i=(int) j;
while(1)
{
sleep(1);
sem_wait(&forks[i]);
sem_wait(&forks[(i+1)%5]);
printf("\nphilosopher %d is eating ",i);

sem_post(&forks[(i+1)%5]);
sem_post(&forks[i]);
printf("\nphilosopher %d is thinking",i);
}
}

int main()
{
pthread_attr_t *attr=NULL;
pthread_t p_tid[5];
int i;
for(i=0;i<5;i++)
sem_init(&forks[i],0,1);
for(i=0;i<5;i++)
pthread_create(&p_tid[i],attr,philosopher,(void *)i);
for(i=0;i<5;i++)
pthread_join(p_tid[i],NULL);
}
