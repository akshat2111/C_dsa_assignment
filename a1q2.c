#include <stdio.h>

void reverse(int a[], int size) {
    int temp, i;

    // Corrected swapping logic
    for(i = 0; i < size / 2; i++) {
        temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;
    }

    // Print the reversed array
    printf("The reversed array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[20], size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);   

    printf("Enter the elements of the array: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &a[i]);   
    }

    reverse(a, size);

    return 0;
}
