#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V 5 
int minDistance(const vector<int>& dist, const vector<bool>& visited) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}
void dijkstra(int graph[V][V], int src) 
{
    vector<int> dist(V, INT_MAX);  
    vector<bool> visited(V, false);  
    dist[src] = 0;  
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, visited);  
        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    cout << "Shortest distances from the college (node " << src << ") to other landmarks:\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << " -> Distance: " << dist[i] << endl;
}
int main() 
{
    int graph[V][V] = 
    {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 3},
        {5, 2, 9, 0, 2},
        {0, 0, 3, 2, 0}
    };
    dijkstra(graph, 0);
    return 0;
}




