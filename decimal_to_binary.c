#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 30

struct stack
{
    int a[max];
    int top;
};

void initialize(struct stack *s)
{
    s->top = -1;
}

int IsEmpty(struct stack *s)
{
    return s->top == -1;
}

int IsFull(struct stack *s)
{
    return s->top == max-1;
}

void push(struct stack *s, int element)
{
    if(s->top == max-1)
    {
        printf("Stack full");
        return;
    }
    s->top++;
    s->a[s->top] = element;
}

int pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top--];
}

int peek(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top];
}

int decimaltobinary(struct stack *s, int decimal)
{
    if(decimal == 0)
    {
        printf("The binary equivalent is 0");
        return 0;
    }
    while(decimal>0)
    {
        push(s, decimal%2);
        decimal=decimal/2;
    }
    printf("Binary equivalent: ");
    while(!IsEmpty(s))
    {
        printf("%d",pop(s));
    }
    printf("\n");
}

int main() 
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    initialize(s);
	int decimal;
	printf("Enter a decimal number: ");
        scanf("%d", &decimal);

        decimaltobinary(s, decimal);

return 0;
}