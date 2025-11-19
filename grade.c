#include<stdio.h>

int main(){
    int marks;
    printf("Enter your marks: ");
    scanf("%d",&marks);
    
    if(marks >= 90){
        printf("Grade: S\n");
    } else if(marks >= 80){
        printf("Grade: A\n");
    } else if(marks >= 70){
        printf("Grade: B\n");
    } else if(marks >= 60){
        printf("Grade: C\n");
    } else if(marks >= 50){
        printf("Grade: D\n");
    } else if (marks >= 40){
        printf("Grade: E\n");
    } else if (marks <= 39 && marks >= 0){
        printf("Grade: F\n");
    } else {
        printf("Enter valid marks\n");
    }
    
    return 0;
}