#include <bits/stdc++.h>
using namespace std;

int subsequences_sum(int idx, vector<int> &arr, int currentSum, int target)
{
    int n = arr.size();

    // base case
    if (idx == n)
    {
        if (currentSum == target)
        {
            return 1;
        }
        return 0;
    }

    // include the element
    // sub.push_back(arr[idx]);
    int l = subsequences_sum(idx + 1, arr, currentSum + arr[idx], target);

    // exclude the element
    // sub.pop_back();
    int r = subsequences_sum(idx + 1, arr, currentSum, target);
    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    // vector<int> sub;
    int target = 2;

    int ans = subsequences_sum(0, arr, 0, target);
    cout << ans << endl;

    return 0;
}
