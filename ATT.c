#include<stdio.h>

int main(){
    int i, n, total = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arr[n][3];
    
    for(i = 0; i < n; i++){
        printf("Enter Burst Time for process %d: ", i+1);
        arr[i][0] = i + 1;
        scanf("%d", &arr[i][1]);
    }
    
    int time = 0;
    for(i = 0; i < n; i++){
        time += arr[i][1];
        arr[i][2] = time;
        total += arr[i][2];
    }
    
    printf("\nProcess\tBurst Time\tTurn Around Time\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t\t%d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    
    printf("\nTotal Turn Around Time: %d\n", total);
    printf("Average Turn Around Time: %d\n", total/n);

    return 0;
}