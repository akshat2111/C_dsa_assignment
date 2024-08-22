#include <stdio.h>
#include<math.h>

typedef struct {
    float coeff; 
    int expo;    
} Term;

typedef struct {
    Term terms[10000]; 
    int no_of_terms;   
} Polynomial;


float evaluatePolynomial(Polynomial* p, float x) {
    float result = 0.0;
    int i;
    
    for ( i = 0; i < p->no_of_terms; i++) {
        result += p->terms[i].coeff * pow(x, p->terms[i].expo);
    }
    
    return result;
}


void printPolynomial(Polynomial* p) {

    int i;
    for ( i = 0; i < p->no_of_terms; i++) {
        printf("%.1fx^%d", p->terms[i].coeff, p->terms[i].expo);
        if (i != p->no_of_terms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
   
    Polynomial p = {{{3.0, 5}, {2.0, 2}, {1.0, 0}}, 3};

  
    printf("Polynomial: ");
    printPolynomial(&p);

    
    float x;
    printf("Enter the value of x: ");
    scanf("%f", &x);


    float result = evaluatePolynomial(&p, x);

   
    printf("Value of polynomial at x = %.2f is: %.2f\n", x, result);

    return 0;
}
