#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    // Step 1: Add boundaries
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // Step 2: Create DP table
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Step 3: Fill DP over increasing length of intervals
    for (int len = 2; len < n + 2; len++)
    {
        for (int left = 0; left + len < n + 2; left++)
        {
            int right = left + len;

            // Try bursting each balloon last in (left, right)
            for (int k = left + 1; k < right; k++)
            {
                dp[left][right] = max(dp[left][right],
                                      nums[left] * nums[k] * nums[right] +
                                          dp[left][k] + dp[k][right]);
            }
        }
    }

    return dp[0][n + 1 - 1]; // dp[0][last]
}

int main()
{
    vector<int> balloons = {3, 1, 5, 8};
    cout << "Maximum coins: " << maxCoins(balloons) << endl;
    return 0;
}
