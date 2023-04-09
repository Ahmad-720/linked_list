#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

typedef struct node node;

node *create_list(){
    int n;
    do{
        printf("Enter how many nodes you want: ");
        scanf("%d",&n);
    }while(n<0);
    if(n == 0) return NULL;
    node *head = (node *)malloc(sizeof(node));
    node *ptr = head;
    node *pre;
    for(int i = 0;i<n;i++){
        printf("ENter data: ");
        scanf("%d",&ptr->data);
        ptr->link = (node *)malloc(sizeof(node));
        pre = ptr;
        ptr = ptr->link;
    }
    pre->link = NULL;
    return head;
}

void print_list(node *head){
    while(head != NULL){
        printf("%d",head->data);
        if(head->link != NULL) printf(" -> ");
        head = head->link;
    }
    printf("\n");
}
