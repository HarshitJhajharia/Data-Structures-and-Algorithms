#include<stdio.h>
#include<stdlib.h>
#define max 100

struct stack 
{
    int a[max];
    int top;
};

void initialize(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int element)
{
    if((s->top) == max-1 )
    {
        printf("Stack full");
        return;
    }
    s->top++;
    s->a[s->top]=element;
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

int peep(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top];
}

int main()
{
    struct stack *s;
    initialize(s);

    int choice;
    while(1)
    {
        printf("\n1.Insert element(push):\n");
        printf("\n2.Delete topmost element(pop):\n");
        printf("\n3.Show topmost element:\n");
        printf("\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case(1): {
            int element;
            printf("Enter element: ");
            scanf("%d",&element);
            push(s, element);
            break;
            }

            case(2): {
            int delete;
            delete = pop(s);
            printf("%d was deleted from the stack",delete);
            break;
            }

            case(3): {
            int topmost;
            topmost = peep(s);
            printf("Topmost element of the stack: %d",topmost);
            break;
            }

            case(4): {
            printf("Exiting....\n");
            return 0;
            }

            default: {
            printf("Enter valid choice");
            }
        }
    }
}