#include <stdio.h>
#include <limits.h>

int dist[5];
int edges[6][3] = {{0,1,2}, {0,2,4}, {1,2,-4}, {1,4,-1}, {2,3,2}, {4,3,-3}};

void printDist() {
    printf("\nDistance Array : ");
    for (int i = 0; i < 5; i++) dist[i] == INT_MAX ? printf("INF ") : printf("%d ", dist[i]);
    printf("\n");
}

void bellmanFord(int src) {
    for (int i = 0; i < 5; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    printf("\n========================================\nBELLMAN FORD ALGORITHM\n========================================\n");
    printDist();

    for (int i = 1; i < 5; i++) {
        printf("\nPress ENTER to start next iteration..."); getchar();
        printf("\n\n========================================\nITERATION %d\n========================================\n", i);

        for (int j = 0; j < 6; j++) {
            int u = edges[j][0], v = edges[j][1], wt = edges[j][2];
            printf("\nChecking Edge %d -> %d (Weight=%d)\n", u, v, wt);

            if (dist[u] == INT_MAX) { printf("Vertex %d is not reachable.\n", u); continue; }

            printf("Calculation : %d + (%d) = %d\n", dist[u], wt, dist[u] + wt);
            if (dist[u] + wt < dist[v]) {
                printf("Relaxation Performed\nDistance[%d] : ", v);
                dist[v] == INT_MAX ? printf("INF") : printf("%d", dist[v]);
                dist[v] = dist[u] + wt;
                printf(" -> %d\n", dist[v]);
            } else printf("No Relaxation Required\n");
        }
        printf("\nAfter Iteration %d", i);
        printDist();
    }

    printf("\n\n========================================\nFINAL SHORTEST PATHS\n========================================\n");
    for (int i = 0; i < 5; i++)
        dist[i] == INT_MAX ? printf("Vertex %d : INF\n", i) : printf("Vertex %d : %d\n", i, dist[i]);
}

int main() {
    bellmanFord(0);
    return 0;
}