#include <stdio.h>

int partition(int a[], int lb, int ub) {
    int p = a[lb], s = lb, e = ub, t;
    while (s < e) {
        while (a[s] <= p && s < ub) s++;
        while (a[e] > p) e--;
        if (s < e) { t = a[s]; a[s] = a[e]; a[e] = t; }
    }
    t = a[lb]; a[lb] = a[e]; a[e] = t;
    return e;
}

void quicksort(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int main() {
    int n, a[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}



