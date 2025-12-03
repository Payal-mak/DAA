#include <bits/stdc++.h>
using namespace std;

bool check_sorted(vector<int> &arr, int idx)
{
    // base case
    int n = arr.size();
    if (idx == n - 1)
        return true;
    bool rec_result = check_sorted(arr, idx + 1);
    bool ans = rec_result & arr[idx] <= arr[idx + 1];
    return ans;
}

void input_array(vector<int> &arr)
{
    cout << "enter array elements: ";
    for (int &i : arr)
    {
        cin >> i;
    }
}

void print_array(vector<int> &arr)
{
    cout << "reversed array: ";
    for (int &i : arr)
    {
        cout << i;
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    input_array(arr);
    bool ans = check_sorted(arr, 0);
    cout << ans;
    cout << "\n";
    // print_array(arr);
    return 0;
}