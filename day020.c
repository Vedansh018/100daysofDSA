//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix_sum = 0;
    int count = 0;

    int hash[20001] = {0};  
    int offset = 10000;     

    hash[offset] = 1; 

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(hash[prefix_sum + offset] > 0) {
            count += hash[prefix_sum + offset];
        }

        hash[prefix_sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}