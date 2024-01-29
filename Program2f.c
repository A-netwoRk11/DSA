//Program2f = Write a program to evaluate expression using stack.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int item) 
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() 
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int is_operator(char symbol)
{
    if (symbol == '+' ||  symbol == '-' ||  symbol == '*' ||  symbol == '/' ||  symbol=='%' || symbol=='^')
    { 
        return 1;  
    }
    return 0;
}

int evaluate_postfix(char* exp)
{
    int i = 0,num,top=-1;
    int op1, op2, result;
    while (exp[i] != '\0')
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            num = exp[i] - '0';
            push(num);
        }
        else if (is_operator(exp[i]))
        {
            op2 = pop();
            op1 = pop();
            switch(exp[i])
            {
                case '+': result = op1 + op2; 
                          break;
                case '-': result = op1 - op2; 
                          break;
                case '*': result = op1 * op2; 
                          break;
                case '/': result = op1 / op2; 
                          break;
                case '%': result = op1 % op2; 
                          break;
                case '^': result = op2 ^ op1; 
                          break;
                default : break;
            }
            push(result);
        }
        i++;
    }
    result = pop();
    return result;   
}

int evaluate_prefix(char* exp)
{
    int i=0,num,len=strlen(exp);
    int op1, op2, result,top=-1;
    for(i=len-1;i>=0;i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            num = exp[i] - '0';
            push(num);
        }
        else if (is_operator(exp[i]))
        {
            op1 = pop();
            op2 = pop();
            switch(exp[i])
            {
                case '+': result = op1 + op2; 
                          break;
                case '-': result = op1 - op2; 
                          break;
                case '*': result = op1 * op2; 
                          break;
                case '/': result = op1 / op2; 
                          break;
                case '%': result = op1 % op2; 
                          break;
                case '^': result = op2 ^ op1; 
                          break;
                default : break;
            }
            push(result);
        }
    }
    result = pop();
    return result;
}

int main() 
{
    char exp[MAX];
    int result,ch;
    do
    {
        printf("\n1. Evaluate Postfix expression: ");
        printf("\n2. Evaluate Prefix expression: ");
        printf("\n3. Exit");
        printf("\n Enter the Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("\nEnter the Postfix expression: ");
                fflush(stdin);
                gets(exp);
                result = evaluate_postfix(exp);
                printf("Result= %d\n", result);
                break;
            case 2:        
                printf("\nEnter the Prefix expression: ");
                fflush(stdin);
                scanf("%s",exp);
                result = evaluate_prefix(exp);
                printf("Result= %d\n", result);
                break;
            default: break;
        }
    }while(ch!=3);
    return 0;
}
