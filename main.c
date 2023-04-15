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
        printf("Enter data: ");
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

void add_node_at_beginning(node **H){
    node *new_node = (node *)malloc(sizeof(node));
    printf("Enter data you want to add at he end: ");
    scanf("%d",&new_node->data);
    if(*H == NULL){
        new_node->link = NULL;
    }
    else new_node->link = *H;

    *H = new_node;
}

void add_at_end(node **head){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->link = NULL;
    printf("Enter data you want to add at the end: ");
    scanf("%d",&new_node->data);
    if(*head == NULL){
        *head = new_node;
    }
    else{
    node *ptr = *head;
    while(ptr->link != NULL) ptr = ptr->link;
    ptr->link = new_node;
    }
}

int count_nodes(node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->link;
    }
    return count;
}

void add_node_at(node **H,int index){
    if(index < 0 || index >= count_nodes(*H)){
        printf("index out of range.");
        return ;
    }
    node *new_node = (node *)malloc(sizeof(node));
    printf("Enter data you want to add: ");
    scanf("%d",&new_node->data);
    if(index == 0){
        new_node->link = *H;
        *H = new_node;
    }
    else{
        node *ptr = *H;
        node *tmp;
        for(int  i = 0 ; i < index-1 ; i++)ptr = ptr->link;
        tmp = ptr->link;
        ptr->link = new_node;
        new_node->link = tmp;
    }
}

void delete_head(node **H){
    node *head = *H;
    if(head == NULL){
        printf("The list is empty.\n");
    }
    else if(head->link == NULL){
        *H = NULL;
    }
    else{
        *H = head->link;
    }
}

void delete_tail(node **H){
    node *ptr = *H;
    if(ptr==NULL){
        printf("The list is empty.\n");
    }
    else if(ptr->link == NULL) *H = NULL;
    else{
        node *pre;
        while(ptr->link != NULL){
            pre = ptr;
            ptr = ptr->link;
        }
        pre->link = NULL;
        free(ptr);
    }
}


void delete_node_at(node **H,int index){
    if(index < 0 || index >= count_nodes(*H)){
        printf("Out of range.\n");
        return ;
    }
    if(index == 0){
        *H = (*H)->link;
    }
    else{
        node *ptr = *H;
        for(int i = 0;i < index-1;i++) ptr = ptr->link;
        ptr->link = ptr->link->link;
    }


