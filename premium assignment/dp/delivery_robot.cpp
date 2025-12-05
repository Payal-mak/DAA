/*Q.2 A delivery robot must move from the top-left corner of a grid to the bottom-right
corner, but some cells contain obstacles it cannot pass through. Each movement
costs 1 unit of energy, and the robot may move only right or down. Develop a
Dynamic Programming strategy that computes the minimum energy needed for the
robot to reach its destination, considering obstacles and blocked paths. Describe the
recurrence relation and how the DP table evolves.*/

#include <bits/stdc++.h>
using namespace std;

int minEnergy(vector<vector<int>> &grid)
{
    int m = grid.size();    // rows
    int n = grid[0].size(); // columns

    const int INF = 1e9; // large number to represent unreachable state

    // 2D dp vector initialized with INF
    vector<vector<int>> dp(m, vector<int>(n, INF));

    // If starting cell is blocked
    if (grid[0][0] == 1)
        return -1;

    // starting cell needs 0 energy to reach itself
    dp[0][0] = 0;

    // Fill DP table
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] == 1)
                continue; // skip blocked cell

            // from top cell
            if (i > 0 && dp[i - 1][j] != INF)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); //+1 energy to reach dp[i][j]

            // from left cell
            if (j > 0 && dp[i][j - 1] != INF)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    return (dp[m - 1][n - 1] == INF) ? -1 : dp[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};

    cout << "Minimum energy required: " << minEnergy(grid) << endl;
    return 0;
}
