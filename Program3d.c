//practical 3.4 implementation of priority queue using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int size;

void enqueue(int pq[size][MAX],int front[size],int rear[size])
{
    printf("Enter the element to insert:\n");
    int temp;
    scanf("%d", &temp);
    printf("Enter the Priority between 0 to %d :\n", size-1);
    int p;
    scanf("%d", &p);
    if(p>size)
    {
    	printf("\n Invalid Priority");
    	printf("\nNO element inserted");
    	return;
	}
    if (front[p]==(rear[p]+1)%MAX)
    {
        printf("Overflow!\n");
        return;
    }
    if (rear[p] == -1&& front[p]==-1)
    {
        front[p] = 0;
        rear[p] = 0;
    }
    else
	{
        rear[p]=(rear[p]+1)%MAX;
    }
    pq[p][rear[p]] = temp;
}

int dequeue (int pq[size][MAX],int front[size],int rear[size])
{
	int data;
    for (int i = size-1; i>=0; i--)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (pq[i][j] != '-')
            {
                data=pq[i][j];
                if(front[i] == rear[i])
                {
    				front[i]=rear[i]=-1;
                }
 				else
                {
   					front[i]=(front[i]+1)%MAX;
                }
				pq[i][j]='-';
                return(data);
            }
        }
    }
    printf("\nUnderflow!");
    return(-1);
}


int peek (int pq[size][MAX],int front[size],int rear[size])
{
	int data;
    for (int i = size-1; i>=0; i--)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (pq[i][j] != '-')
            {
                data=pq[i][j];
                printf("\nItem deleted!");
                return(data);
            }
        }
    }
    printf("\nUnderflow!");
    return(-1);
}

void display(int pq[size][MAX],int front[size],int rear[size])
{
    printf("Displaying Queue:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (pq[i][j] == '-')
            {
                printf("_ ");
            }
            else
            {
                printf("%d ", pq[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int choice,n;
    printf("\nEnter Size of Priority:");
    scanf("%d",&size);
    int pq[size][MAX];
    int front[size];
    int rear[size];
    for(int i=0;i<size;i++)
    {
        front[i]=-1;
        rear[i]=-1;
        for(int j=0;j<5;j++)
        {
            pq[i][j]='-';
        }
    }
    do
    {
        printf("\n----Menu----\n");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Peek - Highest priority element");
        printf("\n4. Display Elements");
        printf("\n5. Exit");
        printf("\nEnter choice:");
        scanf(" %d", &choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                enqueue(pq,front,rear); 
                break;
            
            case 2:
                n=dequeue(pq,front,rear);
                if(n!=-1)
                    printf("\n%d deleted element",n);
                break;
            
            case 3:
                n=peek(pq,front,rear);
                if(n!=-1)
                    printf("\n%d higehst priorty element",n);
                break;

            case 4:
                display(pq,front,rear);	    
                break;
            
            default:
                printf("\nInvalid Choice") ;
                break;  
        } 
    }while(choice!=5);
    return(0);  
}