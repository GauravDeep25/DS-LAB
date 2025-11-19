#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push() {
    struct node *temp;
    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = top;
    top = temp;

}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void display() {
    struct node *p;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    p = top;
    printf("Stack elements are: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int choice;

    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
