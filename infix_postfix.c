#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    if(top == (MAX - 1)){
        printf("Stack is Full\n");
        return;
    }else{
        top = top + 1;
        stack[top] = x;
    }
}

// Pop function
char pop() {
    int data;
    if(top==-1){
        printf("\nStack is empty\n");
        return;
    }
    else{
        data = stack[top];
        top = top - 1;
    }
    return data;
}

// Precedence function
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return -1;
}

int main() {
    char infix[MAX], *p, x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    p = infix;

    printf("Postfix expression: ");

    while (*p != '\0') {
        if (isalnum(*p)) {
            // If operand → directly print
            printf("%c", *p);
        }
        else if (*p == '(') {
            push(*p);
        }
        else if (*p == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        else {
            // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(*p)) {
                printf("%c", pop());
            }
            push(*p);
        }
        p++;
    }

    // Pop remaining operators
    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
