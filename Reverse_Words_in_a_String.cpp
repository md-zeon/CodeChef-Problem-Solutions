#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    // write code here...
    vector<string> str;
    string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            str.push_back(word);
            word = "";
            while (s[i + 1] == ' ')
            {
                i++;
            }
        }
        else
        {
            word += s[i];
        }
    }

    str.push_back(word);

    string ans = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        ans += str[i];
        if (i != 0)
            ans += " ";
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << reverseWords(s) << "\n";
    return 0;
}