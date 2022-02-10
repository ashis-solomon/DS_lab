/*
PROGRAM 3 - TO IMPLEMENT TO CIRCULAR LINKED LIST
- Ashis Solomon
*/

#include<stdio.h>  
#include<stdlib.h>  

typedef struct node{  
    int data;  
    struct node *next;   
}listNode;  

listNode *front;  
  
void insert_begin(){ 
    listNode *ptr,*temp;   
    int item;   
    ptr = (listNode*)malloc(sizeof(listNode));  
    if(ptr == NULL)  
    {  
        printf("OVERFLOW!!!\n");  
    }  
    else   
    {  
        printf("\nEnter the element to be inserted : ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL){  
            front = ptr;  
            ptr->next = front;  
        }  
        else{     
            temp = front;  
            while(temp->next != front)  
                temp = temp->next;  
            ptr->next = front;   
            temp -> next = ptr;   
            front = ptr;  
        }   
        printf("Inserted!!\n");  
    }  
              
}  
void insert_last(){  
    listNode *ptr,*temp;   
    int item;  
    ptr = (listNode *)malloc(sizeof(listNode));  
    if(ptr == NULL){  
        printf("OVERFLOW\n");  
    }  
    else{  
        printf("\nEnter the element to be inserted : ");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(front == NULL){  
            front = ptr;  
            ptr->next = front;    
        }  
        else{  
            temp = front;  
            while(temp -> next != front){  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr->next = front;  
        }  
        printf("Inserted!!\n");  
    }  
  
}  
  
void delete_begin(){  
    listNode *ptr;   
    if(front == NULL){  
        printf("UNDERFLOW!!!\n");    
    }  
    else if(front->next == front){  
        front = NULL;  
        free(front);  
        printf("Deleted!!\n");  
    }  
    else{   
        ptr = front;   
        while(ptr->next != front)  
            ptr = ptr->next;   

        ptr->next = front->next;  
        free(front);  
        front = ptr->next;  
        printf("Deleted!!\n");  
    }  
}  
void delete_last(){  
    listNode *ptr, *temp;  
    if(front == NULL){  
        printf("UNDERFLOW!!!\n");  
    }  
    else if(front->next == front){  
        front = NULL;  
        free(front);  
        printf("Deleted!!\n");  
  
    }  
    else{  
        ptr = front;  
        while(ptr->next != front){  
            temp=ptr;  
            ptr = ptr->next;  
        }  
        temp->next = ptr->next;  
        free(ptr);  
        printf("Deleted!!\n");  
    }  
}  
  
void display(){  
    listNode *ptr;  
    ptr = front;  
    if(front == NULL){  
        printf("EMPTY!!\n");  
    }     
    else{  
        printf("The List : ");       
        while(ptr->next != front){  
            printf("  %d  ", ptr -> data);  
            ptr = ptr->next;  
        }  
        printf("  %d\n", ptr -> data);  
    }  
}  

void main(){  
    int choice =0;  
    printf("\n*****MENU*****\n");  
    printf("\n1.Insert at Begining\n2.Insert at End");
    printf("\n3.Delete from Beginning\n4.Delete from last\n5.Display\n6.Exit\n\n");
    while(choice!=6){  
        printf("\nEnter the Menu choice : \n");         
        scanf("\n%d",&choice);  
        switch(choice){  
            case 1 :    insert_begin();
                        break;  
            case 2 :    insert_last();
                        break;  
            case 3 :    delete_begin();
                        break;  
            case 4 :    delete_last();
                        break;  
            case 5 :    display();
                        break;  
            case 6 :    return;
                        break;  
            default:    printf("\nEnter a valid choice !!\n");  
        }  
    }  
}  