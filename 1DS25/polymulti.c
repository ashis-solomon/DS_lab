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

void reduce_poly();

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
	reduce_poly();

	display_result(first);
	
	printf("\n");
	
	return first;
}

void reduce_poly() {
	poly* term = result;
	poly* prev = result;
	
	while((term != NULL) && (term->link != NULL)) {
		if(term->pow == term->link->pow) {
			int sum = term->coeff + term->link->coeff;
			if(sum) {
				term->coeff = sum;
				term->link = term->link->link;
			}
			else {
				if(term == prev) {
					result = term->link->link;
					term = prev = result;
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


void Product(poly* poly1, poly* poly2) {
	poly* temp;
	poly* a = poly1;
	poly* b = poly2;
	
	while(a != NULL) {
		b = poly2;
		while(b != NULL) {
			int c = a->coeff * b->coeff;
			int p = a->pow + b->pow;
			
			poly* node = (poly*)malloc(sizeof(poly));
			node->coeff = c;
			node->pow = p;
			node->link = NULL;
			
			if(result == NULL)
				result = temp = node;
			else {
				temp->link = node;
				temp = node;
			}
			
			b = b->link;
		}
		a = a->link;
	}
	
	Sort(result);
	reduce_poly();
}

void main() {
	printf("\nPolynomial 1 \n");
	heada = In_Exp();
	printf("\nPolynomial 2 \n");
	headb = In_Exp();
	
	Product(heada, headb);
	
	printf("\nProduct of the polynomials : \n");
	display_result(result);
}
