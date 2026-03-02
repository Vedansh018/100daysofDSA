//Problem: Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], rotated[n];

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    for(int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    printf("Rotated array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}