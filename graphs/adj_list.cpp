#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef unordered_set<int> usi;
typedef pair<int, vvi> pivvi;
typedef unordered_map<int, int> umii;
typedef pair<int, int> pii;
typedef unordered_map<int, umii> umiumii;
typedef unordered_map<int, usi> umiusi;

#define forn(i, n) for (int i = 0; i < n; i++)

void print_neighbors(const usi &neighbors)
{
    for (int x : neighbors)
        cout << x << " ";
    cout << "\n";
}

void print_adjacency_list(const umiusi &adjacency_list)
{
    for (const auto &row : adjacency_list)
    {
        cout << row.first << " : ";
        print_neighbors(row.second);
    }
    cout << "\n";
}

void print_adj_list_w_ud(const umiumii &adj_list)
{
    for (const auto &row : adj_list)
    {
        cout << row.first << " :\n";
        for (const auto &nbr : row.second)
        {
            cout << "\t" << nbr.first << " -> " << nbr.second << "\n";
        }
        cout << "\n";
    }
}

// --------- Graph Creation ---------

pivvi dummy_graph()
{
    int v = 7;
    return {v, {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {0, 0}}};
}

// --------- Adjacency List Builders ---------

void initialize_adj_list(umiusi &adjacency_list, int v)
{
    forn(i, v)
        adjacency_list[i] = usi();
}

void fill_adjacency_list_ud_uw(umiusi &adjacency_list, pivvi &graph)
{
    initialize_adj_list(adjacency_list, graph.first);

    for (const vi &edge : graph.second)
    {
        int start = edge[0], end = edge[1];
        adjacency_list[start].insert(end);
        adjacency_list[end].insert(start);
    }
}

void initialize_adj_list(umiumii &adj_list, int v)
{
    forn(i, v)
        adj_list[i] = unordered_map<int, int>();
}

umiumii make_adj_list_w_ud(pivvi &graph_w)
{
    umiumii adj_list;
    initialize_adj_list(adj_list, graph_w.first);

    for (const vi &edge : graph_w.second)
    {
        adj_list[edge[0]][edge[1]] = edge[2];
        adj_list[edge[1]][edge[0]] = edge[2];
    }
    return adj_list;
}

// ---------- Driver ----------

void playing_with_graphs()
{
    pivvi graph1 = dummy_graph();
    umiusi adjacency_list;

    fill_adjacency_list_ud_uw(adjacency_list, graph1);

    cout << "Unweighted Undirected Adjacency List:\n";
    print_adjacency_list(adjacency_list);
}

void solve()
{
    playing_with_graphs();
}

int main()
{
    solve();
}