/*Program1a = Write a program to implement a student 
structure using dynamic memory allocation and 
perform following operations:
i) Create a student record
ii) Search a student record
iii) Update a student record
iv) Delete a student record
v) Display student records
vi) Sort Student records
vii) Merge Student records */
 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int rollno;
	char name[20];
	float marks;
}*first[20];

int i=0;

void insert()
{
	int j;
	
	first[i] = (struct student*)malloc(sizeof(struct student));
	
	printf("\nEnter roll number: ");
	scanf("%d", &first[i]->rollno);
	printf("Enter name: ");
	fflush(stdin);
	gets(first[i]->name);
	printf("Enter marks: ");
	scanf("%f", &first[i]->marks);
	
	++i;
};

void display()
{
	int j;
	
	printf("\n********** All Students Record ***********\n");
	printf("\nRollno\t|Name\t|Marks\n");
	for(j=0;j<i;j++)
	{
		printf("\n%d\t|%s\t|%f", first[j]->rollno,first[j]->name,first[j]->marks);
	}
};

void search()
{
	int j,no,found=-1;
	printf("Enter rollno you want to search= ");
	scanf("%d", &no);
	
	for(j=0;j<i;j++)
	{
		if(first[j]->rollno==no)
		{
			found=1;
			break;
		}
	}
	if(found==1)
	{
		printf("\nStudent found.");
	}
	else
	{
		printf("\nStudent not found.");
	}
};

void update()
{
	int j,h,no;
	printf("\nEnter rollno you want to update= ");
	scanf("%d", &no);
	
	for(j=0;j<i;j++)
	{
		if(first[j]->rollno==no)
		{
			printf("Enter the updated number");
			scanf("%d", &h);
			first[j]->rollno=h;
			return;
		}
	}
};

void delete()
{
	int j,k,no;
	printf("\nEnter rollno you want to delete= ");
	scanf("%d", &no);
	
	for(j=0;j<i;j++)
	{
		if(first[j]->rollno==no)
		{
			for(k=j;k<i;k++)
			{
				first[k]=first[k+1];
			}
			--i;
			printf("Record Deleted");
			return;
		}
	}
};

void sort()
{
	int r,a;
	struct student *m;
	
	for(r=0;r<i;r++)
	{
		for(a=r+1;a<i;a++)
		{
			if(first[r]->rollno>first[a]->rollno)
			{
				m=first[r];
				first[r]=first[a];
				first[a]=m;
			}
		}
	}
};

void main()
{
	int choice;
	do
	{
		printf("\n----------------------------------------");
		printf("\n1:insert a student record");
		printf("\n2:display a student record");
		printf("\n3:search a student record");
		printf("\n4:update a student record");
		printf("\n5:delete a student record");
		printf("\n6:sort a student record");
		printf("\n0:exit");
		printf("\n----------------------------------------");
		
		printf("\nEnter your choice= ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			       insert();
			       break;
			case 2:
				   display();
				   break;
			case 3:
				   search();
				   break;
			case 4:
				   update();
				   break;
			case 5:
				   delete();
				   break;
			case 6:
				   sort();
				   break;
			case 0:
				   exit;
				   break;
			default:
				   printf("\nYour entered choice is not found...!\n\nEnter new choice.");
				   break;
		}
	}while(choice!=0);

	getch();
}
