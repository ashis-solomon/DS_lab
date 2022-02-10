#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int coeff;
	int pow;
	struct Node* link;
} expression;

expression* heada = NULL;
expression* headb = NULL;
expression* headresult = NULL;


void displayExpression(expression* exp) {
	expression* temp = exp;
	printf("\n");
	while(temp!=NULL) {
		if(temp == exp)
			printf("%d(x^%d)", temp->coeff, temp->pow);
		else
			printf("%+d(x^%d)", temp->coeff, temp->pow);
			
		temp = temp->link;
	}
	printf("\n");
}


void sortExpression(expression* exp) {
	expression* i = exp;
	int swapped = 0;
	
	if(exp == NULL)
		return;
	
	do {
		i = exp;
		swapped = 0;
		
		while(i->link != NULL) {
			if(i->pow < i->link->pow) {
				int temppow = i->pow;
				int tempcoeff = i->coeff;
				i->pow = i->link->pow;
				i->coeff = i->link->coeff;
				i->link->pow = temppow;
				i->link->coeff = tempcoeff;
				swapped = 1;
			}
			i = i->link;
		}
		
	}while(swapped);
}


expression* inputExpression() {
	int num;
	expression* temp;
	expression* first = NULL;
	printf("enter number of terms : ");
	scanf("%d", &num);
	printf("\n");
	for(int i=1; i<=num; i++) {
		printf("\nterm %d\n", i);
		expression* node = (expression*)malloc(sizeof(expression));
		printf("coefficient : ");
		scanf("%d", &node->coeff);
		printf("power : ");
		scanf("%d", &node->pow);
		node->link = NULL;
		if(first == NULL) {
			temp = first = node;
		}
		else {
			temp->link = node;
			temp = node;
		}
	}
	
	sortExpression(first);
	
	displayExpression(first);
	
	printf("--------------------------------------\n");
	
	return first;
}


void filterExpression() {
	expression* term = headresult;
	expression* prev = headresult;
	
	while((term != NULL) && (term->link != NULL)) {
		if(term->pow == term->link->pow) {
			int sum = term->coeff + term->link->coeff;
			if(sum) {
				term->coeff = sum;
				term->link = term->link->link;
			}
			else {
				if(term == prev) {
					headresult = term->link->link;
					term = prev = headresult;
				}
				else {
					prev->link = term->link->link;
					term = prev->link;
				}
			}
			
			continue;
		}
		
		prev = term;
		term = term->link;
	}
}


void findProduct(expression* expa, expression* expb) {
	expression* temp;
	expression* a = expa;
	expression* b = expb;
	
	while(a != NULL) {
		b = expb;
		while(b != NULL) {
			int c = a->coeff * b->coeff;
			int p = a->pow + b->pow;
			
			expression* node = (expression*)malloc(sizeof(expression));
			node->coeff = c;
			node->pow = p;
			node->link = NULL;
			
			if(headresult == NULL)
				headresult = temp = node;
			else {
				temp->link = node;
				temp = node;
			}
			
			b = b->link;
		}
		a = a->link;
	}
	
	sortExpression(headresult);
	filterExpression();
}


void main() {
	printf("\nexpression 1 :\n");
	heada = inputExpression();
	printf("\nexpression 2 :\n");
	headb = inputExpression();
	
	findProduct(heada, headb);
	
	printf("\nProduct of the two experssions is : \n");
	displayExpression(headresult);
}
