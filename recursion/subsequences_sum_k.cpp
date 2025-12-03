#include <bits/stdc++.h>
using namespace std;

void subsequences_sum(int idx, vector<int> &arr, vector<int> &sub, int currentSum, int target)
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
        }
        return;
    }

    // include the element
    sub.push_back(arr[idx]);
    subsequences_sum(idx + 1, arr, sub, currentSum + arr[idx], target);

    // exclude the element
    sub.pop_back();
    subsequences_sum(idx + 1, arr, sub, currentSum, target);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> sub;
    int target = 2;

    subsequences_sum(0, arr, sub, 0, target);

    return 0;
}
