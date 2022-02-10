/*
PROGRAM 2 - TO IMPLEMENT A DOUBLY LINKED LIST
- Ashis Solomon
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
}listNode;

listNode *beg = NULL;
listNode *end = NULL;


void display(){
	printf("\n");
	listNode* temp = beg;
	while(temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	if(beg==end){
		printf("EMPTY!!");
}
}


void insertElement(int pos) {
	int data;
	printf("\nEnter the data : ");
	scanf("%d", &data);
	
	listNode* n = (listNode*)malloc(sizeof(listNode));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	
	if(pos == 0) {
		printf("Enter the position to insert data [1 Onwards]: ");
		scanf("%d", &pos);
	}
	
	if((beg == NULL) && (end == NULL))
		beg = end = n;
	else if(pos == 1) {
		beg->prev = n;
		n->next = beg;
		beg = n;
	}
	else {
		listNode* temp = beg;
		int count = 0;
		
		while(temp != NULL) {
			count++;
			if(count == pos)
				break;
			temp = temp->next;
		}
		
		if(temp != NULL) {
			n->prev = temp->prev;
			temp->prev->next = n;
			n->next = temp;
			temp->prev = n;
		}
		else {
			end->next = n;
			n->prev = end;
			end = n;
		}
	}
	
}

void delete_ele() {

	if( (beg == NULL) && (end == NULL) ) {
		printf("UNDERFLOW!!\n");
		return;
	}
	
	int ele;
	printf("Enter the element to delete : ");
	scanf("%d", &ele);
	
	listNode* temp = beg;
	
	while(temp != NULL) {
		if(temp->data == ele) {
			if((temp == beg) && (temp == end))
				beg = end = NULL;
			else if(temp == beg) {
				beg = beg->next;
				beg->prev = NULL;
			}
			else if(temp == end) {
				end = end->prev;
				end->next = NULL;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			
			free(temp);
			break;
		}
		
		temp = temp->next;
	}
	
	display();
}


void main() {
	int choice=0;
	printf("****MENU****\n");
	printf("\n1.Insert at Begining\n2.Insert at End\n3.Insert at a position");
	printf("\n4.Deletion\n5.Display\n6.Exit\n");

while(choice!=6){	
	printf("Enter a Menu choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: insertElement(1);
				break;
		case 2: insertElement(-1);
				break;
		case 3: insertElement(0);
				break;
		case 4: delete_ele();
				break;
		case 5: display();
				break;
		case 6: exit(0);
				break;
		default: printf("Enter a valid choice!!\n");
	}
}
}
