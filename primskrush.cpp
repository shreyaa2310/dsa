#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Edge 
{
    int src, dest, weight;
};
bool compareEdge(Edge a, Edge b) 
{
    return a.weight < b.weight;
}
class Graph 
{
    int V;
    vector<vector<pair<int, int>>> adjList;  
    vector<Edge> edges;
public:
    Graph(int V) 
    {
        this->V = V;
        adjList.resize(V);
    }
    void addEdge(int src, int dest, int weight) 
    {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});
        edges.push_back({src, dest, weight});
    }
    void primMST() 
    {
        vector<int> key(V, INT_MAX);  
        vector<bool> inMST(V, false); 
        vector<int> parent(V, -1);    
        key[0] = 0;  
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++)
        {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!inMST[i] && (u == -1 || key[i] < key[u]))
                    u = i;
            inMST[u] = true;
            for (auto [v, weight] : adjList[u]) 
            {
                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
        cout << "\nMinimum Spanning Tree using Prim's Algorithm:\n";
        int totalCost = 0;
        for (int i = 1; i < V; i++) 
        {
            cout << parent[i] << " - " << i << " (Cost: " << key[i] << ")\n";
            totalCost += key[i];
        }
        cout << "Total Minimum Cost: " << totalCost << endl;
    }
    int findSet(int parent[], int i) 
    {
        if (parent[i] == i)
            return i;
        return parent[i] = findSet(parent, parent[i]);  
    }
    void unionSets(int parent[], int rank[], int u, int v) 
    {
        u = findSet(parent, u);
        v = findSet(parent, v);
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else 
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    void kruskalMST() 
    {
        sort(edges.begin(), edges.end(), compareEdge);  
        vector<Edge> mst;
        int parent[V], rank[V];
        for (int i = 0; i < V; i++) 
        {
            parent[i] = i;
            rank[i] = 0;
        }
        int totalCost = 0;
        for (auto edge : edges) 
        {
            int u = findSet(parent, edge.src);
            int v = findSet(parent, edge.dest);
            if (u != v) 
            {
                mst.push_back(edge);
                totalCost += edge.weight;
                unionSets(parent, rank, u, v);
            }
        }
        cout << "\nMinimum Spanning Tree using Kruskal's Algorithm:\n";
        for (auto edge : mst) 
        {
            cout << edge.src << " - " << edge.dest << " (Cost: " << edge.weight << ")\n";
        }
        cout << "Total Minimum Cost: " << totalCost << endl;
    }
};
int main()
{
    int V, E;
    cout << "Enter the number of offices (nodes): ";
    cin >> V;
    cout << "Enter the number of connections (edges): ";
    cin >> E;
    Graph g(V);
    cout << "Enter the edges (src dest cost):\n";
    for (int i = 0; i < E; i++) 
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }
    g.primMST();
    g.kruskalMST();
    return 0;
}

