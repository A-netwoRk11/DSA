//Program2b = Write a program to reverse a string using Stack
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20
int top = -1;
char stack[MAX];

void push(char item)
{
	if(top==(MAX-1))
	{
		printf("\nStack Overflow\n");
		return;
	}
	stack[++top]=item;
}

char pop()
{
	if(top==-1)
	{
		printf("\nStack Underflow\n");
		return(-1);
	}
	return stack[top--];
}

void reverse(char str[])
{
	int i;
	//Push string on the stack.
	for(i=0; i<strlen(str); i++)
	{
		push(str[i]);
	}
	//Pop character from the stack and store in string str.
	for(i=0; i<strlen(str); i++)
	{
		str[i]=pop();
	}
}

int main()
{
	char str[20];
	printf("\nEnter the string: ");
	gets(str);
	reverse(str);
	printf("\nReversed string is : ");
	puts(str);
	return 0;
}
