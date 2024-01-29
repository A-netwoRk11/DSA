// Practical 3.1 simple queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int queue[MAX], front = -1,rear=-1;

void enqueue(int data)
{
  if(rear==MAX-1)
	{
		printf("\nQueue is full--> Overflow");
		return;
	}
   if(front == -1 && rear ==-1)
      front=rear=0;
   else
	   rear=rear+1;
      queue[rear]=data;
}


int dequeue()
{
  int value;
   if(front==-1)
	{
		printf("\nQueue is empty --> Underflow");
		return(-1);
	}
   value=queue[front];
   if(front ==rear)
      front=rear=-1;
   else
      front=front+1;
      return(value);

}

void display()
{
   int i;
   if(front==-1)
     printf("\nunder flow Queue or Queue is empty");
   else
   {
      printf("\nElemets : ");
      for(i=front; i<=rear; i++)
    	   printf("\n%d",queue[i]);
   }
}
int peek()
{
   int p;
   if(front==-1)
   {
      printf("\nQueue is empty !!!");
      return(-1);
   }
   else
	return(queue[front]);
}


int main()
{
   int ch,n;
   system("cls");
   do {
   printf("\n1. Enqueue or INSERT");
   printf("\n2. Dequeue or DELETE");
   printf("\n3. PEEK");
   printf("\n4. Display");
   printf("\n5. End program");
   printf("\n");
   printf("\nEnter Choice : ");
   scanf("%d",&ch);  
   switch(ch)
     {
         case 1:
       		printf("\nEnter the element : ");
     			scanf("%d",&n);
	      	enqueue(n);
	         break;
         case 2:
    			n=dequeue();
    			if(n!=-1)
    			   printf("\n%d is the deleted element",n);
    			break;
	      case 3:
   			n=peek();
   			if(n!=-1)
    			   printf("\n%d is the front element",n);
   			break;
         case 4:
    			display();
    			break;
         default:
 				printf("\ninvalid choice !!!");
 				break;
      } 
   }while(ch!=5);
   return(0);    
}