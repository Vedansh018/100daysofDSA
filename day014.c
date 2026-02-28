//Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>

int main()
{
    int n, i, j;
    int matrix[100][100];
    int isIdentity = 1; 
    
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                if(matrix[i][j] != 1)
                {
                    isIdentity = 0;
                    break;
                }
            }
            else
            {
                if(matrix[i][j] != 0)
                {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0)
            break;
    }

    if(isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}