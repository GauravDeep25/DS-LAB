#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* start = NULL;
void insert_start(){
    struct node* temp;
    int info;
    printf("\nEnter the data part: ");
    scanf("%d", &info);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL){
        start = temp;
    } else {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}
void insert_end(){
    struct node* p;
    struct node* temp;
    int info;
    printf("\nEnter the data part: ");
    scanf("%d", &info);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL){
        start = temp;
    } else {
        p = start;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}
void insert_mid(){
    struct node* p;
    struct node* temp;
    int info, key_node;
    printf("\nEnter the data part: ");
    scanf("%d", &info);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL){
        start = temp;
    } else {
        printf("\nEnter the key node after which to insert: ");
        scanf("%d", &key_node);
        p = start;
        while(p != NULL && p->data != key_node){
            p = p->next;
        }
        if(p == NULL){
            p->next = temp;
            temp->prev = p;
            return;
        }
        else{
            temp->prev = p;
            temp->next = p->next;
            p->next->prev = temp;
            p->next = temp;
        }
    }
}
void delete_end(){
    struct node* p;
    if(start == NULL){
        printf("\nThe Doubly Linked List is empty.");
        return;
    } else {
        p = start;
        while(p->next != NULL){
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
        printf("\nNode deleted from end.");
    }
}
void delete_start(){
    struct node* temp;
    if(start == NULL){
        printf("\nThe Doubly Linked List is empty.");
        return;
    } else {
        temp = start;
        start = start->next;
        if(start != NULL){
            start->prev = NULL;
        }
        free(temp);
        printf("\nNode deleted from start.");
    }
}

void delete_mid(){
    struct node* p;
    int key_node;
    if(start == NULL){
        printf("\nThe Doubly Linked List is empty.");
        return;
    } else {
        printf("\nEnter the key node to delete: ");
        scanf("%d", &key_node);
        p = start;
        while(p != NULL && p->data != key_node){
            p = p->next;
        }
        if(p == NULL){
            printf("\nKey node not found.");
            return;
        }
        if(p->prev != NULL){
            p->prev->next = p->next;
        } else {
            start = p->next;
        }
        if(p->next != NULL){
            p->next->prev = p->prev;
        }
        free(p);
        printf("\nNode with data %d deleted.", key_node);
    }
}
void display(){
    struct node* p;
    if(start == NULL){
        printf("\nThe Doubly Linked List is empty.");
        return;
    }
    p = start;
    printf("\nDoubly Linked List elements: ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}
void main(){
    int choice;
    while(1){
        printf("\n1. Insert at Start\n2. Insert at End\n3. Insert at Middle\n4. Delete from Start\n5. Delete from End\n6. Delete from Middle\n7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert_start();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_mid();
                break;
            case 4:
                delete_start();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_mid();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
}