#include <stdio.h>

void sortDescending(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int a[20], size, i, numDeletions,k,pos;

    printf("Enter the size of the array: ");
    scanf("%d", &size);   

    printf("Enter the elements of the array: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &a[i]);   
    }

    printf("Enter the number of elements you want to delete: ");
    scanf("%d", &numDeletions);

    int positions[numDeletions];

    printf("Enter the positions to delete (1-based index): ");
    for(i = 0; i < numDeletions; i++) {
        scanf("%d", &positions[i]);
    }

    
    sortDescending(positions, numDeletions);

    for( k = 0; k < numDeletions; k++) {
         pos = positions[k];
        

        if(pos < 1 || pos > size) {
            printf("Invalid position %d!\n", pos);
            continue;
        }

      
        for(i = pos - 1; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size--;  
    }
     printf("Array after deletion: ");
    for(i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Element at 5th place: %d", a[5-1]);

   

    return 0;
}