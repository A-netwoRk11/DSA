//stack implementation using Doubly linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
}*top;

//create a empty node
struct node *create_node()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return(p);
}

//PUSH operation
void push(int x)
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
  if(top==NULL)
  {
	  top=new1;
  }
  else
  {
 	  new1->next=top;
 	  top->prev=new1;
  	top=new1;
  } 
}

//pop operation
int pop ()
{
  int x;
  struct node *del;
  if(top==NULL)
  {
    printf("\nunderflow-->Linked list empty");
    return(-1);
  }
  del=top;
  x=top->data;
  top=top->next;
  top->prev=NULL;
  free(del);
  return(x);
}

//Peek operation
int peek()
{
  if(top==NULL)
  {
    printf("\nUnderflow-->Linked list empty");
    return(-1);
  }
  return(top->data);
}

//display operation
void display()
{
  struct node *save;
  if(top==NULL)
  {
    printf("\nUnderflow");
    return;
  }
  save=top;
  printf("\nStack data: ");
  while(save!=NULL)
  {
    printf("\t%d",save->data);
    save=save->next;
  }
}

int main()
{
  int ch,n;
  top=NULL;
  system("cls");
  do
  {
    printf("\n1. PUSH or INSERT");
    printf("\n2. POP or DELETE");
    printf("\n3. PEEK or SEARCH");
    printf("\n4. Display");
    printf("\n5. End program");
    printf("\nEnter Choice : ");
    scanf("%d",&ch);  
    switch(ch)
    {
      case 1:
       			printf("\nEnter the element : ");
     			  scanf("%d",&n);
	      		push(n);
	          break;
      case 2:
    			n=pop();
    			if(n!=-1)
    			  printf("\n%d is the popped element",n);
    			break;
	    case 3:
   				n=peek();
   				if(n!=-1)
    			  printf("\n%d is the topmost element",n);
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
