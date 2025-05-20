#include <stdio.h>

void quicksort(int a[], int first, int last, int pivotChoice) { 
    if (first < last) {
        int pivot=first;
        int i = first;
        int j = last;
        int temp;

        // Select pivot based on user's choice
        switch (pivotChoice) {
            case 1: // First element as pivot
                pivot = first;
                break;
            case 2: // Last element as pivot
                pivot = last;
                break;
            case 3: // Middle element as pivot
                pivot = (first + last) / 2;
                break;
            default: // Default to first element if invalid choice
                pivot = first;
                break;
        }
 while (i < j) {
            // Moving i right, skipping over elements less than or equal to pivot
            while (a[i] <= a[pivot] && i < last) 
                i++;
            // Moving j left, skipping over elements greater than pivot
            while (a[j] > a[pivot]) 
                j--; 

            // Swap if i is less than j
            if (i < j) {
                temp = a[i];         
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Move the pivot element to the beginning for standard partitioning
        temp = a[pivot];
        a[pivot] = a[first];
        a[first] = temp;
        pivot = first;

       
        // Swap pivot with a[j] (partitioning)
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        // Recursively sort the two partitions
        quicksort(a, first, j - 1, pivotChoice);  // Left partition
        quicksort(a, j + 1, last, pivotChoice);   // Right partition
    }
}

int main() {
    int a[40], n, i, pivotChoice;

    // Read number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    // Ask the user for pivot selection method
    printf("Choose pivot selection method:\n");
    printf("1. First element\n");
    printf("2. Last element\n");
    printf("3. Middle element\n");
    printf("Enter your choice: ");
    scanf("%d", &pivotChoice);

    // Call quicksort function
    quicksort(a, 0, n - 1, pivotChoice);

    // Output sorted array
    printf("Sorted elements are: ");
    for (i = 0; i < n; i++) 
        printf("%d\t", a[i]);

    return 0;
}
