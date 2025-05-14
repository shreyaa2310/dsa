#include<iostream>
#include<vector>

using namespace std;

//check if it's safe to assign color "c" to node "node"
bool isSafe(int node, int color[], vector<vector<int>> &graph, int V, int c){
    for(int i=0;i<V;i++){
        if(graph[node][i] && color[i] == c) 
        // checks if there is  a node between [node] and [i] AND if color at index "i" is c
        // if both conditions are true then node has a neighbour i that has already been colored with the same color "c" 
            return false;
    }
    return true;
}

bool solve(int node, int color[], int m, int V, vector<vector<int>> &graph){
    if(node==V)  // If node is V that is the last vertex
        return true;
    
    for(int c=1;c<=m;c++){//check if out of the colors given, any color is possible
        if(isSafe(node,color,graph,V,c)){ // checks if it is possible
            color[node]=c;
        
        // if possible color of next node is determined by calling the solve function on it
        // and when the function completes its call then it is checked if it returns true or false
        if(solve(node+1,color,m,V,graph)) 
            return true;

            color[node]=0; //backtrack
        }
    }
    return false; // if anyone call returns false then all if the pending ones will send back false too
}

bool graphColoring(vector<vector<int>> &graph, int m, int V ){ // takes in graph, allowed colors, no of vertices

    int color[V]={0}; // all the elements in color are given 0 that is no colour
    return solve(0, color,m,V,graph); 

}

int main(){
    
    int V=4;
    vector<vector<int>> graph={
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int m=3;

    if(graphColoring(graph,m,V))
        cout<<"Coloring possible with" <<m<<"colors. \n";
    else
        cout<<"Coloring not possible with "<<m<<" colors. \n";

}

// The color array hols the color assigned to each node, where:
// index of the array = node number
// value at the index = color assigned to that node

