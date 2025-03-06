#include <stdio.h>
#include <stdlib.h>

#define N 100

struct stack {
    int data[N];
    int top;
};

void initStack(struct stack *s) {
    s->top = -1;
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == N - 1;
}

void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow \n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty \n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int evaluatePostfix(char *postfix) {
    struct stack s;
    initStack(&s);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isDigit(c)) {
            push(&s, c - '0'); 
        } 
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            
            switch (c) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    push(&s, val1 / val2);
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
              } 
          } 
    }
 return pop(&s);
}

int main() {
    char postfix[N];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d \n", result);

    return 0;
}

