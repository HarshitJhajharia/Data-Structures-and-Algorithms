#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct stack
{
    struct Node *top;
};

struct stack *create()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = NULL;
    return s;
}

int IsEmpty(struct stack *s)
{
    if(s->top == NULL);
    {
        return 1;
    }
    return 0;
}

int IsFull(struct stack *s)
{
    return 0;
}

void push(struct stack *s, int data)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data = data;
    newnode->next = s->top;
    s->top=newnode;
}

void pop(struct stack *s)
{
    int x = IsEmpty(s);
    if(x==1)
    {
        printf("Stack empty");
        return;
    }
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
}

int Top(struct stack *s)
{
    int x = IsEmpty(s);
    if(x==1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->top->data;
}

void display(struct stack *s)
{
    int x = IsEmpty(s);
    if(x=1)
    {
        printf("Stack Empty");
        return;
    }
    struct Node *temp = s->top;
    printf("Stack elements are: \n");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct stack *s = create(); 
    while(1)
    {
        int ch;
        printf("1.Insert an element at the top of stack\n");
        printf("2.Delete the top element of the stack\n");
        printf("3.Check if Stack is full\n");
        printf("4.Check if Stack is empty\n");
        printf("5.Display the top element of the stack\n");
        printf("6.Display the elements of the stack\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
                int ele;
                printf("Enter element to insert\n");
                scanf("%d",&ele);
                push(s,ele);
                break;
            }
            case 2:
            {
                printf("Top element: %d\n", Top(s));
                pop(s);
                break;
            }
            case 3:
            {
                int x=IsFull(s);
                if(x==0)
                {
                 printf("stack is not full \n");
                 break;
                }
                printf("stack is full \n");
                break;
            }
            case 4:
            {
                int x=IsEmpty(s);
                if(x==1) 
                {
                 printf("stack is empty \n");
                 break;
                }
                printf("stack is not empty \n");
                break;
            }
            case 5:
            {
                printf("Top element: %d\n", Top(s));
                break;
            }
            case 6:
            {
                display(s);
                break;
            }
            case 7:
            {
                printf("Exiting...\n");
                return 0;
            }
            default:
            {
               printf("Invalid Input!\n");
               break;
            }  
        }
    }
    return 0;
}

