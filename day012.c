//Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <stdio.h>

int main()
{
    int m, n;
    int A[100][100];
    int isSymmetric = 1;

    scanf("%d %d", &m, &n);

    if (m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] != A[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
    }

    if(isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}