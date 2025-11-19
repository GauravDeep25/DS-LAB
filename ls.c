#include<stdio.h>

void linear_search(int arr[], int n, int search);

void main(){

    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the element to be searched: ");
    int search;
    scanf("%d", &search);
    linear_search(arr, n, search);
}

void linear_search(int arr[], int n, int search) {

    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("Element found in the array.\n");
    } else {
        printf("Element not found in the array.\n");
    }
}