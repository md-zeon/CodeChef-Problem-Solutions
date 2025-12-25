/************************************************************
*  Problem: Remove Outermost Parentheses
*  Link   : https://www.codechef.com/practice/course/strings/STRINGS/problems/REMOVEPAREN
*  Author : Zeanur Rahaman Zeon
*  Date   : 2025-12-25
*  ----------------------------------------------

*  Problem Description:
*  You are given a valid parentheses string s. A valid parentheses string is composed of '(' and ')' that are properly balanced.
*  A valid parentheses string is called primitive if it cannot be split into two smaller valid parentheses strings.
*  Your task is to remove the outermost parentheses from every primitive part of s and print the final result.
*
*  Platform: CodeChef
*  Status  : [Solved]
************************************************************/

#include <bits/stdc++.h>
using namespace std;

/************************************************************
 * Approach: (Initial)
 * Use two stacks to differentiate between the outermost
 * boundary and the internal structure.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 ************************************************************/

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

/************************************************************
 * Approach: (Optimized)
 * Utilize a 'depth' counter to track nesting levels.
 * Parentheses are only appended to the result if they exist
 * at a nesting level greater than 0.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 ************************************************************/

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

/************************************************************
 * Sample Input:
 * 4
 * ((()))
 * (()(()))
 * ()()
 * ((())())(()(()))
 *
 * Sample Output:
 * (())
 * ()(())
 *
 * (())()(())
 ************************************************************/