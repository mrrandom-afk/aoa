#include <stdio.h>

int main() {
    int a[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("\nInitial Array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;

        int temp = a[i]; a[i] = a[min]; a[min] = temp;

        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) printf("%d ", a[k]);
        printf("\n");
    }

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
