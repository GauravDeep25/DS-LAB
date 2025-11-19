#include<stdio.h>

void display(int *a, int n);

void main(){

    int arr[] = {10,20,30,40,50};
    int i, n = sizeof(arr)/sizeof(arr[0]);

    display(arr, n);
}

void display(int *ptr, int n){
    int i;
    for(i=0; i<n; i++){
        printf("\n%d\n", *ptr);
    }
}