//Program for Circular singly link list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*head;

//create a empty node
struct node *create_node()
{
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  return(p);
}

//count a node in the list
int count_node()
{
  struct node *save;
  int i=0;
  if(head==NULL)
  {
    return(0);
  }
  save=head;
  while(save->next!=head)
  {
    save=save->next;
    ++i;
  }
  return (i+1);
}

//display a list
void display(struct node *p)
{
  struct node *save;
  save=p;
  printf("\n============================");
  if(save==NULL)
  {
    printf("\nLinked list empty: ");
    return;
  }
  
  printf("\nLinked data: ");
  while(save->next!=head)
  {
    printf("\t%d",save->data);
    save=save->next;
  }
  printf("\t%d",save->data);  
  printf("\n============================");
}

// search a element in list
void search(int x)
{
  struct node *save;
  if(head==NULL)
  {
  	printf("\nList is empty");
  	return;
  }
  save=head;
  while(save->data!=x)
	{
	  save=save->next;
	  if(save->next==head)
		  break;
  }
  if(save->data==x  || save->next!=head )
	  printf("\nKey found");
  else
	  printf("\nKey not found");
}

//insert at begining
void insert_at_begin(int x)
{
  struct node *new1,*save;
  new1=create_node();
  if(new1==NULL)
  {
	  printf("\nOverflow");
	  return;
  }
  new1->data=x;
  if(head==NULL)
	{
	  head=new1;
	  new1->next=head;
	}
  else
  {
    save=head;
    while(save->next!=head)
 	  {
      save=save->next;
    }
    new1->next=head;
    save->next=new1;
    head=new1;
  }
}

//insert node at end
void insert_at_end(int x)
{
  struct node *new1,*save;
  new1=create_node();
  if(new1==NULL)
  {
	  printf("\nOverflow");
	  return;
  }
  new1->data=x;
  if(head==NULL)
  {
	  head=new1;
	  new1->next=head;
  }
  else
  {
    save=head;
    while(save->next!=head)
    {
      save=save->next;
      save->next=new1;
      new1->next=head;
    }
  }
} 

//insert after a node contain given value
void insert_after(int x,int n)
{
  struct node *new1,*save;
  new1=create_node();
  if(new1==NULL)
  {
	  printf("\nOverflow");
	  return;
  }
  new1->data=x;
  save=head;
  while(save->data!=n)
	{ 
	  save=save->next;
	  if(save->next==head)
    {
	    break;
    }
  }
  if(save->next!=head)
 	{	
	  new1->next=save->next;
	  save->next=new1;
	}	
  else if(save->data==n)
  {
  	insert_at_begin(x);
  }
  else
  {
  	printf("\nNode not found");
  }
}

//insert before a node 
void insert_before(int x,int n)
{
  struct node *new1,*save,*prev;
  new1=create_node();
  if(new1==NULL)
  {
	  printf("\nOverflow");
	  return;
  }
  new1->data=x;
  if(head->data==n)
  {
    insert_at_end(x);
    return;
  }
  save=head;
  while(save->data!=n)
	{
	  prev=save;
	  save=save->next;
	  if(save->next==head)
    {
		  break;
    }
  }
  if(save->data==n || save->next !=head )
  {
 	  new1->next=prev->next; 
    prev->next=new1;
  }
  else
  {
    printf("\nNode not found");
  }
}

//insert at specific Position
void insert_at_specific_pos(int x,int pos)
{
  struct node *new1,*save;
  int cnt,i=1;
  cnt=count_node();
  if(pos>cnt)
  {
    printf("\nPosition is not found: ");
    return;
  }
  new1=create_node();
  if(new1==NULL)
  {
	  printf("\nOverflow");
	  return;
  }
  new1->data=x;
  if(pos==1)
  {
    insert_at_begin(x);
    return;
  }
  save=head;
  while(i!=pos-1)
	{ 
    save=save->next; ++i;	
	  if(save->next==head)
	  {
      break;
    }
	}
  printf("\nposition i=%d",i);
  if(save->next==head)
  {
    insert_at_end(x);
  }
  else
  {
    new1->next=save->next;
	  save->next=new1;
  }
}

// delete at begining
int delete_at_begin()
{
  int x;
  struct node *save,*del;
  if(head==NULL)
  {
    printf("\nLinked list empty");
    return(-1);
  }
  del=head;
  x=head->data;
  if(head->next==head) //only one node in list
 	{
    head=NULL;
  }
  else
  {
	  save=head;
	  while(save->next!=head)
	  {
		  save=save->next;
 	  }
	  save->next=head->next;
	  head=head->next;
  } 
  free(del);
  return(x);
}

//delete at end
int delete_at_end()
{
  int x;
  struct node *save,*del;
  if(head==NULL)
  {
    printf("\nLinked list empty"); 
    return(-1);
  }
  if(head->next==head)
  {
    x=head->data;
    free(head);
    head=NULL;
    return(x);
  }
  save=head;
  while(save->next->next!=head)
  {  
    save=save->next;
  }
  x=save->next->data; 
  free(save->next);
  save->next=head;
  return(x);
}

//delete after a node
int delete_after_node(int n)
{
  int x;
  struct node *save, *del;
  if(head==NULL)
  {
    printf("\nLinked list empty"); 
    return(-1);
  }
  save=head;
  while (save->data !=n)
  {  
    save=save->next;
    if(save->next==head)
      break;
  }
  if(save->next!=head)
  {
	  del=save->next;
	  x=save->next->data;
	  save->next=save->next->next;
	  free(del);
	  return (x);
  }  
  if(save->data==n)
  { 
    x=delete_at_begin();
		return(x);
  }
  else
  {
    printf("\nGiven Node not Found");
    return(-1);
  }
}

//delete at node at specific position
int delete_a_specific_pos_node(int pos)
{
  int x,cnt,i=1;
  struct node *save, *del;
  if(head==NULL)
  {
    printf("\nLinked list empty"); 
    return(-1);
  }
  cnt=count_node();
  if(pos>cnt)
  {
    printf("\nPosition is not found: ");
    return(-1);
  }
  if(pos==1)
  {    
    x=delete_at_begin(x);
    return (x) ;
  }
  save=head;
  i=1;
  while( i!=pos-1)
	{ 
    save=save->next; ++i;
  }
  if(save->next->next!=head)
  {	
	  del=save->next;
	  x=save->next->data; 
	  save->next=save->next->next; 
	  free(del);
	  return (x);
	}	
  else
  {
    x=delete_at_end();
	  return(x);
  } 	
}

//delete specific node which contain given value
int delete_specific_value_node(int n)
{
  int x;
  struct node *save,*prev;
  if(head==NULL)
  {
    printf("\nLinked list empty"); 
    return(-1);
  }
  if(head->data ==n)
  {
    x=delete_at_begin(x);
    return (x) ;
  }
  save=head;
  while( save->data!=n)
  {  	
    prev=save;
    save=save->next;
    if(save->next==head)
	    break;
  } 	
	if(save->next!=head)
  {
  	x=save->data;
		prev->next=save->next;	
 		free(save);
		return (x);
  }
	else if (save->data==n)
	{
		x=delete_at_end();
		return(x);
	}
  else
 	{	
    printf("\nGiven Node not Found");
    return(-1);
  }
}

//delete entire list
void delete_list()
{
  struct node *save;
  if(head!=NULL)
  {
    save=head;
    while(save->next != head)
    {
      printf("\n %d is to be deleted next", delete_at_begin());
      save=head;
    }	
    printf("\n %d is to be deleted next", delete_at_begin());
  }
}

//copy a list
struct node *copy()
{
	struct node *new1;
	new1=head;
	return(new1);
}

int main()
{
  int ch,x,pos;
  struct node *p;
  head=NULL;
  system("cls");
  do
	{
 	  printf("\n============================");
	  printf("\nEnter the Choice: ");
	  printf("\n1:Insertion at begin");
	  printf("\n2:Insertion at end");
	  printf("\n3:Insertion at specific position");
	  printf("\n4:Insert after");
	  printf("\n5:Insert before");
	  printf("\n6:Display");
	  printf("\n7:Deletion at begin");
	  printf("\n8:Deletion at end");
	  printf("\n9:Deletion after");
	  printf("\n10:Deletion at specified Position");
	  printf("\n11:Delete at element x");
	  printf("\n12:Delete entire list");
	  printf("\n13:Search");
	  printf("\n14:Copy a list");
	  printf("\n15:Count Number of node in list");
	  printf("\n0:Exit");
	  printf("\n============================");
	  printf("\nYour Choice:- ");
	  scanf("%d", &ch);
	  printf("\n============================");
	  switch(ch)
	  {
		  case 1:
		   		printf("\nEnter the value to be inserted: ");
		   		scanf("%d",&x);
		   		insert_at_begin(x);
		   		break;
		  case 2:
          printf("\nEnter the value to be inserted: ");
          scanf("%d",&x);
          insert_at_end(x);
          break;
		  case 3:
		   	  printf("\nEnter the position where to be inserted: ");
		   	  scanf("%d",&pos);
		      printf("\nEnter the value to be inserted: ");
		      scanf("%d",&x);
		      insert_at_specific_pos(x, pos);
		      break;
		  case 4:
		   	  printf("\nEnter the value after where to be inserted: ");
		   	  scanf("%d",&pos);
		      printf("\nEnter the value to be inserted: ");
		      scanf("%d",&x);
		      insert_after(x,pos);
		      break;
		  case 5:
		   	  printf("\nEnter the value before where to be inserted: ");
		   	  scanf("%d",&pos);
		      printf("\nEnter the value to be inserted: ");
		      scanf("%d",&x);
		      insert_before(x,pos);
		      break;
		  case 6:
          display(head);
          break;
		  case 7:
          x=delete_at_begin();
          if(x!=-1)
            printf("\nDeleted element: %d",x);
          break;
		  case 8:
          x=delete_at_end();
          if(x!=-1)
            printf("\nDeleted element: %d",x);
          break;
		  case 9:
          printf("\nEnter the value after where to be deleted: ");
          scanf("%d",&pos);
          x=delete_after_node(pos);
          if(x!=-1)
            printf("\ndeleted element: %d",x);
          break;
		  case 10:
          printf("\nEnter the position of node to be deleted: ");
          scanf("%d",&pos);
          x=delete_a_specific_pos_node(pos);
          if(x!=-1)
            printf("\nDeleted element: %d",x);
          break;
		  case 11:
		   	  printf("\nEnter the value of node to be deleted: ");
		   	  scanf("%d",&pos);
		      x=delete_specific_value_node(pos);
		      if(x!=-1)
				    printf("\nDeleted element: %d",x);
		      break;
		  case 12: delete_list();
				  break; 
	    case 13:
		   	  printf("\nEnter the value to be search: ");
		      scanf("%d",&x);
		      search(x);
		      break;
		  case 14:
		   	  p=copy();
		   	  printf("\n copy of list");
		   	  display(p);
		   	  break; 
		  case 15:
		   	  x=count_node();
		   	  printf("\nNo. of node in list=%d",x);
		   	  break; 	  
		  default:
		      break;
	  }
  }while(ch!=0);
  return(0);       
}
