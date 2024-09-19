#include <stdio.h>

int main() {
    int rows = 3;
    int cols = 4;
    int size = rows * cols;
    int arr1d[size]; // 1D array
    int arr2d[rows][cols]; // 2D array

    // Initialize 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2d[i][j] = i * cols + j;
        }
    }

    // Copy 2D array to 1D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int k = i * cols + j;
            arr1d[k] = arr2d[i][j];
        }
    }

    // Print 1D array
    for (int k = 0; k < size; k++) {
        printf("arr1d[%d] = %d\n", k, arr1d[k]);
    }

    return 0;
}