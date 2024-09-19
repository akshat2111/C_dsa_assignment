#include <stdio.h>

typedef struct term {
    float coeff;
    int expo;
} term;

typedef struct poly {
    term a[10000];
    int no_of_terms;
} poly;


void addPolynomials(poly P1, poly P2, poly* P3) {
    int i = 0, j = 0, k = 0;

    while (i < P1.no_of_terms && j < P2.no_of_terms) {
        if (P1.a[i].expo == P2.a[j].expo) {
            (*P3).a[k].coeff = P1.a[i].coeff + P2.a[j].coeff;
            (*P3).a[k].expo = P1.a[i].expo;
            if ((*P3).a[k].coeff != 0) { 
                k++;
            }
            i++;
            j++;
        } else if (P1.a[i].expo < P2.a[j].expo) {
            (*P3).a[k] = P1.a[i];
            i++;
            k++;
        } else {
            (*P3).a[k] = P2.a[j];
            j++;
            k++;
        }
    }


    while (i < P1.no_of_terms) {
        (*P3).a[k++] = P1.a[i++];
    }

    while (j < P2.no_of_terms) {
        (*P3).a[k++] = P2.a[j++];
    }

    (*P3).no_of_terms = k;
}

void printPolynomial(poly p) {
    int i;
    for ( i = 0; i < p.no_of_terms; i++) {
        printf("%.1fx^%d", p.a[i].coeff, p.a[i].expo);
        if (i != p.no_of_terms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    poly P1 = {{{3.0, 5}, {2.0, 2}, {1.0, 0}}, 3};

    poly P2 = {{{5.0, 4}, {2.0, 2}, {4.0, 0}}, 3};

    poly P3; 
    P3.no_of_terms = 0;

 
    addPolynomials(P1, P2, &P3);

    printf("Resultant polynomial: ");
    printPolynomial(P3);

    return 0;
}

