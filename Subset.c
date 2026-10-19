#include <stdio.h>

int a[20], s[20], n, target;

void sum(int i, int curr, int k)
{
    if (curr == target)
    {
        printf("{ ");
        for (int j = 0; j < k; j++)
            printf("%d ", s[j]);
        printf("}\n");
        return;
    }

    if (i == n || curr > target)
        return;

    if (curr + a[i] <= target)
    {
        s[k] = a[i];
        sum(i + 1, curr + a[i], k + 1);
    }

    sum(i + 1, curr, k);
}

int main()
{
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20)
        return 1;

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1 || a[i] < 0)
            return 1;

    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1 || target < 0)
        return 1;

    printf("Subsets with target sum %d:\n", target);
    sum(0, 0, 0);

    return 0;
}



SUM OF SUBSET
