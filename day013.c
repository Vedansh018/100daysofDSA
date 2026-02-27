//Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <stdio.h>

int main()
{
    int r, c;
    int A[100][100];

    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            printf("%d ", A[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++)
        {
            printf("%d ", A[i][right]);
        }
        right--;

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                printf("%d ", A[bottom][i]);
            }
            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                printf("%d ", A[i][left]);
            }
            left++;
        }
    }

    return 0;
}