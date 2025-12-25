/************************************************************
 *  Problem: DNA Storage
 *  Link   : https://www.codechef.com/practice/course/strings/STRINGS/problems/DNASTORAGE
 *  Author : Zeanur Rahaman Zeon
 *  Date   : 2025-12-25
 *  ----------------------------------------------
 *
 *  Problem Description:
 *  You are given a binary string `s` of length `n`, where `n`
 *  is always even.
 *
 *  Every pair of bits represents a DNA character:
 *    "00" -> 'A'
 *    "01" -> 'T'
 *    "10" -> 'C'
 *    "11" -> 'G'
 *
 *  Your task is to convert the binary string into its
 *  corresponding DNA string.
 *
 *  Platform: CodeChef
 *  Status  : [Solved]
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/************************************************************
 * Approach: (Initial)
 * Traverse the string in steps of 2 characters.
 * For each pair, use nested conditional checks to
 * determine the corresponding DNA character.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 ************************************************************/

string encode(const string &s, int n)
{
    string ans = "";

    for (int i = 0; i < n; i += 2)
    {
        if (s[i] == '0')
        {
            if (s[i + 1] == '0')
                ans += 'A';
            else
                ans += 'T';
        }
        else
        {
            if (s[i + 1] == '0')
                ans += 'C';
            else
                ans += 'G';
        }
    }

    return ans;
}

/************************************************************
 * Approach: (Optimized / Cleaner)
 * Process the string in pairs using substr().
 * Match each 2-character substring directly with
 * predefined DNA mappings.
 *
 * Improves readability and maintainability.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 ************************************************************/

string encodeOptimized(const string &s, int n)
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
    return 0;
}

/************************************************************
 * Sample Input:
 * 3
 * 8
 * 00011011
 * 4
 * 01
 * 6
 * 110010
 *
 * Sample Output:
 * ATCG
 * T
 * GAC
 ************************************************************/
