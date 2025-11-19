#include<stdio.h>
int main(){

    int m,n,i,j,l=1;
    int row,col=3,k=0;

    printf("Enter the rows and columns of the sparse matrix respectively: ");
    scanf("%d%d",&m,&n);

    printf("Enter the sparse matrix elements: ");

    int arr[m][n];

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
                      
        }
    }

    printf("The entered matrix is: \n");

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t ",arr[i][j]);
            if (arr[i][j] != 0)
                k++;  
        }
        printf("\n");
    }


    printf("Number of non-zero elements in the sparse matrix: %d\n", k);

    row =k+1;
    int com[row][col];
    com[0][0] = row;
    com[0][1] = col;
    com[0][2] = k;

    l = 1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j] != 0){
                com[l][0] = i;
                com[l][1] = j;
                com[l][2] = arr[i][j];
                l++;
            }
            if(l==row){
                break;
            }
        }
    }

    printf("The compressed sparse matrix is: \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d\t ",com[i][j]);
        }
        printf("\n");
    }

    return 0;
}