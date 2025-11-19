#include <stdio.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == (MAX - 1)) {
        printf("Stack is Full\n");
        return;
    } else {
        top = top + 1;
        stack[top] = x;
    }
}

int pop() {
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

// // Function to calculate power (base^exponent) for integers
// int power(int base, int exponent) {
//     int result = 1;
//     if (exponent < 0) {
//         printf("Negative exponents not supported for integer calculation\n");
//         return 0;
//     }
//     for (int i = 0; i < exponent; i++) {
//         result *= base;
//     }
//     return result;
// }

int main() {
    char postfix[MAX];
    char *p;
    int num, n1, n2, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    p = postfix;

    while (*p != '\0') {
        if (isdigit(*p)) {
            num = *p - 48;
            push(num);
        } else {
            switch (*p) {
                case '+':
                    n1 = pop();
                    n2 = pop();
                    result = n2 + n1;
                    push(result);
                    break;
                case '-':
                    n1 = pop();
                    n2 = pop();
                    result = n2 - n1;
                    push(result);
                    break;
                case '*':
                    n1 = pop();
                    n2 = pop();
                    result = n2 * n1;
                    push(result);
                    break;
                case '/':
                    n1 = pop();
                    n2 = pop();
                    if (n1 == 0) {
                        printf("Division by zero error\n");
                        return 1;
                    }
                    result = n2 / n1;
                    push(result);
                    break;
                // case '^':
                //     n1 = pop();  // exponent
                //     n2 = pop();  // base
                //     result = power(n2, n1);
                //     push(result);
                //     break;
                default:
                    printf("Invalid character encountered: %c\n", *p);
                    return 1;
            }
        }
        p++; // move to next character
    }

    result = pop();
    printf("Result = %d\n", result);

    return 0;
}
