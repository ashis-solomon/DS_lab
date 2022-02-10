#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}listnode;

listnode *front = NULL;

listnode *create(int value){
    listnode *node;
    node = (listnode*)malloc(sizeof(listnode));
    node->data = value;
    node->link = NULL;
    return node;
}


void insert_begin(int value){
    listnode *node = create(value);
    if(node!=NULL){
        if(front==NULL){
        front = node;
    }
    else{
        node->link = front;
        front = node;
    }
    }
    else{
        printf("\nOVERFLOW!!!\n");
    }
}

void insert_end(int value){
    listnode *node = create(value);
    listnode *temp = front;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    if(node!=NULL){
        temp->link = node;
    }
    else{
        printf("\nOVERFLOW!!!\n");
    }
}

void display(){
    listnode *temp = front;
    if(temp==NULL){
        printf("\nThe List is Empty !!!\n\n");
    }
    int i=1;
    while(temp!=NULL){
        printf(" %d [Stud %d]   ",temp->data,i);
        temp = temp->link;
        i++;
    }
    printf("\n");
}

void main(){
    int n,value;
    printf("Enter the number of Students : ");
    scanf("%d",&n);
    printf("Enter the marks [total] of the Students : \n");
    scanf("%d",&value);
    insert_begin(value); 
    for(int i=2;i<=n;i++){
        scanf("%d",&value);
        insert_end(value); 
    }
    
    printf("\n");
    printf("The List of Marks [Stud. number]: \n");
    display();
    printf("\nThe Sorted List of Marks [Stud. number]: \n");
    display();
    return;
}