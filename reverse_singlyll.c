/*
PROGRAM 1 - TO REVERSE A SINGLY LINKED LIST
- Ashis Solomon
*/

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

void insert_rand(int value,int check){
    listnode *node = create(value);
    listnode *temp = front;
    listnode *ptr = NULL;
    if(node!=NULL){
        while(temp->data != check && temp!=NULL){   
            ptr = temp;
            temp = temp->link;
         }
         if(temp==NULL){
             printf("\nElement not in the list !!!\n");
             return;
        }
         ptr = temp;
         temp = temp->link;
         ptr->link = node;
         node->link = temp;
    }
    else{
        printf("\nOVERFLOW!!!\n");
    }  
    
}

void delete_begin(){
    listnode *temp = front;
    if(temp!=NULL){
        front = front->link;
        free(temp);
        printf("\nDeleted !!\n");
    }
    else{
        printf("\nList is Empty!!!\n");
    }
}

void delete_rand(int check){
    listnode *temp = front;
    listnode *ptr = NULL;
    if(temp->data==check && temp->link==NULL){
        free(temp);
        temp=NULL;
        front = NULL;
        printf("\nDeleted !!\n");
    }
    else if(temp!=NULL){
        while(temp->data!=check && temp->link!=NULL){
        ptr = temp;
        temp = temp->link;
    }
    if(temp->link == NULL && temp->data!=check){
        printf("\nELement is not in the list !!\n");
    }
    else{
        ptr->link = temp->link;
        free(temp);
        printf("\nDeleted !!\n");
    }
    }    
    return;
}

void delete_end(){
    listnode *temp = front;
    listnode *ptr = NULL;
    if(temp==NULL){
        printf("\nList is Empty!!\n");
    }
    else if(temp->link == NULL && temp==front){
        front = NULL;
        temp = NULL;
        printf("\nDeleted !!\n");
    }
    else{
        while(temp->link != NULL){
            ptr =temp;
            temp = temp->link;
        }          
        ptr->link=NULL;
        free(temp);
        printf("\nDeleted !!\n");
    }
}


void display(){
    listnode *temp = front;
    if(temp==NULL){
        printf("\nThe List is Empty !!!\n\n");
    }
    while(temp!=NULL){
        printf(" %d   ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void reverse(){                                 
    int count = 1,i,ct;
    listnode *temp = front;
    listnode *ptr;
    
    while(temp->link!=NULL){
        count++;
        temp=temp->link;
    }
    ptr = temp;
    for(i=0;i<(count-1);i++){
        temp = front->link;
        front->link = ptr->link;
        ptr->link = front;
        front = temp;
    }    
    front = ptr;
    printf("\nThe REVERSED List is : \n");
    display();
}

void main(){
    int choice,value,check;
    printf("****MENU****\n\n");
    printf("1.Insert at Begining\n2.Insert after Element\n");
    printf("3.Insert at End\n4.Delete from Begining\n");
    printf("5.Delete an Element\n6.Delete from End\n");
    printf("7.Display\n8.REVERSE THE LIST\n9.Exit\n");
    printf("\nEnter the Menu choice : ");
    scanf("%d",&choice);
    while(choice!=9){
        switch(choice){
        case 1 :    printf("\nEnter the value to be inserted : ");
                    scanf("%d",&value);
                    insert_begin(value);
                    break;
        case 2 :    printf("Enter the value after which element is to be inserted : ");
                    scanf("%d",&check);
                    printf("Enter the value to be inserted : ");
                    scanf("%d",&value);
                    insert_rand(value,check);
                    break;
        case 3 :    printf("\nEnter the value to be inserted : ");
                    scanf("%d",&value);
                    insert_end(value); 
                    break;  
        case 4 :    delete_begin();
                    break;
        case 5 :    printf("Enter the value to be deleted : ");
                    scanf("%d",&check);
                    delete_rand(check);
                    break;
        case 6 :    delete_end();
                    break;
        case 7 :    display();
                    break;
        case 8 :    reverse();
                    break;
        case 9 :    return;         
        default:    printf("\nEnter a valid choice !!\n");         
    }
    printf("Enter the Menu Choice : ");
    scanf("%d",&choice);
    }
    return;
}