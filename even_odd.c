#include<stdio.h>

int main(){
    int num,res;
    printf("Enter a number: ");
    scanf("%d",&num);
    
    res = num % 2;
    
    if(res == 0){
        printf("The number %d is even\n",num);
    } else {
        printf("The number %d is odd\n", num);
    }
    
    return 0;   
}