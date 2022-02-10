#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
} listnode;

listnode* head = NULL;


void display() {
	listnode* temp = head;
	printf("\n");
	while(temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}


void sort() {
	listnode* temp = head;
	int swapped = 0;
	
	do {
	
		temp = head;
		swapped = 0;
		
		while(temp->link != NULL) {
			if(temp->data < temp->link->data) {
				int t = temp->data;
				temp->data = temp->link->data;
				temp->link->data = t;
				swapped = 1;
			}
			temp = temp->link;
		}
	
	}while(swapped);
}


void insert(int n) {
	listnode* temp;
	for(int i=1; i<=n; i++) {
		printf("\nEnter Student %d Mark : ", i);
		listnode* n = (listnode*)malloc(sizeof(listnode));
		scanf("%d", &n->data);
		n->link = NULL;
		
		if(head == NULL)
			head = temp = n;
		else {
			temp->link = n;
			temp = n;
		}
	}
}

void main() {
	int n;
	printf("Enter the number of Students : ");
	scanf("%d", &n);
	insert(n);
	
	printf("\nThe Sorted List of Marks : \n");
	sort();
	display();
}
