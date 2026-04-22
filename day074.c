//Problem Statement:Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char candidate[MAX][LEN];
    int count[MAX] = {0};
    int unique = 0;

    // Count votes
    for(int i = 0; i < n; i++) {
        int found = -1;

        for(int j = 0; j < unique; j++) {
            if(strcmp(votes[i], candidate[j]) == 0) {
                found = j;
                break;
            }
        }

        if(found == -1) {
            strcpy(candidate[unique], votes[i]);
            count[unique] = 1;
            unique++;
        } else {
            count[found]++;
        }
    }

    // Find winner
    int maxVotes = count[0];
    char winner[LEN];
    strcpy(winner, candidate[0]);

    for(int i = 1; i < unique; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, candidate[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(candidate[i], winner) < 0) {
                strcpy(winner, candidate[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}