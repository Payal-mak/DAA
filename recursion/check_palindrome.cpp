#include <bits/stdc++.h>
using namespace std;

bool check_pal(string &s, int i)
{
    int n = s.size();
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - i - 1])
        return false;
    return check_pal(s, i + 1);
}

int main()
{
    string s;
    cin >> s;
    bool ans = check_pal(s, 0);
    cout << ans;
    cout << "\n";
    return 0;
}