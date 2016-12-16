#include<semaphore.h>

#include<sys/types.h>

#include<stdio.h>

#include<pthread.h>

int readers;

sem_t mutex;

sem_t wsem;


void* reader()

{

 while(1)

  {

   sleep(1);

   sem_wait(&mutex);

   readers++;

   if(readers==1)

       sem_wait(&wsem);

   sem_post(&mutex);

   printf("\n Reader reading data");

   sem_wait(&mutex);

   readers--;

   if(readers==0)

       sem_post(&wsem);

   sem_post(&mutex);

  }

}

void* writer()

{

 while(1)

  {

   sleep(1);

   //sem_wait(&wwsem);
   sem_wait(&wsem);

   printf("\n Writer writing data");

   sem_post(&wsem);

   //sem_post(&wwsem);

  }

}

int main()

{

 readers=0;

 pthread_attr_t* attr=NULL;

 pthread_t rd;

 pthread_t wr;

 sem_init(&mutex,0,1);

 sem_init(&wsem,0,1);

 pthread_create(&wr,attr,writer,0);

 pthread_create(&rd,attr,reader,0);

 pthread_join(rd,NULL);

 pthread_join(wr,NULL);

 return 0;

}
