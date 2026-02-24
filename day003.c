//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, k;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    int comparisons = 0;
    int found = 0;
    
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Not Found\n");
    }
    
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}