#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct stack {
    char data[N];
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

void push(struct stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow \n");
        exit(1);
    }
    s->data[++(s->top)] = c;
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
	  printf("Stack is empty \n");
	  exit(1);
    }
    return s->data[(s->top)--];
}

char peek(struct stack *s) {
    if (isEmpty(s)) {
       return '\0';
    }
    return s->data[s->top];
}

int precedence(char c) {
    switch(c) {
    	case '+':
    	case '-':
    	 return 1;
    	case '*':
    	case '/':
    	 return 2;
    	case '^':
    	 return 3;
    	default:
    	 return 0;
   }
}

int isAlphanumeric(char c) {
	return ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'));
}

void infixToPostfix(char *infix, char *postfix) {
    struct stack s;
    initStack(&s);
    int i,j=0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (isAlphanumeric(c)) { 
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main () {
	char infix[N], postfix[N];
	
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	
        infixToPostfix(infix, postfix);
        printf("Postfix expression: %s \n", postfix);
        
        return 0;
}
        