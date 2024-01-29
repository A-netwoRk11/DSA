//Program2c = Write a program to check the expression for valid usage of parenthesis.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
char stack[MAX_SIZE];
int top=-1;

void push(char data)
{
    if(top==MAX_SIZE-1)
    {
        printf("\nOverflow..!");
        return;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("\nEmpty stack.");
        return -1;
    }
    return(stack[top-1]);
}

int is_matching_pair(char char1, char char2)
{
    if(char1=='(' && char2==')')
    {
        return 1;
    }
    else if(char1=='[' && char2==']')
    {
        return 1;
    }
    else if(char1=='{' && char2=='}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[MAX_SIZE];
    int i;
    printf("Input an expression in parantheses: ");
    gets(exp);
    for(i=0; i<strlen(exp); i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(!is_matching_pair(pop(),exp[i]))
            {
                printf("\nThe expression is not balanced.");
                return(0);
            }
        }
    }
    if(top==-1)
    {
        printf("\nThe expression is balanced.");
    }
    else
    {
        printf("\nThe expression is not balanced.");
    }
    return 0;
}
