//Program for single link list
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
	save=head;
	while(save!=NULL)
	{
		save=save->next;
		++i;
	}
	return (i);
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
	while(save!=NULL)
	{
		printf("\t%d",save->data);
		save=save->next;
	}
	printf("\n============================");
}

//insert at beginning
void insert_at_begin(int x)
{
	struct node *new1;
	new1=create_node();
	if(new1==NULL)
	{
		printf("\nOverflow");
		return;
	}
	new1->data=x;
	new1->next=head;
	head=new1;
}

//insert at end
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
	new1->next=NULL;
	if(head==NULL)
	{
		head=new1;
	}
	else
	{
		save=head;
		while(save->next!=NULL)
		{
			save=save->next;
		}
		save->next=new1;
	}
} 

//insert at specific position
void insert_at_specific_pos(int x,int pos)
{
	struct node *new1,*save;
	int cnt,i;
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
	printf("\n empty node created");   
	new1->data=x;
	new1->next=NULL;
	if(pos==1)
	{
		new1->next=head;
		head=new1;
		return;
	}
	save=head;
	i=1;
	while(i!=pos-1)
	{ 
		save=save->next;
		++i;
	}
	new1->next=save->next;
	save->next=new1;
}

//insert after a specific value
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
	new1->next=NULL;
	save=head;
	while(save->data!=n)
	{
		save=save->next;
		if(save==NULL)
		break;
	}
	if(save!=NULL)
	{
		new1->next=save->next;
		save->next=new1;
	}
	else
	{
	printf("\nNode not found");
	}
}

//insert before a specific value
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
	new1->next=NULL;
	if(head->data==n)
	{
		new1->next=head;
		head=new1;
		return;
	}
	save=head;
	
	while(save->data!=n)
	{
		prev=save;
		save=save->next;
		if(save==NULL)
			break;
	}
	if(save!=NULL)
	{
		new1->next=prev->next;
		prev->next=new1;
	}
	else
		printf("\nNode not found");
}

//delete a node at begining
int delete_at_begin()
{
	int x;
	struct node *save;
	if(head==NULL)
	{
		printf("\nLinked list empty");
		return(-1);
	}
	save=head;
	x=head->data;
	head=head->next;
	free(save);
	return(x);
}

//delete a node at End
int delete_at_end()
{
	int x;
	struct node *save, *last;
	if(head==NULL)
	{
		printf("\nLinked list empty"); 
		return(-1);
	}
	if(head->next==NULL)
	{
		x=head->data;
		free(head);
		head=NULL;
		return(x);
	}
	save=head;
	while(save->next->next!=NULL)
	{  
		save=save->next;
	}
	x=save->next->data;
	free(save->next);
	save->next=NULL;
	return(x);
}

//delete a node after specific value
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
	while (save->data != n)
	{  
		save=save->next;
		if(save==NULL)
		break; 
	}  
	if(save !=NULL && save->next!=NULL)
	{
		del=save->next;
		x=save->next->data;
		save->next=save->next->next;
		free(del);
		return (x);
	}
	if(save->next==NULL)
	{
		printf("No node after given Node");
		return(-1);
	}	
	if(save==NULL)
	{
		printf("\nGiven Node not Found");
		return(-1);
    }
}

//Deletion at specified Position
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
		x=head->data;
		del=head;
		head=head->next;
		free(del);
		return (x) ;
	}
	save=head;
	i=1;
	printf("\n inside function");
	while( i!=pos-1)
	{
		save=save->next;
		++i;
	}
	printf("\nposition =%d",i);
	del=save->next;
	x=save->next->data;
	if(save->next->next==NULL) // last node to be deleted
	{
		save->next=NULL;
	}
	else
	{
		save->next=save->next->next;
	}
	free(del);
	return (x);
}

//Delete at element x
int delete_specific_value_node(int n)
{
	int x;
	struct node *save,*del, *prev;
	if(head==NULL)
	{
		printf("\nLinked list empty"); 
		return(-1);
	}
	if(head->data ==n)
	{
		x=head->data;
		del=head;
		head=head->next;
		free(del);
		return (x) ;
	}
	save=head;
	while( save->data!=n )
	{
		prev=save;
		save=save->next;
		if(save==NULL)
		break;
	}
	if(save !=NULL)
	{
		x=save->data;
		prev->next=save->next;
		free(save);
		return (x);
	}
	else
	{
		printf("\nNo node after given Node");
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
		while(save != NULL)
		{
			printf("\n %d is to be deleted next", delete_at_begin());
			save=head;
		}	
	}
}

//search a list
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
		if(save==NULL)
			break;
	}
	if(save!=NULL)
	{
		printf("\nKey found");
	}
	else
	{
		printf("\nKey not found");
	}
}

//reverse a list
struct node *reverse()
{
	struct node *prev, *curr;
	prev = NULL;
	curr = head;
	while (curr != NULL)
	{
		head = head-> next;
		curr-> next = prev;
		prev = curr;
		curr = head;
	}
	return(prev);
}

//sort a list
struct node *sort()
{
	struct node *ptr1, *ptr2;
	int temp;
	ptr1 = head;
	while(ptr1 -> next != NULL)
	{
		ptr2 = ptr1 -> next;
		while(ptr2 != NULL)
		{
			if(ptr1 -> data > ptr2 -> data)
			{
				temp = ptr1 -> data;
				ptr1 -> data = ptr2 -> data;
				ptr2 -> data = temp;
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return(head);
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
	system("cls");
	do
	{
		printf("\n============================");
		printf("\nEnter the Choice: ");
		printf("\n1:Insertion at begin");
		printf("\n2:Insertion at end");
		printf("\n3:Insertion at specified node");
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
		printf("\n14:Reverse a list");
		printf("\n15:Sort a List");
		printf("\n16:Copy a list");
		printf("\n17:Count Number of node in list");
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
						printf("\nDeleted element: %d",x);
					break;
			case 10:
					printf("\nEnter the position of node to be deleted: ");
					scanf("%d",&pos);
					x=delete_a_specific_pos_node(pos);
					if(x!=-1)
						printf("\nDeleted element: %d",x);
					break;
			case 11:
					printf("\nEnter the value of node to be Deleted: ");
					scanf("%d",&pos);
					x=delete_specific_value_node(pos);
					if(x!=-1)
						printf("\nDeleted element: %d",x);
					break;
			case 12: 
					delete_list();
				 	break; 
	    	case 13:
					printf("\nEnter the value to be search: ");
					scanf("%d",&x);
					search(x);
					break;
	    	case 14:
					head=reverse();
					printf("\n reverse list");
					display(head);
					break;
			case 15:
					p=sort();
					printf("\n Sorting of list");
					display(p);
					break;  
			case 16:
					p=copy();
					printf("\n copy of list");
					display(p);
					break; 
			case 17:
					x=count_node();
					printf("\nNo. of node in list=%d",x);
					break; 	  
			default:
		    		break;
	  	}
  	} while(ch!=0);
	return(0);       
}