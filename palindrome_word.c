#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

struct stack 
{
    char a[max];
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

char pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top--];
}

char peep(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack empty");
        return -1;
    }
    return s->a[s->top];
}

void palindrome(struct stack *s, char *word)
{
    int i;
    for(i=0; word[i] != '\0' ;i++)
    {
        push(s, word[i]);
    }
    char y[50];
    int j=0;
    while(s->top != -1)
    {
        y[j]=pop(s);
        j++;
    }
    y[j] = '\0';
    if(strcmp(word, y) == 0)
    {
        printf("Word is a palindrome");
        return;
    }
    printf("Word is not a palindrome");
}

int main() {
    char word[max];
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    initialize(s);
    printf("Enter a word: ");
    scanf("%s", word);

    palindrome(s, word);
return 0;
}
