#include <bits/stdc++.h>
using namespace std;

void fun(int i, int &n)
{
    if (i < 1) // base case
    {
        return;
    }
    cout << (i);
    fun(i - 1, n); // recursive part
}

int main()
{
    int n;
    cin >> n;
    fun(n, n);

    return 0;
}