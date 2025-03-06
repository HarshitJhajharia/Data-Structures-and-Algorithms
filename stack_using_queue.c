#include <stdio.h>
#include <stdlib.h>
#define max 100

struct queue {
    int arr[max];
    int front, rear;
};

void initQueue(struct queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct queue* q) {
    return (q->front == -1);
}

int isFull(struct queue *q)
{
    return q->rear == max -1;
}

void enqueue(struct queue* q, int data) {
    if (isFull(q)) {
        printf("Stack is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(struct queue * q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void push(struct queue * q, int data) {
    enqueue(q, data);
}

int pop(struct queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return -1;
    }
    int size = q->rear - q->front + 1;
    for (int i = 0; i < size - 1; i++) {
        enqueue(q, dequeue(q));
    }
    return dequeue(q);
}

int top(struct queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return -1;
    }
    int size = q->rear - q->front + 1;
    int lastElement;
    for (int i = 0; i < size; i++) {
        lastElement = dequeue(q);
        enqueue(q, lastElement);
    }
    return lastElement;
}

int main() {
    struct queue *stack = (struct queue*)malloc(sizeof(struct queue));
    initQueue(stack);
    int x, ch, data;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter element: ");
            scanf("%d",&data);
            push(stack, data);
            break;
            case 2:
            pop(stack);
            break;
            case 3:
            x = top(stack);
            printf("The top element of the stack is: %d\n",x);
            break;
            case 4:
            exit(0);
            break;
        }
    }
    return 0;
}