/*#include<semaphore.h>

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

}*/   








#include<semaphore.h>

#include<sys/types.h>

#include<stdio.h>

#include<pthread.h>

int readers,writers;

sem_t x;

sem_t y;

sem_t z;

sem_t wsem;

sem_t rsem;


void* reader()

{

 while(1)

  {

   sleep(1);

   sem_wait(&z);

   sem_wait(&rsem);

   sem_wait(&x);

   readers++;

   if(readers==1)

       sem_wait(&wsem);

   sem_post(&x);

   sem_post(&rsem);

   sem_post(&z);

   printf("\n Reader reading data");
 
   sem_wait(&x);

   readers--;

   if(readers==0)

       sem_post(&wsem);

   sem_post(&x);

  }

}

void* writer()

{

 while(1)

  {

   sleep(1);

   //sem_wait(&wwsem);	
   sem_wait(&y);

   writers++;

   if(writers==1)

       sem_wait(&rsem);

   sem_post(&y);

   sem_wait(&wsem);

   printf("\n Writer writing data");

   sem_post(&wsem);

   sem_wait(&y);
   writers--;

   if(writers==0)

      sem_post(&rsem);

   sem_post(&y);

  }

}

int main()

{


 readers=0;

 writers=0;

 pthread_attr_t* attr=NULL;

 pthread_t rd;

 pthread_t wr;

 sem_init(&x,0,1);

 sem_init(&y,0,1);

 sem_init(&z,0,1);

 sem_init(&rsem,0,1);

 sem_init(&wsem,0,1);

 pthread_create(&wr,attr,writer,0);

 pthread_create(&rd,attr,reader,0);

 pthread_join(rd,NULL);

 pthread_join(wr,NULL);

 return 0;

}   
