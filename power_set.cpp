#include <bits/stdc++.h>
using namespace std;

vector<string> allPossibleStrings(string &s)
{
    int n = s.size();
    vector<string> res;
    for (int i = 0; i < (1 << n); i++)
    {
        string sub = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sub += s[j];
            }
        }
        res.push_back(sub);
    }
    return res;
}

int main()
{
    string s = "abc";
    vector<string> subsets = allPossibleStrings(s);
    for (string s : subsets)
    {
        cout << s << endl;
    }
    cout << endl;
    return 0;
}