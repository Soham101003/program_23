#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read a matrix from user input
void readMatrix(int **matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return NULL;
    }

    int **result = allocateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    // Allocate memory for matrices
    int **matrix1 = allocateMatrix(rows1, cols1);
    int **matrix2 = allocateMatrix(rows2, cols2);

    // Read matrices from user input
    printf("Matrix 1:\n");
    readMatrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    readMatrix(matrix2, rows2, cols2);

    // Multiply matrices
    int **result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    // Display result
    if (result != NULL) {
        displayMatrix(result, rows1, cols2);
        // Free memory
        freeMatrix(result, rows1);
    }

    // Free memory
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}
