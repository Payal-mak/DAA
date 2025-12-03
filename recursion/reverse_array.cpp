#include <bits/stdc++.h>
using namespace std;

void reverse_array(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
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
    reverse_array(arr);
    print_array(arr);
    return 0;
}