#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int length(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, m, i, x;
    struct Node *head1=NULL, *head2=NULL, *temp=NULL, *newNode=NULL;

    // First list
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=x;
        newNode->next=NULL;

        if(head1==NULL){
            head1=newNode;
            temp=head1;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    // Second list
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&x);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=x;
        newNode->next=NULL;

        if(head2==NULL){
            head2=newNode;
            temp=head2;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    int len1 = length(head1);
    int len2 = length(head2);

    struct Node *p1=head1, *p2=head2;

    int diff = abs(len1-len2);

    if(len1 > len2)
        for(i=0;i<diff;i++) p1=p1->next;
    else
        for(i=0;i<diff;i++) p2=p2->next;

    while(p1!=NULL && p2!=NULL){
        if(p1->data == p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }

    printf("No Intersection");
    return 0;
}