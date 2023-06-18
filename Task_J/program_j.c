#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int count = 0;

void dfs(int currentVertex, int n) {
    visited[currentVertex] = 1;
    count++;
    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    dfs(s - 1, n);

    printf("%d\n", count);

    return 0;
}