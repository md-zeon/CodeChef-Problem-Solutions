#include <bits/stdc++.h>
using namespace std;

string encode(string s, int n)
{
    string ans = "";
    for (int i = 0; i < n; i += 2)
    {
        if (s[i] == '0')
        {
            if (s[i + 1] == '0')
            {
                ans += 'A';
            }
            else
            {
                ans += 'T';
            }
        }
        else
        {
            if (s[i + 1] == '0')
            {
                ans += 'C';
            }
            else
            {
                ans += 'G';
            }
        }
    }

    return ans;
}

string encodeOptimized(string s, int n)
{
    string ans = "";
    for (int i = 0; i < n; i += 2)
    {
        string pair = s.substr(i, 2);
        if (pair == "00")
            ans += 'A';
        else if (pair == "01")
            ans += 'T';
        else if (pair == "10")
            ans += 'C';
        else if (pair == "11")
            ans += 'G';
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // your code goes here
        // cout << encode(s, n) << "\n";
        cout << encodeOptimized(s, n) << "\n";
    }
}
