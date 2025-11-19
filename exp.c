#include<stdio.h>
#include"myheader.h"

int main() {
    int a, b, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    sum = add(a, b);
    printf("Sum: %d\n", sum);
    
    return 0;
}