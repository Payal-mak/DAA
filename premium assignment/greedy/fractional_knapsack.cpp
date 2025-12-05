#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool compare(vi &a, vi &b)
{
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(vi &val, vi &wt, int capacity)
{
    int n = val.size();

    // create a 2d vector to store value and wt
    vvi arr(n, vi(2));

    for (int i = 0; i < n; i++)
    {
        arr[i][0] = val[i];
        arr[i][1] = wt[i];
    }
    sort(arr.begin(), arr.end(), compare);

    double res = 0.0;
    int currcapacity = capacity;

    for (int i = 0; i < n; i++)
    {
        // we take the current item, if the wt is less than or equal to current capacity
        if (arr[i][1] <= currcapacity)
        {
            res += arr[i][0];
            currcapacity -= arr[i][1];
        }
        // otherwise, take a fraction
        else
        {
            res += (1.0 * arr[i][0] / arr[i][1]) * currcapacity;

            // knapsack is full
            break;
        }
    }
    return res;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}