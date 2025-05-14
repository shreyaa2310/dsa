# include <iostream>
# include <vector>
# include <stack>

using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[]){

    //Craete a visited array
    int vis[V]={0};
    //Initialize a stack 
    stack<int> st;
    //Push into the queue and mark it as visited
    // st.push(1);
    // vis[1]=1;

    vector<int> dfs;

    for(int i=1;i<V;i++){

        if(!vis[i]){
            // stack<int> st;
            st.push(i);
            vis[i]=1;

        while(!st.empty()){

            int node=st.top();
            st.pop();
            dfs.push_back(node);

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    st.push(it);
                }
            }
        }
    }
    }
 return dfs;
}

void addEdge(vector<int> adj[], int v, int u){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){

    vector<int> adj[9];

    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,4,8);
    addEdge(adj,3,7);
    addEdge(adj,7,8);


    vector<int> ans=dfsOfGraph(9,adj);
    printAns(ans);

}