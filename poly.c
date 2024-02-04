#include <stdio.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term result[], int *size3) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k] = poly1[i];
            i++;
            k++;
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k] = poly2[j];
            j++;
            k++;
        } else {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++;
            j++;
            k++;
        }
    }

    while (i < size1) {
        result[k] = poly1[i];
        i++;
        k++;
    }

    while (j < size2) {
        result[k] = poly2[j];
        j++;
        k++;
    }

    *size3 = k;
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i != size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    int maxTerms = 100; // Maximum number of terms in the polynomials

    // Input for polynomial 1
    struct Term poly1[maxTerms];
    int size1;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &size1);

    printf("Enter the terms for the first polynomial:\n");
    for (int i = 0; i < size1; i++) {
        printf("Term %d: \n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &poly1[i].coefficient);
        printf("Exponent: ");
        scanf("%d", &poly1[i].exponent);
    }

    // Input for polynomial 2
    struct Term poly2[maxTerms];
    int size2;

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &size2);

    printf("Enter the terms for the second polynomial:\n");
    for (int i = 0; i < size2; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &poly2[i].coefficient);
        printf("Exponent: ");
        scanf("%d", &poly2[i].exponent);
    }

    // Calculate and display the result
    struct Term result[maxTerms];
    int size3;

    addPolynomials(poly1, size1, poly2, size2, result, &size3);

    printf("\nFirst polynomial: ");
    displayPolynomial(poly1, size1);

    printf("\nSecond polynomial: ");
    displayPolynomial(poly2, size2);

    printf("\nResultant polynomial: ");
    displayPolynomial(result, size3);

    return 0;

}