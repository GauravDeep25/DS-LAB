#include<stdio.h>

void display(int arr[], int n);

int main() {
    int arr[5], i;
    printf("Enter array elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    display(arr, 5);
    return 0;
}

void display(int arr[], int n) {
    printf("Array elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}