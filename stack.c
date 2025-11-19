#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int item){
    if(top == (SIZE - 1)){
        printf("Stack is Full\n");
        return;
    }else{
        top = top+1;
        stack[top] = item;
    }
}

int pop(){
    int data;
    if(top==-1){
        printf("\nStack is empty\n");
        return;
    }
    else{
        data = stack[top];
        top = top-1;
    }
    return data;
}

void display(){
    int i;
    if(top==-1){
        printf("\nStack is empty\n");
        return;
    }
    else{
        for(i=0;i<=top;i++){
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

void menu(){
    printf("Enter the number to perform the specific operation:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
}

int main(){
    int i,data,item;
    do{
        menu();
        scanf("%d",&i);

        switch(i){
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                data = pop();
                printf("Popped item is: %d\n",data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input\n");
        }
    }while(1);
}
