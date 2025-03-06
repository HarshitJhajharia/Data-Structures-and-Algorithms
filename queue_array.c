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
    if(q->rear == max-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if(q->front == -1 || q->front>q->rear)
    {
        return 1;
    }
    return 0;
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
        q->front++;
    }
    q->rear++;
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
    q->front++;
    if(q->front>q->rear)
    {
        q->front = q->rear = -1;
    }
    printf("Dequeued value: %d\n", dequeuedvalue);
}

void display(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is full");
    }
    printf("\nQueue is: ");
    for(int i = q->front; i<=q->rear;i++)
    {
        printf("%d",q->arr[i]);
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
            break;
        }
    }
    return 0;
}