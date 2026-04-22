//Problem Statement:Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // store prefix sums and first index
    int sum[MAX * 2];
    int index[MAX * 2];
    int size = 0;

    // handle sum = 0 at start
    sum[size] = 0;
    index[size] = -1;
    size++;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int found = -1;
        for(int j = 0; j < size; j++) {
            if(sum[j] == prefixSum) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            int len = i - index[found];
            if(len > maxLen)
                maxLen = len;
        } else {
            sum[size] = prefixSum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}