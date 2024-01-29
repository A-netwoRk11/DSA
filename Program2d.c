//Program2d = Write a program to convert Infix expression to Postfix expression using Stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

#define MAX 100
char stack[MAX];
int top=-1;

int push(char item)
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow.");
        return top;
    }
    stack[++top]=item;
}

char pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    return stack[top--];
}

//Function to return precedence of operators
int precedence(char operator)
{
    switch(operator)
    {
        case'+':
        case'-':
            return 1;
        case'*':
        case'/':
        case'%':
            return 2;
        case'^':
            return 3;
        default:
            return -1;
    }
}

int isOperator(char ch)
{
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='%');
}

//function to convert infix expression to postfix expression
char*infixToPostfix(char*infix)
{
    int i,j = 0;
    int len = strlen(infix);
    char*postfix=(char*)malloc(sizeof(char)*(len+2));
    
    for(i=0; i<len; i++)
    {
        if(infix[i]==' ' || infix[i]=='\t')
        {
            continue;
        }
        //If the scanned character is operand add it to the postfix expression
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        //if the scanned character is '(' push it in the stack
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        /* if the scanned character is ')' pop the stack and add it to the output string until empty or '(' found*/
        else if(infix[i]==')')
        {
            while(top>-1 && stack[top]!='(')
            {
                postfix[j++]=pop();

                if((top>-1) && stack[top]!='(')
                {
                    return"Invalid Expression";
                }
                else
                {
                    pop();
                }
            }
        }
        
        /*If the scanned character is an operator, 
        pop the stack element until its precedence higher or equal than input operator or "(" not encontered in stack
        push it in the stack*/
        else if(isOperator(infix[i]))
        {
            if(infix[i]!='^')
            {
                while(top>-1 && precedence(stack[top])>=precedence(infix[i]) && stack[top]!='(')
                {
                    postfix[j++]=pop();
                }
                push(infix[i]);
            }
            
            //Pop all remaining elements from the stack
            while(top>1)
            {
                if(stack[top]=='(')
                {
                    return"Invalid Expression.";
                }
                postfix[i]='\0';
                return (postfix);
            }
        }        
    }
}

int main()
{
    char infix[MAX],*postfix;
    printf("\nEnter the infix expression: ");
    gets(infix);
    postfix=infixToPostfix(infix);
    printf("\nPostfix Expression: %s" ,postfix);
    free(postfix);
    return 0;
}
