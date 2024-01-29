//Practical 9.1 Breadth First Travseal using adjacency matrix
/*1. First take the number of nodes in the graph as input and then create an adjacency matrix of size n x n where n is the number of nodes in the graph.
2. Next take the adjacency matrix as input.
3. Take the starting node as input.
4. We then call the bfs function with the starting node as the argument.
5. In the bfs function, we first mark the current node as visited and then we enqueue all the nodes which are adjacent to the current node and are not visited.
6. We then dequeue a node from the queue and call the bfs function with the dequeued node as the argument.
7. We repeat the above steps until the queue is empty.
8. Finally, we print the nodes which are reachable from the starting node.*/
#include <stdio.h>
int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10];
 
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}
 
int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    printf("Enter graph data in matrix form:    \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);
    printf("The node which are reachable are:    \n");
    for (i = 1; i <= n; i++)
        if (visited[i])
            printf("%d\t", i);
        else
            printf("BFS is not possible. Not all nodes are reachable");
    return 0;
}