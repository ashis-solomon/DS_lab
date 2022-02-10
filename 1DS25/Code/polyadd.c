#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int coeff;
	int pow;
	struct Node* link;
} poly;

poly* heada = NULL;
poly* headb = NULL;
poly* result = NULL;


void display_result(poly* exp) {
	poly* temp = exp;
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


void Sort(poly* exp) {
	poly* i = exp;
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


poly* In_Exp() {
	int num;
	poly* temp;
	poly* first = NULL;
	printf("Enter the Number of Terms : ");
	scanf("%d", &num);
	printf("\n");
	for(int i=1; i<=num; i++) {
		printf("\nterm %d\n", i);
		poly* node = (poly*)malloc(sizeof(poly));
		printf("Coeff : ");
		scanf("%d", &node->coeff);
		printf("Exponent : ");
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
	
	Sort(first);
	
	display_result(first);
	
	printf("\n");
	
	return first;
}


void Sum(poly* poly1, poly* poly2) {
	
	poly* temp;
	poly* node;
	
	while((poly1 != NULL) && (poly2 != NULL)) {
		if(poly1->pow == poly2->pow) {
			int sum = poly1->coeff + poly2->coeff;
			if(sum) {
				node = (poly*)malloc(sizeof(poly));
				node->coeff = sum;
				node->pow = poly1->pow;
				node->link = NULL;
				if(result==NULL)
					result = temp = node;
				else {
					temp->link = node;
					temp = node;
				}
			}
			poly1 = poly1->link;
			poly2 = poly2->link;
		}
		
		else if(poly1->pow > poly2->pow) {
			node = (poly*)malloc(sizeof(poly));
			node->coeff = poly1->coeff;
			node->pow = poly1->pow;
			node->link = NULL;
			if(result==NULL)
				result = temp = node;
			else {
				temp->link = node;
				temp = node;
			}
			
			poly1 = poly1->link;
		}
		
		else {
			node = (poly*)malloc(sizeof(poly));
			node->coeff = poly2->coeff;
			node->pow = poly2->pow;
			node->link = NULL;
			if(result==NULL)
				result = temp = node;
			else {
				temp->link = node;
				temp = node;
			}
			
			poly2 = poly2->link;
		}
	}
	
	while(poly1 != NULL) {
		node = (poly*)malloc(sizeof(poly));
		node->coeff = poly1->coeff;
		node->pow = poly1->pow;
		node->link = NULL;
		if(result==NULL)
			result = temp = node;
		else {
			temp->link = node;
			temp = node;
		}
		
		poly1 = poly1->link;
	}
	
	while(poly2 != NULL) {
		node = (poly*)malloc(sizeof(poly));
		node->coeff = poly2->coeff;
		node->pow = poly2->pow;
		node->link = NULL;
		if(result==NULL)
			result = temp = node;
		else {
			temp->link = node;
			temp = node;
		}
		
		poly2 = poly2->link;
	}
	
}


void main() {
	printf("\nPolynomial 1 \n");
	heada = In_Exp();
	printf("\nPolynomial 2 \n");
	headb = In_Exp();
	
	Sum(heada, headb);
	
	printf("\nSum of the polynomials : \n");
	display_result(result);
}
