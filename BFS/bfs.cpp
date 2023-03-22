// Start BFS traversal from source vertex.
// While doing BFS, store the shortest distance to each of the other nodes and also maintain a parent vector for each of the nodes.
// Make the parent of source node as “-1”. For each node, it will store all the parents for which it has the shortest distance from the source node.
// Recover all the paths using parent array. At any instant, we will push one vertex in the path array and then call for all its parents.
// If we encounter “-1” in the above steps, then it means a path has been found and can be stored in the paths array.
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void find_paths(vector<vector<int>> &paths, vector<int> &path, vector<int> parent[], int n, int u)
{
    if (u == -1)
    {
        paths.push_back(path);
        return;
    }
    for (int par : parent[u])
    {
        path.push_back(u);
        find_paths(paths, path, parent,
                   n, par);
        path.pop_back();
    }
}

void bfs(vector<int> adj[], vector<int> parent[], int n, int start)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(start);
    parent[start] = {-1};
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[v] == dist[u] + 1)
            {
                parent[v].push_back(u);
            }
        }
    }
}

void print_paths(vector<int> adj[], int n, int start, int end)
{
    vector<vector<int>> paths;
    vector<int> path;
    vector<int> parent[n];
    bfs(adj, parent, n, start);
    find_paths(paths, path, parent, n, end);
    for (auto v : paths)
    {
        reverse(v.begin(), v.end());
        for (int u : v)
            cout << u << " ";
        cout << endl;
    }
}

int main()
{
    int n = 6;
    vector<int> adj[n];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 3);
    add_edge(adj, 1, 4);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 5);
    add_edge(adj, 4, 5);
    int src = 0;
    int dest = n - 1;
    print_paths(adj, n, src, dest);
    return 0;
}
