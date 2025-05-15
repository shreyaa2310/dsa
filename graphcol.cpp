#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int c, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (graph[node][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}
bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int m, int n) 
{
    if (node == n)
        return true;
    for (int c = 1; c <= m; c++) 
    {
        if (isSafe(node, graph, color, c, n)) 
        {
            color[node] = c;
            if (solve(node + 1, graph, color, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
int main() 
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    vector<int> color(n, 0);
    if (solve(0, graph, color, m, n)) 
    {
        cout << "Color assignment:\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    } 
    else
    {
        cout << "No solution exists with " << m << " colors.\n";
    }
    return 0;
}
