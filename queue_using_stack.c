#include <stdio.h>
#include <stdlib.h>

#define max 100

struct stack {
    int top;
    int arr[max];
};

void initStack(struct stack *s) {
    s->top = -1;
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == max - 1;
}

void push(struct stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Full\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

struct queue {
    struct stack *s1, *s2;
};

void initQueue(struct queue *q) {
    q->s1 = (struct stack*)malloc(sizeof(struct stack));
    q->s2 = (struct stack*)malloc(sizeof(struct stack));
    initStack(q->s1);
    initStack(q->s2);
}

void enqueue(struct queue *q, int data) {
    push(q->s1, data);
}

int dequeue(struct queue *q) {
    if (isEmpty(q->s1) && isEmpty(q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(q->s2)) {
        while (!isEmpty(q->s1)) {
            push(q->s2, pop(q->s1));
        }
    }
    return pop(q->s2);
}

int peekQueue(struct queue *q) {
    if (isEmpty(q->s1) && isEmpty(q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(q->s2)) {
        while (!isEmpty(q->s1)) {
            push(q->s2, pop(q->s1));
        }
    }
    return peek(q->s2);
}


int main() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    initQueue(q);
    
    int ch, data;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(q));
                break;
            case 3:
                printf("Front element: %d\n", peekQueue(q));
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }        
    }    
    return 0;
}
