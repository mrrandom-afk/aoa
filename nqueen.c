#include <stdio.h>
#define MAX 20

int board[MAX][MAX], n;

int isSafe(int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        if (board[i][c]) return 0;

    for (i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (i = r-1, j = c+1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return 0;

    return 1;
}

int solve(int r)
{
    if (r == n) return 1;

    for (int c = 0; c < n; c++)
    {
        if (isSafe(r, c))
        {
            board[r][c] = 1;

            if (solve(r + 1)) return 1;

            board[r][c] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid N!\n");
        return 1;
    }

    if (solve(0))
    {
        printf("\nN-Queen Solution:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c ", board[i][j] ? 'Q' : '.');
            printf("\n");
        }
    }
    else
        printf("No solution exists for N = %d\n", n);

    return 0;
}



N QUEEN
