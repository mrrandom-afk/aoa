#include <stdio.h>

void printTable(int dp[5][6]) {
    printf("\n\nDP TABLE:\n\nItem/Cap ");
    for (int w = 0; w <= 5; w++) printf("%4d", w);
    printf("\n");
    for (int i = 0; i <= 4; i++, printf("\n")) {
        printf("%8d", i);
        for (int w = 0; w <= 5; w++) printf("%4d", dp[i][w]);
    }
}

void knapsack(int wt[], int pr[], int n, int C) {
    int dp[5][6] = {0}, i, w, inc, exc;
    printf("\n========================================\n 0/1 KNAPSACK PROBLEM\n========================================");
    for (i = 1; i <= n; i++) {
        printf("\nPress ENTER to start the next iteration..."); getchar();
        printf("\n\n========================================\nITERATION %d\nItem %d: Weight = %d, Profit = %d\n========================================\n", i, i, wt[i-1], pr[i-1]);
        for (w = 1; w <= C; w++) {
            if (wt[i-1] <= w) {
                inc = pr[i-1] + dp[i-1][w - wt[i-1]]; exc = dp[i-1][w];
                dp[i][w] = inc > exc ? inc : exc;
                printf("\nCapacity %d:\nInclude Item %d = %d\nExclude Item %d = %d\nSelected Value = %d\n", w, i, inc, i, exc, dp[i][w]);
            } else {
                dp[i][w] = dp[i-1][w];
                printf("\nCapacity %d: Item %d is too heavy\nValue copied = %d\n", w, i, dp[i][w]);
            }
        }
        printf("\nTable after Iteration %d:", i);
        printTable(dp);
    }
    printf("\n\n========================================\n FINAL RESULT\n========================================\nMaximum Profit = %d\n\nSelected Items: ", dp[n][C]);
    for (w = C, i = n; i > 0; i--) if (dp[i][w] != dp[i-1][w]) printf("Item %d ", i), w -= wt[i-1];
    printf("\n");
}

int main() {
    int wt[] = {2, 3, 4, 5}, pr[] = {3, 4, 5, 6};
    printf("Items:\nItem 1: Weight = 2, Profit = 3\nItem 2: Weight = 3, Profit = 4\nItem 3: Weight = 4, Profit = 5\nItem 4: Weight = 5, Profit = 6\n\nKnapsack Capacity = 5\n");
    knapsack(wt, pr, 4, 5);
}