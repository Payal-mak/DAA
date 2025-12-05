#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int activitySelection(vector<int> &start, vector<int> &finish)
{
    // first we will make an array to store both start and finish time
    vector<vector<int>> arr;

    for (int i = 0; i < start.size(); i++)
    {
        arr.push_back({start[i], finish[i]});
    }
    // then we will sort the activities based on finish time
    sort(arr.begin(), arr.end(), compare);
    // at least one activity can be performed
    int cnt = 1;
    // index of last selected activity
    int j = 0;

    // check if current activity starts before previous activity finishes
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][0] > arr[j][1])
        {
            cnt++;

            // update last selected activity
            j = i;
        }
    }
    return cnt;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    cout << endl;
    return 0;
}