#include<stdio.h>

void display(int *a);

void main(){

    int arr[] = {10,20,30,40,50};
    int i, n = sizeof(arr)/sizeof(arr[0]);

    for(i=0; i<n;i++)
        display(&arr[i]);
}

void display(int *ptr){
    printf("\n%u",ptr);
    printf("\n%d\n", *ptr);
}