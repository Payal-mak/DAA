#include <bits/stdc++.h>
using namespace std;

void print_all_subsequences(int idx, vector<int> &arr, vector<int> &sub)
{
    int n = arr.size();

    // base case
    if (idx == n)
    {
        for (int num : sub)
            cout << num << " ";
        cout << endl;
        return;
    }

    // take the element
    sub.push_back(arr[idx]);
    print_all_subsequences(idx + 1, arr, sub);

    // not take the element
    sub.pop_back();
    print_all_subsequences(idx + 1, arr, sub);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> sub;
    print_all_subsequences(0, arr, sub);
    return 0;
}
