#include<stdio.h>
#include<stdlib.h>

#define max 50

struct queue
{
    int arr[max];
    int front, rear;
};
void initialize(struct queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(struct queue *q)
{
    return(((q->rear)+1)%max == q->front);
}

int isEmpty(struct queue *q)
{
    return(q->front == -1);
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear+1)%max;
    q->arr[q->rear] = data;
}

void dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }
    int dequeuedvalue = q->arr[q->front];
    printf("Dequeued value: %d\n", dequeuedvalue);
    if(q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front+1)%max;
    }
}

void display(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    printf("\nQueue is: ");
    int i = q->front;
    while(1)
    {
        printf("%d ",q->arr[i]);
        if(i == q->rear)
        break;
        i = (i+1)%max;
    }
    printf("\n");
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    initialize(q);
    int ch, data;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter element: ");
            scanf("%d",&data);
            enqueue(q, data);
            break;
            case 2:
            dequeue(q);
            break;
            case 3:
            display(q);
            break;
            case 4:
            exit(0);
            printf("\nExiting...");
            break;
        }
    }
    return 0;
}