#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 500
#define INF 10000000

struct Road {
    int node1;
    int node2;
    int time;
    int max_weight;
};

int minim(int a, int b) {
    return (a < b) ? a : b;
}
int maxim(int a, int b)
{
    return(a > b) ? a : b;
}

int max_cups(int num_nodes, int num_roads, struct Road* roads) {
    int graph[MAX_NODES][MAX_NODES];
    int max_weight[MAX_NODES][MAX_NODES];

    for (int i = 1; i <= num_nodes; i++) {
        for (int j = 1; j <= num_nodes; j++) {
            if (i == j) {
                graph[i][j] = 0;
                max_weight[i][j] = INF;
            }
            else {
                graph[i][j] = INF;
                max_weight[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < num_roads; i++) {
        int node1 = roads[i].node1;
        int node2 = roads[i].node2;
        int time = roads[i].time;
        int maxWeight = minim(roads[i].max_weight, INF);

        graph[node1][node2] = time;
        graph[node2][node1] = time;
        max_weight[node1][node2] = maxWeight;
        max_weight[node2][node1] = maxWeight;
    }

    for (int k = 1; k <= num_nodes; k++) {
        for (int i = 1; i <= num_nodes; i++) {
            for (int j = 1; j <= num_nodes; j++) {
                graph[i][j] = minim(graph[i][j], graph[i][k] + graph[k][j]);
                max_weight[i][j] = minim(max_weight[i][j], max_weight[i][k] + max_weight[k][j]);
            }
        }
    }

    int maxCups = 0;
    for (int i = 2; i <= num_nodes; i++) {
        if (graph[1][i] <= 1440 && max_weight[1][i] >= 3000000) {
            maxCups = maxim(maxCups, (max_weight[1][i] - 3000000) * 100);
        }
    }

    return maxCups;
}

int main() {
    int num_nodes, num_roads;
    scanf("%d %d", &num_nodes, &num_roads);

    struct Road* roads = malloc(num_roads * sizeof(struct Road));
    for (int i = 0; i < num_roads; i++) {
        scanf("%d %d %d %d", &roads[i].node1, &roads[i].node2, &roads[i].time, &roads[i].max_weight);
    }

    int result = max_cups(num_nodes, num_roads, roads);
    printf("%d\n", result);

    free(roads);

    return 0;
}