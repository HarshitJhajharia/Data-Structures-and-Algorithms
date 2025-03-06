#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

struct Stack {
    int top;
    char arr[max];
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

void push(struct Stack* s, char ch) {
    if (s->top == max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = ch;
}

char pop(struct Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->arr[s->top--];
}

char peek(struct Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->arr[s->top];
}

int precedence(char ch)
{
    switch(ch)
    {
        case'+':
        case'-':
        return 1;
        case'*':
        case'%':
        case'/':
        return 2;
        case'^':
        return 3;
        default:
        return 0;
    }
}

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int isAlphanumeric(char c)
{
    return ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'));
}

void infixToPrefix(char* infix, char* prefix) {
    struct Stack stack;
    initStack(&stack);
    
    reverseString(infix);

    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    int k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        if (isAlphanumeric(infix[i])) {
            prefix[k++] = infix[i];
        } 
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } 
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                prefix[k++] = pop(&stack);
            }
            pop(&stack);
        } 
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                prefix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        prefix[k++] = pop(&stack);
    }
    
    prefix[k] = '\0';

    reverseString(prefix);
}

int main() {
    char infix[max], prefix[max];
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
