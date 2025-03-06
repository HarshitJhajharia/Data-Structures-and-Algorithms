#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 30

struct stack
{
    char a[max];
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

void push(struct stack *s, char element)
{
    if(s->top == max-1)
    {
        printf("Stack full");
        return;
    }
    s->top++;
    s->a[s->top] = element;
}

char pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top--];
}

char peek(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top];
}

int ismatching(char opening, char closing)
{
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

int bracket(char *b)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    initialize(s);
    char j=0;
    for(int i=0; b[i] !='\0';i++)
    {
        char c = b[i];
        if(c == '(' || c == '{' || c == '[')
        {
            push(s, c);
        }
        else if(c == ')' || c == '}' || c == ']')
        {
            if(IsEmpty(s))
            {
                printf("No closing bracket found");
                return 0;
            }
            char top = pop(s);
            if(!ismatching(top, c))
            {
                printf("No matching bracket found");
                return 0;
            }
        }
    }
    return IsEmpty(s);
}

int main() {
    char expression[max];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (bracket(expression)) {
        printf("The expression is balanced.\n");
    } 
    else {
        printf("The expression is not balanced.\n");
    }
return 0;
}