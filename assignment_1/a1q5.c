#include <stdio.h>

typedef struct {
    float coeff; 
    int expo;    
} Term;

typedef struct {
    Term terms[10000]; 
    int no_of_terms;   
} Polynomial;


Polynomial multiplyPolynomials(Polynomial* p1, Polynomial* p2) {
    Polynomial result;
    result.no_of_terms = 0;
    int i,j,expo,found;
    float coeff_sum;

    
    Term temp[10000];
    int temp_size = 0;

 
    for ( i = 0; i < p1->no_of_terms; i++) {
        for ( j = 0; j < p2->no_of_terms; j++) {
            temp[temp_size].coeff = p1->terms[i].coeff * p2->terms[j].coeff;
            temp[temp_size].expo = p1->terms[i].expo + p2->terms[j].expo;
            temp_size++;
        }
    }

   
    for (int i = 0; i < temp_size; i++) {
         coeff_sum = temp[i].coeff;
         expo = temp[i].expo;

        
        found = 0;
        for ( j = 0; j < result.no_of_terms; j++) {
            if (result.terms[j].expo == expo) {
                result.terms[j].coeff += coeff_sum;
                found = 1;
                break;
            }
        }

        
        if (!found && coeff_sum != 0) {
            result.terms[result.no_of_terms].coeff = coeff_sum;
            result.terms[result.no_of_terms].expo = expo;
            result.no_of_terms++;
        }
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
    
    Polynomial p1 = {{{3.0, 5}, {2.0, 2}, {1.0, 0}}, 3};


    Polynomial p2 = {{{5.0, 4}, {2.0, 2}, {4.0, 0}}, 3};


    Polynomial result = multiplyPolynomials(&p1, &p2);

    printf("Resulting polynomial: ");
    printPolynomial(&result);

    return 0;
}
