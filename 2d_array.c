#include<stdio.h>

void display(int arr[][3], int rows, int cols);

int main() {
    int arr[3][3], i, j;
    printf("Enter elements for a 3x3 array:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    display(arr, 3, 3);
    return 0;
}

void display(int arr[][3], int rows, int cols) {
    printf("Array elements are:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}