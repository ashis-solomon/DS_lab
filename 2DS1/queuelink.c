#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} node;

node* front = NULL;
node* rear = NULL;


void display_queue(){
	node* temp = front;
	if (temp == NULL) {
		printf("\nQueue is Empty !!!\n");
		return;
	}
	printf("\nQueue : \n");
	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->link;
	}
}


void push(){
	int data;
	printf("\nEnter the data to be inserted : ");
	scanf("%d", &data);
	
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->link = NULL;
	
	if(front == NULL){
        front = ptr;
        rear = ptr;
    }
	else {
		rear->link = ptr;
		rear = ptr;
	}
	
	display_queue();
	
}


void pop() {
	if(front == NULL) {
		printf("\nQueue is Empty !!!\n");
		return;
	}
	else {
        node* temp = front;
		printf("\nPop Element : %d\n", front->data);
		front = front->link;
        free(temp);
	}
	
	display_queue();
}


void main() {
	int choice=0;
    printf("***MENU***\n");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    
	while(choice!=4){
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
    
	switch (choice) {
		case 1: push();
			    break;
		case 2: pop();
			    break;
		case 3: display_queue();
			    break;
        case 4: return; 
		default: printf("INVALID CHOICE...!!\n");
	}
	}
	
}
