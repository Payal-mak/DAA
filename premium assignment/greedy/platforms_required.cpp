#include <bits/stdc++.h>
using namespace std;

int minPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    // first we will sort both the arrays independently
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int cnt = 0;
    int maxcnt = 0;

    int i = 0, j = 0;

    while (i < n && j < n)
    {
        // check if arrival time is less than dep time
        // then increase the counter
        // that means the trains will intersect (another train will come before the current train departs)
        // so we increase the platform
        if (arr[i] < dep[j])
        {
            cnt++;
            i++;
        }
        // if arrival time is more than dep time,
        else
        {
            cnt--;
            j++;
        }
        maxcnt = max(maxcnt, cnt);
    }
    return maxcnt;
}

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep);
    cout << endl;
    return 0;
}