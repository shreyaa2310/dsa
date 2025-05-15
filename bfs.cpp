# include <iostream>
# include <vector>
# include <queue>

using namespace std;

vector<int> bfsOfGraph(int V,vector<int> adj[]){

    // Create a visited list
    int vis[V]={0};
    // Initialize a queue
    queue<int> q;
    // Push the starting node in the queue and mark it as visited
    q.push(0);
    vis[0]=1;
    // While the queue is not empty

    vector<int> bfs; 
    //To store the result

    while(!q.empty()){

        int node=q.front();
        q.pop();
        //Pop front node from the queue(say u)
        bfs.push_back(node);
        //Process u (Print it or store it)

        //For each neighbour v, of u in the adjacency list,
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1; //Mark v as visited 
                q.push(it);//Push v into the queue
            }
        }
    }
    return bfs;
}

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}

int main( ){
    vector<int> adj[6];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);

    vector<int> ans=bfsOfGraph(5,adj);

    printAns(ans);

}








