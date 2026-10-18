#include <stdio.h>
#include <limits.h>

int G[6][6] = {
    {0,2,0,0,0,4}, {2,0,8,0,0,3}, {0,8,0,6,1,0},
    {0,0,6,0,12,0}, {0,0,1,12,0,2}, {4,3,0,0,2,0}
}, key[6], parent[6], mst[6];

void status() {
    printf("\nVertex\tKey\tParent\tMST_Set\n");
    for (int i = 0; i < 6; i++) {
        printf("%d\t", i);
        key[i] == INT_MAX ? printf("INF\t") : printf("%d\t", key[i]);
        parent[i] == -1 ? printf("-\t") : printf("%d\t", parent[i]);
        printf("%s\n", mst[i] ? "YES" : "NO");
    }
}

int main() {
    for (int i = 0; i < 6; i++) key[i] = INT_MAX, parent[i] = -1;
    key[0] = 0;
    printf("\nINITIAL STATUS");
    status();

    for (int step = 1; step < 6; step++) {
        int u = -1, min = INT_MAX;
        for (int v = 0; v < 6; v++)
            if (!mst[v] && key[v] < min) min = key[v], u = v;
        mst[u] = 1;

        printf("\n\n========================================\nSTEP %d\nSelected Vertex = %d\n========================================\n", step, u);

        for (int v = 0; v < 6; v++) {
            if (G[u][v] && !mst[v] && G[u][v] < key[v]) {
                printf("\nUpdating Vertex %d\nOld Key = ", v);
                key[v] == INT_MAX ? printf("INF") : printf("%d", key[v]);
                printf("\nNew Key = %d\nParent[%d] = %d\n", G[u][v], v, u);
                key[v] = G[u][v]; parent[v] = u;
            }
        }
        status();
        printf("\nPress ENTER for next step..."); getchar();
    }

    int total = 0;
    printf("\n\n============ FINAL MST ============\nEdge\tWeight\n");
    for (int i = 1; i < 6; i++) {
        printf("%d - %d\t%d\n", parent[i], i, G[i][parent[i]]);
        total += G[i][parent[i]];
    }
    printf("\nTotal Cost = %d\n", total);
}