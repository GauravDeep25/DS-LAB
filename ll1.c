#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* start = NULL;

void insert_start(){
    struct node *p;
    struct node *temp;
    int info;
    printf("\nEnter the data part: ");
    scanf("%d", &info);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->link = NULL;
    if(start == NULL){
        start = temp;
    }else{
        temp->link = start;
        start = temp;
    }
}

void insert_end(){
    struct node *p;
    struct node *temp;
    int info;
    printf("\nEnter the data part: ");
    scanf("%d", &info);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->link = NULL;
    if(start == NULL){
        start = temp;
    } else {
        p = start;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
}

void insert_mid(){
    struct node *p;
    struct node *temp;
    int info, key_node;
    printf("\nEnter the data part: ");
    scanf("%d", &info);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->link = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        printf("\nAfter which node?\n");
        scanf("%d", &key_node);
        p = start;
        while(p != NULL && p->data != key_node){
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
}

void delete_end(){
    struct node *p, *temp;
    if(start == NULL){
        printf("\nThe Linked List is empty.");
        return;
    }
    if(start->link == NULL){
        free(start);
        start = NULL;
        printf("\nNode deleted from end.");
    } else {
        p = start;
        while(p->link->link != NULL){
            p = p->link;
        }
        temp = p->link;
        p->link = NULL;
        free(temp);
        printf("\nNode deleted from end.");
    }
}

void display(){
    struct node *p;
    if(start == NULL){
        printf("\nThe Linked List is empty.");
    }else {
        p = start;
        printf("\nThe Linked List elements are: ");
        while(p != NULL){
            printf("%d ", p->data);
            p = p->link;
        }
    }
}

void main(){
    int choice;
    printf("\n1. Insert at start\n2. Insert at end\n3. Insert at middle\n4. Delete from end\n5. Display\n6. Exit");
    while(1){
        printf("\nEnter your choice: ");

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
                delete_end();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
}