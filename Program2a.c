//Program2a = Write a program to create a Stack and perform the following operations:Push, Pop, Peep, Change and Display
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100
int TOP = -1;
char stack[MAX_SIZE];

void push(char value)
{
	if(TOP==(MAX_SIZE-1))
	{
		printf("\nStack is full-Overflow");
		return;
	}
	else 
	{
		stack[++TOP]=value;
	}
}

int pop()
{
	if(TOP==-1)
	{
		printf("\nStack is empty-Underflow\n");
		return -1; 
	}
	else
	{
		return stack[TOP--];
	}
}

int peep()
{
	if(TOP==-1)
	{
		printf("\nStack is empty-Underflow.");
		return -1;
	}
	else
	{
		return(stack[TOP]);
	}
}

void display()
{
	int i;
	if(TOP==-1)
	{
		printf("\nStack is Underflow.");
		return;
	}
	else
	{
		printf("\nStack element are as below: ");
		for(i=TOP; i>=0; i--)
		{
			printf("%d", stack[i]);
		}
	}
}

void change()
{
    int i,j;
    printf("\nEnter position for change: ");
    scanf("%d", i);
    printf("\nEnter the number for change:");
    scanf("%d", &j);

    if(TOP-i<=-1)
    {
        printf("\nStack is Overflow");
    }
    else
    {
        stack[TOP-i]=j;
        
        printf("\nChanged Successfully..!!");
    
    }
}

int main()
{
	int choice,data;
	do
	{
		printf("\n1: push data");
		printf("\n2: pop data");
		printf("\n3: peep data");
		printf("\n4: disply data");
		printf("\n5: change data");
		printf("\n0: exit");
		printf("\n----------------------");
		printf("\nEnter choice= ", choice);
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter data into stack= ", data);
				scanf("%d", &data);
				push(data);
                printf("\n");
				break;
			case 2:
				data=pop();
				if(data!=-1)
				{
					printf("%d is pop", data);
				}
				printf("\n");
                break;
			case 3:
				data=peep();
				if(data!=-1)
				{
					printf("%d is peep", data);
				}
                printf("\n");
				break;
			case 4:
				display();
                printf("\n");
				break;
			case 5:
				change();
				printf("\nEnter position for change: ");
    			scanf("%d", data);
    			printf("\nEnter the number for change:");
    			scanf("%d", &data);
				change(data);
				printf("\n");
				break;
			default:
				printf("Enter valid choice.\n");
		}
	}while(choice!=0);
	return 0;
}
