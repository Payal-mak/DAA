/*6.A university needs the minimum number of classrooms to schedule all lectures
without any overlap. Write a greedy-based program that assigns rooms to
lectures based on start and end times. Explain how sorting and greedy room
assignment ensure optimal usage of rooms.*/

// similar to minimum platforms required
#include <bits/stdc++.h>
using namespace std;

int minClassrooms(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int cnt = 0, maxcnt = 0;
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (start[i] < end[j])
        {
            cnt++;
            i++;
        }
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
    vector<int> start = {9, 9, 11, 14, 11, 15};
    vector<int> end = {10, 12, 13, 16, 12, 17};

    cout << "Minimum classrooms needed: " << minClassrooms(start, end) << endl;
    return 0;
}