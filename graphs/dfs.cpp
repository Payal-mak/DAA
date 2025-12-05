#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs_helper(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited, int src)
    {
        visited[src] = true;
        ans.push_back(src);

        for (int neighbor : adj[src])
        {
            if (!visited[neighbor])
            {
                dfs_helper(adj, ans, visited, neighbor);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> ans;
        vector<bool> visited(v, false);

        // First DFS from node 0
        dfs_helper(adj, ans, visited, 0);

        // Handle disconnected graph
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs_helper(adj, ans, visited, i);
            }
        }

        return ans;
    }
};

int main()
{
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v2;
        cin >> u >> v2;
        adj[u].push_back(v2);
        adj[v2].push_back(u); // Comment if graph is directed
    }

    Solution sol;
    vector<int> result = sol.dfs(adj);

    cout << "\nDFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
