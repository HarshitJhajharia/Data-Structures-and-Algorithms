#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *next;
    int data;
};

struct queue 
{
    struct Node *front, *rear;
};

struct queue *initialize()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct queue *q)
{
    return(q->front == NULL);
}

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(struct queue *q, int new_data)
{
    struct Node *new_node = createnode(new_data);
    if(q->rear == NULL)
    {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

void dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        return;
    }
    struct Node *temp = q->front;
    printf("Dequeued element is: %d\n",temp->data);
    q->front = q->front->next;
    free(temp);
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
}

void display(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue empty\n");
        return;
    }
    struct Node *temp = (q->front);
    printf("\nQueue is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void getfront(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }
    printf("The frontmost element of the queue is %d\n",q->front->data);
}

void getrear(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }
    printf("The rearmost element of the queue is %d\n",q->rear->data);
}

void freequeue(struct queue *q)
{
    while(!isEmpty(q))
    {
        dequeue(q);
    }
    free(q);
}

int main()
{
    struct queue *q = initialize();
    int ch, data;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Get Front Element\n5.Get Rear Element\n6.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter data: ");
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
            getfront(q);
            break;
            case 5:
            getrear(q);
            break;
            case 6:
            freequeue(q);
            printf("\nExiting...");
            exit(0);
            break;
        }
    }
    return 0;
}