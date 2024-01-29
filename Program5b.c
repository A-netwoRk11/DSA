//Implementation of queue using Doubly linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
}*front,*rear;

//create a empty node
struct node *create_node()
{
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  return(p);
}

//enqueue() operation
void enqueue(int x)
{
  struct node *new1;
  new1=create_node();
  if(new1==NULL)
  {
	  printf("\nOverflow");
	  return;
  }
  new1->data=x;
  new1->next=NULL;
  new1->prev=NULL;
  if(front==NULL)
  {
	  front=new1;
	  rear= new1;
  } 
  else
  {
    rear->next=new1;
    new1->prev=rear;
    rear=new1;
  }
} 

//dequeue() operation
int dequeue()
{
  int x;
  struct node *del;
  if(front==NULL)
  {
    printf("\nUnderflow-->Linked list empty"); 
    return(-1);
  }
  x=front->data;
  del=front;
  if(front==rear)
    	front=rear=NULL;
  else
   	front=front->next;
   	front->prev=NULL;
  free(del);
  return(x);
}

//Peek Operation
int peek()
{
  int x;
  if(front==NULL)
  {
    printf("\nLinked list empty"); 
    return(-1);
  }
  x=front->data;
  return(x);
}

//display queue
void display()
{
  struct node *save;
  if(front==NULL)
  {
    printf("\nUnderflow");
    return;
  }
  save=front;
  printf("\nQueue data: ");
  while(save!=NULL)
  {
    printf("\t%d",save->data);
    save=save->next;
  }
}

int main()
{
  int ch,n;
  front=NULL;
  rear=NULL;
  system("cls");
  do
  {
    printf("\n1. Enqueue or INSERT");
    printf("\n2. Dequeue or DELETE");
    printf("\n3. PEEK");
    printf("\n4. Display");
    printf("\n5. End program");
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
 