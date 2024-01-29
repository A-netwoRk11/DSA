// Practical 3.3 Double ended queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX], front = -1,rear=-1;
//insert at front end
void insert_at_front(int data)
{
   if(front==(rear+1)%MAX)
	{
		printf("\nQueue is full --> Overflow");
		return;
	}
   if(front == -1 && rear ==-1)
   {
   	front=rear=0;
   }
   else if(front==0)
   {
	   front=MAX-1;
   }
   else
   {
 	   front=front-1;
   }
   queue[front]=data;
}

//insert at rear end
void insert_at_rear(int data)
{
   if(front==(rear+1)%MAX)
	{
		printf("\nQueue is full --> Overflow");
		return;
	}
   if(front == -1 && rear ==-1)
   {
    front=rear=0;
   }
   else
   {
	   rear=(rear+1)%MAX;
   }
   queue[rear]=data;
}

//delete at front end
int delete_at_front()
{
   int value;
   if(front==-1)
	{
		printf("\nQueue is empty --> Underflow");
		return(-1);
	}
   value=queue[front];
   if(front ==rear)
   {
      front=rear=-1;
   }
   else
   {
      front=(front+1)%MAX;
   }
   return(value);
}

//delete at rear end
int delete_at_rear()
{
 int value;
   if(front==-1)
	{
		printf("\nQueue is empty--> Underflow");
		return(-1);
	}
   value=queue[rear];
   if(front == rear)
   {
      front=rear=-1;
   }
   else if(rear==0)
   {
      rear=MAX-1;
   }
   else
   {
      rear=rear-1;
   }
   return(value);
}


void display()
{
   int i;
   if(front==-1)
   {
     printf("\nunder flow Queue or Queue is empty");
   }
   else
   {
      printf("\nElemets : ");
      for(i=front; i!=rear; i=(i+1)%MAX)
    	{   
         printf("\n%d",queue[i]);
      }
      printf("\n%d",queue[i]);
   }
}

//get element from front end
int peek_front()
{
   int p;
   if(front==-1)
   {
      printf("\nQueue is empty !!!");
      return(-1);
   }
   else
   {
	   return(queue[front]);
   }
}

//get element from rear end
int peek_rear()
{
   int p;
   if(front==-1)
   {
      printf("\nQueue is empty !!!");
      return(-1);
   }
   else
   {
	   return(queue[rear]);
   }
}

int main()
{
   int ch,n;
   system("cls");
   do
   {
      printf("\n1. Insert at front");
      printf("\n2. Insert at rear");
      printf("\n3. Delete from front");
      printf("\n4. Delete from rear");
      printf("\n5. PEEK from front");
      printf("\n6. PEEK from rear");
      printf("\n7. Display");
      printf("\n8. End program");
      printf("\n-----------------------");
      printf("\nEnter Choice : ");
      scanf("%d",&ch);  
      switch(ch)
      {
         case 1:
       		printf("\nEnter the element : ");
     			scanf("%d",&n);
	      	insert_at_front(n);
	         break;
	      
         case 2: 	
            printf("\nEnter the element : ");
     			scanf("%d",&n);
            insert_at_rear(n);
            break;
       
         case 3:
    			n=delete_at_front();
    			if(n!=-1)
            {
    			   printf("\n%d is the deleted element",n);
            }
            break;
       
         case 4:
    			n=delete_at_rear();
    			if(n!=-1)
            {
    			   printf("\n%d is the deleted element",n);
            }
            break;
	      
         case 5:
   			n=peek_front();
   			if(n!=-1)
            {
    			   printf("\n%d is the front element",n);
            }
            break;
   	   
         case 6:
   			n=peek_rear();
   			if(n!=-1)
    			{   
               printf("\n%d is the rear element",n);
            }
            break;
       
         case 7:
    			display();
    			break;
         default:
 				printf("\ninvalid choice !!!");
 				break;
      } 
   }while(ch!=8);
   return(0);    
}