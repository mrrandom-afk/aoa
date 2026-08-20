#include <stdio.h>
int main() {
    int a[100], n, temp, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("\nInitial Array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    for (int i = 1; i < n; i++) {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;

        printf("\nPass %d: ", i);
        for (int k = 0; k < n; k++) printf("%d ", a[k]);
    }

    printf("\n\nSorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

