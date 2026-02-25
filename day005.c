//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
#include <stdio.h>

int main() {
    int p, q, i = 0, j = 0, k = 0;

    scanf("%d", &p);
    int A[p];

    for (i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    int B[q];

    for (i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int merged[p + q];

    i = 0;
    j = 0;
    k = 0;

    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            merged[k] = A[i];
            i++;
        } else {
            merged[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < p) {
        merged[k] = A[i];
        i++;
        k++;
    }

    while (j < q) {
        merged[k] = B[j];
        j++;
        k++;
    }

    for (i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}