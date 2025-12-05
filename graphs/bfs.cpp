#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to perform BFS from a given source node
    void bfs_helper(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans, int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Main BFS traversal function (handles disconnected components)
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> ans;
        vector<bool> visited(v, false);

        // BFS for component starting at node 0
        bfs_helper(adj, visited, ans, 0);

        // Check for disconnected components
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bfs_helper(adj, visited, ans, i);
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
        adj[v2].push_back(u); // Remove this if graph is directed
    }

    Solution sol;
    vector<int> result = sol.bfs(adj);

    cout << "\nBFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
