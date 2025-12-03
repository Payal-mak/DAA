#include <bits/stdc++.h>
using namespace std;

bool subsequences_sum(int idx, vector<int> &arr, vector<int> &sub, int currentSum, int target)
{
    int n = arr.size();

    // base case
    if (idx == n)
    {
        if (currentSum == target)
        {
            for (int num : sub)
                cout << num << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // include the element
    sub.push_back(arr[idx]);
    if (subsequences_sum(idx + 1, arr, sub, currentSum + arr[idx], target) == true)
    {
        return true;
    }

    // exclude the element
    sub.pop_back();
    if (subsequences_sum(idx + 1, arr, sub, currentSum, target) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> sub;
    int target = 2;

    bool ans = subsequences_sum(0, arr, sub, 0, target);
    cout << ans << endl;

    return 0;
}
