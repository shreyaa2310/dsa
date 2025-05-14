#include <bits/stdc++.h>
using namespace std;


    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INT_MAX);      // Minimum weight to connect each node
        vector<int> parent(V, -1);        // To store the parent of each node
        vector<bool> inMST(V, false);     // To track nodes already in MST (You mark visited only when you add the element in the MST)

        key[0] = 0; // We start with the 0th element. Where the distance to reach the 0th element is zero.
        pq.push({0, 0});  // {weight,node}

        while (!pq.empty())
        {
            int node = pq.top().second; 
            pq.pop();

            if (inMST[node]) continue; // if node has been visited continue that is skip this iteration.
            inMST[node] = true; // Mark the current node as visited

            for (auto &it : adj[node]) // iterate over the adj[node] which contains the node's neighbours
            {
                // it is one of element of node. And node is a vector which contains multiple vectors/pairs
                int v = it[0]; 
                int weight = it[1];

                // key contains minimum weight to visit that node.
                if (!inMST[v] && weight < key[v]) //if not visited (i.e., included in MST) and weight<key[v]  
                {
                    key[v] = weight;
                    pq.push({weight,v});
                    parent[v] = node;
                }
            }
        }

        // Optional: Print the MST edges
        cout << "MST Edges:\n";
        int mstCost = 0;
        for (int i = 1; i < V; ++i)
        {
            cout << parent[i] << " - " << i << " (weight: " << key[i] << ")\n";
            mstCost += key[i];
        }
        return mstCost;
    }


int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1},
        {2, 3, 2}, {3, 4, 1}, {4, 2, 2}
    };

    vector<vector<int>> adj[V]; // an array of vectors of vectors/pairs
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];// parent,node,weight
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mstCost = spanningTree(V, adj);
    cout << "Total weight of MST: " << mstCost << endl;

    return 0;
}

// priority_queue<...> pq; declares a priority queue named pq
// pair<int,int> Each item stored in the queue is a pair of two integers {weight,node}
// vector<pair<int, int>> underlying container used to store data -- 
// greater<pair<int,int>> -- use a min-heap logic (smallest on top)


// It holds the smallest edge weight that connects node i to any node already in the MST.
// It gets updated whenever a cheaper edge to i is found.

