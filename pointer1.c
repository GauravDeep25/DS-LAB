#include<stdio.h>

void display(int *a);

void main(){

    int arr[] = {10,20,30,40,50};
    display(arr);
}

void display(int *ptr){
    printf("\n%u",ptr);
    printf("\n%d\n", *ptr);
}