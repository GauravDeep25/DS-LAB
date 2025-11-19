#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_start() {
    struct node *temp, *p;
    int info;
    printf("\nEnter data: ");
    scanf("%d", &info);

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;

    if (start == NULL) {
        start = temp;
        temp->next = start;
    } else {
        p = start;
        while (p->next != start)
            p = p->next;
        temp->next = start;
        p->next = temp;
        start = temp;
    }
    printf("Node inserted at start.\n");
}

void insert_end() {
    struct node *temp, *p;
    int info;
    printf("\nEnter data: ");
    scanf("%d", &info);

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;

    if (start == NULL) {
        start = temp;
        temp->next = start;
    } else {
        p = start;
        while (p->next != start)
            p = p->next;
        p->next = temp;
        temp->next = start;
    }
    printf("Node inserted at end.\n");
}

void delete_start() {
    struct node *p, *temp;

    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = start;
    if (start->next == start) {
        start = NULL;
    } else {
        p = start;
        while (p->next != start)
            p = p->next;
        start = start->next;
        p->next = start;
    }

    free(temp);
}

void delete_end() {
    struct node *p, *q;

    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    p = start;
    if (start->next == start) {
        free(start);
        start = NULL;
        return;
    }

    while (p->next->next != start)
        p = p->next;

    q = p->next;
    p->next = start;
    free(q);
}

void display() {
    struct node *p;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nCircular Linked List elements: ");
    p = start;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start);
    printf("\n");
}

int main() {
    int choice;
        printf("\n1. Insert at Start\n2. Insert at End\n3. Delete from Start\n4. Delete from End\n5. Display\n6. Exit");
    while (1) {
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_start(); break;
            case 2: insert_end(); break;
            case 3: delete_start(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
