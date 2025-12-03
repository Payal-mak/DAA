#include <bits/stdc++.h>
using namespace std;

void fun(int i, int &n)
{
    if (i > n) // base case
    {
        return;
    }
    cout << ("payal");
    fun(i + 1, n); // recursive part
}

int main()
{
    int n;
    cin >> n;
    fun(1, n);

    return 0;
}