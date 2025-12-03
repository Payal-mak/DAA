#include <bits/stdc++.h>
using namespace std;

void reverse_array(vector<int> &arr, int i)
{
    int n = arr.size();
    // base case
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverse_array(arr, i + 1);
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
    // int l = 0;
    // int r = n - 1;
    input_array(arr);
    reverse_array(arr, 0);
    print_array(arr);
    return 0;
}