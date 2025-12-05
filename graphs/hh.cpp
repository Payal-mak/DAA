#include <bits/stdc++.h>
using namespace std;

void countOccurrences(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (auto &x : freq)
        cout << x.first << " appears " << x.second << " times\n";
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    countOccurrences(arr, n);

    return 0;
}
