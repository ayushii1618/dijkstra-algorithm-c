#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start);

int main() {
    int graph[MAX][MAX], n, i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 if no edge exists):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INFINITY;
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX] = {0}, i, count, minDist, nextNode;
    
    // Initialize distance array
    for (i = 0; i < n; i++)
        distance[i] = graph[start][i];

    visited[start] = 1;
    distance[start] = 0;

    // Find shortest path for all nodes
    for (count = 1; count < n - 1; count++) {
        minDist = INFINITY;

        // Find the next node with the smallest distance
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update distances
        for (i = 0; i < n; i++) {
            if (!visited[i] && (minDist + graph[nextNode][i] < distance[i])) {
                distance[i] = minDist + graph[nextNode][i];
            }
        }
    }

    // Print result
    printf("\nVertex\tDistance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\n", i, distance[i]);
}
