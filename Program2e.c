//Program 2e = Write a program to convert Infix expression to Prefix expression using Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char operator) 
{
    switch (operator) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int isOperator(char ch) 
{
    return (ch == '+' ||  ch == '-' ||  ch == '*' || ch == '/' ||  ch == '^' || ch == '%');
}

void reverse(char *infix) 
{
    int size = strlen(infix);
    int j = size - 1, i = 0; 
    char temp[size];

    temp[size] = '\0';

    while (i < size) 
    {
        temp[j] = infix[i];
        j--;
        i++;
    }
    strcpy(infix, temp);
}

void brackets(char *infix) 
{
    int len = strlen(infix);
    for (int i = 0; i < len; i++) 
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
}

char *infixToPostfix(char *infix) 
{
    int i, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 1));

    for (i = 0; i < len; i++) 
    {
        if (infix[i] == ' ' || infix[i] == '\t')
        {
            continue;
        }
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')') 
        {
            while (top > -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top > -1 && stack[top] != '(')
            {
                return "Invalid Expression";
            }
            else
            {
                pop();
            }
        } 
        else if (precedence(stack[top]) >= precedence(infix[i])) 
        {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]) && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        } 
        else 
        {
            push(infix[i]);
        }
    }

    while (top > -1) 
    {
        if (stack[top] == '(')
        {
            return "Invalid Expression";
        }
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
    return postfix;
}

char *infixToPrefix(char *infix) 
{
    reverse(infix);
    brackets(infix);
    char *postfix = infixToPostfix(infix);
    reverse(postfix);
    return postfix;
}

int main() 
{
    char infix[MAX], *prefix;
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';

    prefix = infixToPrefix(infix);
    printf("Prefix expression: %s\n", prefix);
    free(prefix);
    return 0;
}
