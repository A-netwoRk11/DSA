#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

// Queue structure
struct Queue
{
    int items[MAX_SIZE];
    int front, rear;
};

// Circular Queue structure
struct CircularQueue
{
    int items[MAX_SIZE];
    int front, rear;
};

// Double-Ended Queue (Deque) structure
struct Deque
{
    int items[MAX_SIZE];
    int front, rear;
};

void initQueue(struct Queue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

void initCircularQueue(struct CircularQueue* cQueue)
{
    cQueue->front = -1;
    cQueue->rear = -1;
}

void initDeque(struct Deque* deque)
{
    deque->front = -1;
    deque->rear = -1;
}

int isFull(struct Queue* queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue* Queue)
{
    return (Queue->front == -1 && Queue->rear == -1);
}

int isCircularQueueFull(struct CircularQueue* cQueue)
{
    return ((cQueue->rear + 1) % MAX_SIZE == cQueue->front);
}

int isCircularQueueEmpty(struct CircularQueue* cQueue)
{
    return (cQueue->front == -1 && cQueue->rear == -1);
}

int isDequeFull(struct Deque* deque)
{
    return ((deque->rear == MAX_SIZE - 1 && deque->front == 0) || (deque->front == (deque->rear + 1) % MAX_SIZE));
}

int isDequeEmpty(struct Deque* deque)
{
    return (deque->front == -1);
}

void insert(struct Queue* queue, int value)
{
    if (isFull(queue))
    {
        printf("\nQueue is full. Cannot insert.");
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = queue->rear = 0;
        } 
        else
        {
            queue->rear++;
        }
        queue->items[queue->rear] = value;
    }
}

int delete(struct Queue* queue)
{
    int deletedItem;
    if (isEmpty(queue))
    {
        printf("\nQueue is empty. Cannot delete.");
        return -1;
    }
    else
    {
        deletedItem = queue->items[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front++;
        }
        return deletedItem;
    }
}

void display(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

void insertCircular(struct CircularQueue* cQueue, int value)
{
    if (isCircularQueueFull(cQueue))
    {
        printf("\nCircular Queue is full. Cannot insert.");
    }
    else
    {
        if (isCircularQueueEmpty(cQueue))
        {
            cQueue->front = cQueue->rear = 0;
        }
        else
        {
            cQueue->rear = (cQueue->rear + 1) % MAX_SIZE;
        }
        cQueue->items[cQueue->rear] = value;
    }
}

int deleteCircular(struct CircularQueue* cQueue)
{
    int deletedItem;
    if (isCircularQueueEmpty(cQueue))
    {
        printf("\nCircular Queue is empty. Cannot delete.");
        return -1;
    }
    else
    {
        deletedItem = cQueue->items[cQueue->front];
        if (cQueue->front == cQueue->rear)
        {
            cQueue->front = cQueue->rear = -1;
        }
        else
        {
            cQueue->front = (cQueue->front + 1) % MAX_SIZE;
        }
        return deletedItem;
    }
}

void displayCircular(struct CircularQueue* cQueue)
{
    if (isCircularQueueEmpty(cQueue))
    {
        printf("\nCircular Queue is empty.");
    }
    else
    {
        printf("Circular Queue elements: ");
        int i = cQueue->front;
        do
        {
            printf("%d ", cQueue->items[i]);
            i = (i + 1) % MAX_SIZE;
        }while (i != (cQueue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

void insertDequeFront(struct Deque* deque, int value)
{
    if (isDequeFull(deque))
    {
        printf("\nDeque is full. Cannot insert at front.");
    }
    else
    {
        if (isDequeEmpty(deque))
        {
            deque->front = deque->rear = 0;
        }
        else if (deque->front == 0)
        {
            deque->front = MAX_SIZE - 1;
        }
        else
        {
            deque->front--;
        }
        deque->items[deque->front] = value;
    }
}

void insertDequeRear(struct Deque* deque, int value)
{
    if (isDequeFull(deque))
    {
        printf("\nDeque is full. Cannot insert at rear.");
    }
    else
    {
        if (isDequeEmpty(deque))
        {
            deque->front = deque->rear = 0;
        }
        else if (deque->rear == MAX_SIZE - 1)
        {
            deque->rear = 0;
        }
        else
        {
            deque->rear++;
        }
        deque->items[deque->rear] = value;
    }
}

int deleteDequeFront(struct Deque* deque)
{
    int deletedItem;
    if (isDequeEmpty(deque))
    {
        printf("\nDeque is empty. Cannot delete from front.");
        return -1;
    }
    else
    {
        deletedItem = deque->items[deque->front];
        if (deque->front == deque->rear)
        {
            deque->front = deque->rear = -1;
        }
        else if (deque->front == MAX_SIZE - 1)
        {
            deque->front = 0;
        }
        else
        {
            deque->front++;
        }
        return deletedItem;
    }
}

int deleteDequeRear(struct Deque* deque)
{
    int deletedItem;
    if (isDequeEmpty(deque))
    {
        printf("\nDeque is empty. Cannot delete from rear.");
        return -1;
    }
    else
    {
        deletedItem = deque->items[deque->rear];
        if (deque->front == deque->rear)
        {
            deque->front = deque->rear = -1;
        }
        else if (deque->rear == 0)
        {
            deque->rear = MAX_SIZE - 1;
        }
        else
        {
            deque->rear--;
        }
        return deletedItem;
    }
}

void displayDeque(struct Deque* deque)
{
    if (isDequeEmpty(deque))
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Deque elements: ");
        if (deque->front <= deque->rear)
        {
            for (int i = deque->front; i <= deque->rear; i++)
            {
                printf("%d ", deque->items[i]);
            }
        }
        else
        {
            for (int i = deque->front; i < MAX_SIZE; i++)
            {
                printf("%d ", deque->items[i]);
            }
            for (int i = 0; i <= deque->rear; i++)
            {
                printf("%d ", deque->items[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Queue queue;
    struct CircularQueue cQueue;
    struct Deque deque;

    initQueue(&queue);
    initCircularQueue(&cQueue);
    initDeque(&deque);

    int choice, value;
    while (1)
    {
        printf("\n-------------------------------------\n");
        printf("\n1. Queue Operations");
        printf("\n2. Circular Queue Operations");
        printf("\n3. Double-Ended Queue (Deque) Operations");
        printf("\n4. Exit");
        printf("\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nQueue Operations:");
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\n4. Back to Main Menu");
                printf("\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        printf("\n");
                        printf("Enter the value to insert: ");
                        scanf("%d", &value);
                        insert(&queue, value);
                        break;
                    case 2:
                        value = delete(&queue);
                        if (value != -1)
                        {
                            printf("\nDeleted item: %d", value);
                        }
                        break;
                    case 3:
                        display(&queue);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nInvalid choice. Please try again.");
                }
                break;

            case 2:
                printf("\nCircular Queue Operations:");
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\n4. Back to Main Menu");
                printf("\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        printf("\n");
                        printf("Enter the value to insert: ");
                        scanf("%d", &value);
                        insertCircular(&cQueue, value);
                        break;
                    case 2:
                        value = deleteCircular(&cQueue);
                        if (value != -1) {
                            printf("\nDeleted item: %d", value);
                        }
                        break;
                    case 3:
                        displayCircular(&cQueue);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nInvalid choice. Please try again.");
                }
                break;

            case 3:
                printf("\nDouble-Ended Queue (Deque) Operations: ");
                printf("\n1. Insert at Front");
                printf("\n2. Insert at Rear");
                printf("\n3. Delete from Front");
                printf("\n4. Delete from Rear");
                printf("\n5. Display");
                printf("\n6. Back to Main Menu");
                printf("\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        printf("\n");
                        printf("Enter the value to insert at the front: ");
                        scanf("%d", &value);
                        insertDequeFront(&deque, value);
                        break;
                    case 2:
                        printf("\n");
                        printf("Enter the value to insert at the rear: ");
                        scanf("%d", &value);
                        insertDequeRear(&deque, value);
                        break;
                    case 3:
                        value = deleteDequeFront(&deque);
                        if (value != -1)
                        {
                            printf("\nDeleted item from the front: %d", value);
                        }
                        break;
                    case 4:
                        value = deleteDequeRear(&deque);
                        if (value != -1)
                        {
                            printf("\nDeleted item from the rear: %d", value);
                        }
                        break;
                    case 5:
                        displayDeque(&deque);
                        break;
                    case 6:
                        break;
                    default:
                        printf("\nInvalid choice. Please try again.");
                }
                break;

            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}