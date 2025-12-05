/*A network provides limited bandwidth and receives multiple requests, each offering a certain profit and requiring specific bandwidth units. Develop a greedy strategy to maximize total profit while staying within the bandwidth limit, and explain why the greedy approach is suitable for this allocation problem.*/
#include <bits/stdc++.h>
using namespace std;

struct Request
{
    int bandwidth; // while staying between the limits
    int profit;    // we have to maximize profit
};

bool compare(Request a, Request b)
{
    double r1 = (1.0 * a.profit) / a.bandwidth;
    double r2 = (1.0 * b.profit) / b.bandwidth;
    return r1 > r2;
}

double maximizeProfit(vector<Request> &req, int totalBandwidth)
{
    // sort profit-to-bandwidth ratio
    sort(req.begin(), req.end(), compare);

    double totalProfit = 0.0;

    for (auto &r : req)
    {
        if (totalBandwidth == 0)
            break;

        // full request
        if (r.bandwidth <= totalBandwidth)
        {
            totalProfit += r.profit;
            totalBandwidth -= r.bandwidth;
        }
        // take fractional part
        else
        {
            double fraction = (1.0 * totalBandwidth) / r.bandwidth;
            totalProfit += r.profit * fraction;
            totalBandwidth = 0;
        }
    }
    return totalProfit;
}

int main()
{
    vector<Request> requests = {
        {10, 100}, {20, 90}, {30, 120}};

    int bandwidthLimit = 50;

    cout << "Maximum Profit: " << maximizeProfit(requests, bandwidthLimit) << endl;
    return 0;
}