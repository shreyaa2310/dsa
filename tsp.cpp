#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int tsp(vector<vector<int>>& graph, vector<bool>& visited, int pos, int n, int count, int cost, int start, vector<int>& path, vector<int>& bestPath, int& minCost) 
{
    if (count == n && graph[pos][start]) 
    {
        cost += graph[pos][start];
        if (cost < minCost) 
        {
            minCost = cost;
            bestPath = path;
            bestPath.push_back(start);
        }
        return cost;
    }
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i] && graph[pos][i]) 
        {
            visited[i] = true;
            path.push_back(i);
            tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start, path, bestPath, minCost);
            visited[i] = false;
            path.pop_back();
        }
    }
    return minCost;
}
int main() 
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    vector<bool> visited(n, false);
    vector<int> path, bestPath;
    int minCost = INT_MAX;
    int start = 0;
    visited[start] = true;
    path.push_back(start);
    tsp(graph, visited, start, n, 1, 0, start, path, bestPath, minCost);
    cout << "\nMinimum Cost: " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath)
        cout << city << " ";
    cout << endl;
    return 0;
}


