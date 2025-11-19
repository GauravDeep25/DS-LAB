#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;

struct node* insert_end(struct node *start) {
    struct node *temp, *p;
    int val;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &val);

    temp->data = val;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        p = start;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }

    printf("Node inserted.\n");
    return start;
}

struct node* concatenate(struct node *start1, struct node *start2) {
    struct node *p;
    if (start1 == NULL)
        return start2;
    if (start2 == NULL)
        return start1;

    p = start1;
    while (p->next != NULL)
        p = p->next;
    p->next = start2;

    return start1;
}

void display(struct node *start) {
    struct node *p = start;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int choice;

    printf("1. Insert in List 1\n2. Insert in List 2\n3. Concatenate Lists & display\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start1 = insert_end(start1);  break;

            case 2:start2 = insert_end(start2); break;

            case 3:start1 = concatenate(start1, start2);
                printf("\nAfter Concatenation:\n");
                display(start1); break;

            case 4: exit(0);

            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
