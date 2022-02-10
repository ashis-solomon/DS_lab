#include<stdio.h>
#include<stdlib.h>
 
typedef struct node{
    int coeff;
    int exp;
    struct node * next;
} polynode;
 
void create_poly(polynode ** node) {
    char ch; 
    int coeff, exp;
    polynode * temp;
    temp = (polynode *) malloc(sizeof(polynode)); 
    *node = temp; 
    do {
        printf("\nEnter the Coeff:");
        scanf("%d", &coeff);
        temp->coeff = coeff;
        printf("\nEnter exp:");
        scanf("%d", &exp);
        temp->exp = exp;
       
        temp->next = NULL;
 
        printf("\nAdd more terms to the polynomial ?(Y/N): ");
        scanf("%d", &ch);

        if(ch=='Y' || ch=='y') {
            temp->next = (polynode *) malloc(sizeof(polynode)); 
            temp = temp->next;
            temp->next = NULL;
        }
    } while (ch=='Y' || ch=='y');
}
 
void display_poly(polynode * node) {
    printf("\nThe Polynomial is :  ");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->exp);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}
 
void polyadd(polynode ** result, polynode * poly1, polynode * poly2) {
    polynode * temp; 
    temp = (polynode *) malloc(sizeof(polynode));
    temp->next = NULL;
    *result = temp; 

    while(poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            temp->exp = poly1->exp;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) {
            temp->exp = poly2->exp;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            temp->exp = poly1->exp;
            temp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
 
        if(poly1 && poly2) {
            temp->next = (polynode *) malloc(sizeof(polynode));
            temp = temp->next;
            temp->next = NULL;
        }
    }
 
    while(poly1 || poly2) {
        temp->next = (polynode *) malloc(sizeof(polynode));
        temp = temp->next;
        temp->next = NULL;
 
        if(poly1) {
            temp->exp = poly1->exp;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            temp->exp = poly2->exp;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
}

void main(){
    char ch;
    do {
        polynode * poly1, * poly2, * poly3;
 
        printf("1st POLYNOMIAL\n ");
        create_poly(&poly1);
        printf("\n1st Polynomial Stored !!!");
        display_poly(poly1);
 
        printf("2nd POLYNOMIAL\n");
        create_poly(&poly2);
        printf("\n2nd Polynomial Stored !!!");
        display_poly(poly2);
 
        polyadd(&poly3, poly1, poly2);
        display_poly(poly3);
 
        printf("\nDo you want to try again ? (Y/N): ");
        scanf("%d", &ch);
    } while (ch == 'y' || ch == 'Y');
    return ;
}
