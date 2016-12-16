#include<semaphore.h>
#include<sys/types.h>
#include<stdio.h>
#include<pthread.h>
int readers;
sem_t mutex;
sem_t wsem;
void seat_availability()
{
	for(int i=0;i<50;i++)
	{
		if(arr[1]==1)
		printf("%d\t",i+1);
	}
}
void book_tickets()
{
	int sno;
	printf("\n Enter the seat number: ");
	scanf("%d",&sno);
	if(a[sno]==0)
	{
		printf("\n Seat Already Booked!!!!!");
	}
	else
		printf("\n Seat successfully booked");
}
void cancel_tickets()
{
	ins sno;
	printf("\n Enter the seat number: ");
	scanf("%d",&sno);
	if(a[sno]==0)
	{
		printf("\n Seat Sucessfully ccancelled!!!!!");
	}
	else
		printf("\n Seat not booked yet");
}
	
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
   seat_availability();
   sem_wait(&mutex);
   readers--;
   if(readers==0)
       sem_post(&wsem);
   sem_post(&mutex);
  }
}
void* writer()
{
	int choice;
 while(1)
  {
   sleep(1);
   sem_wait(&wsem);
   printf("\n Writer writing data");
   printf("\n\n Enter the choice: 1. See Availability \n2. Book Tickets \n3. Cancel Tickets);
   scanf("%d",&choice);
   switch(choice)
   {
	case 1: seat_availability();break;
	case 2: book_tickets();break;
	case 3: cancel_ticket();break;
	default: printf("\n\n Enter a valid choice");
   }
   sem_post(&wsem);
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
