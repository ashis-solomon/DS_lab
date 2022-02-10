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
		printf("%c   ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	if(beg==end){
		printf("EMPTY!!");
}
}


void insertElement(char data) {
	int pos = -1;
	
	listNode* n = (listNode*)malloc(sizeof(listNode));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	
	
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

int isPalindrome(listNode *start) {
    if (start == NULL)    // null string check
		return 1;
 
    listNode *end = start;
    while (end->next != NULL)  // traverse to the end - ptr
        end = end->next;
 
    while (start != end) {
        if (start->data != end->data) 
            return 0;
       
        start = start->next;
        end = end->prev;
    }
	
    return 1;
}

void main() {
	char str[100];
	printf("Enter the string : ");
	scanf("%s",&str);
	int i=0,len = 0;
	for(len=0;str[len]!='\0';len++);	
	printf("\nThe Length : %d",len);

	while(i<len){
		insertElement(str[i]);
		i++;
	}
	printf("\nThe Doubly list : \n");
	display();
	int check = isPalindrome(beg);
	if(check == 1)
		printf("\nString is A PALINDROME !!");
	else if(check == 0)
		printf("\nString is NOT A PALINDROME !!");
}
