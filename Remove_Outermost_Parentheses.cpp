#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(const string &s)
{
    // write your code here...
    stack<char> outer;
    stack<char> inner;
    string ans = "";
    for (char c : s)
    {
        if (outer.empty())
        {
            if (c == '(')
            {
                outer.push(c);
            }
        }
        else
        {
            if (!inner.empty())
            {
                if (c == ')')
                {
                    inner.pop();
                }
                else
                {
                    inner.push(c);
                }
                ans += c;
            }
            else
            {
                if (c == '(')
                {
                    inner.push(c);
                    ans += c;
                }
                else
                {
                    outer.pop();
                }
            }
        }
    }

    return ans;
}

string removeOuterParenthesesOptimized(const string &s)
{
    int depth = 0;
    string ans = "";

    for (char c : s)
    {
        if (c == '(')
        {
            if (depth > 0)
            {
                ans += c;
            }
            depth++;
        }
        else
        {
            depth--;
            if (depth > 0)
            {
                ans += c;
            }
        }
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
        string s;
        cin >> s;
        // cout << removeOuterParentheses(s) << "\n";
        cout << removeOuterParenthesesOptimized(s) << "\n";
    }

    return 0;
}