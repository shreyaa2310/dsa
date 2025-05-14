#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> shortestPath(int V, vector<vector<int>> adj[]){
    priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
    vector<int> dist(V,INT_MAX);

    dist[0]=0;
    pq.push({0,0}); //{distance, node}

    while(!pq.empty()){

        int node = pq.top().second;
        int currentDist=pq.top().first; // distance to this node
        pq.pop();

        for(auto it : adj[node]){
            
            int v=it[0];
            int weight=it[1];

            if(currentDist + weight < dist[v]){
                dist[v]=currentDist+weight;
                pq.push({dist[v],v});
            }
        }

    }

    return dist;

}

int main(){

    int V=5;
    vector<vector<int>> edges={{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1}};

    vector<vector<int>> adj[V];

    for(auto edge : edges){
        int u=edge[0], v=edge[1], w=edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist=shortestPath(5,adj);
    cout<<"Shortest distances from node 0 are :"<<endl;
    for(int i=0;i<V;i++){
        cout<<"Node 0 to "<<"Node "<< i <<":"<<dist[i]<<endl;
    }

    return 0;
}

// Craete a priority queue
// A distance array - each index (represents a node) stores the shortest distance to itself from the source node
// The adjacenecy matrix is giving you elements (node,weight) but since your goal is minimum edge weigh so in the priority queue you push (weight,node)
