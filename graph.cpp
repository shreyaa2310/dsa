#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool direction){    //function for adding edges
        // direction = 0 -> undirected 
        // direction = 1 -> directed

        // create an edge from u to v
    }
};

int main(){
    return 0;
}