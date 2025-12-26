/************************************************************
 *  Problem: Reverse Words in a String
 *  Link   : https://www.codechef.com/practice/course/strings/STRINGS/problems/PALINDRCHECK
 *  Author : Zeanur Rahaman Zeon
 *  Date   : 2025-12-27
 *  ----------------------------------------------
 *
 *  Problem Description:
 *  You are given a string `s` consisting of words separated
 *  by spaces. The string may contain:
 *   - Leading spaces
 *   - Trailing spaces
 *   - Multiple spaces between words
 *
 *  Your task is to reverse the order of the words and return
 *  a single-space separated string without extra spaces.
 *
 *  Platform: CodeChef
 *  Status  : [Solved]
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

/************************************************************
 * Approach: (Initial)
 * Manually traverse the string and extract words.
 * - Ignore multiple consecutive spaces
 * - Store words in a vector
 * - Reconstruct the answer in reverse order
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 ************************************************************/

string reverseWords(string s)
{
    vector<string> str;
    string word = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            str.push_back(word);
            word = "";

            // Skip consecutive spaces
            while (i + 1 < s.size() && s[i + 1] == ' ')
            {
                i++;
            }
        }
        else
        {
            word += s[i];
        }
    }

    // Push last word
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

/************************************************************
 * Helper Function:
 * Remove leading spaces from the string.
 ************************************************************/

string prefixTrim(const string &s)
{
    int start = 0;
    while (start < s.size() && s[start] == ' ')
        start++;
    return s.substr(start);
}

/************************************************************
 * Helper Function:
 * Remove trailing spaces from the string.
 ************************************************************/

string suffixTrim(const string &s)
{
    int end = s.size() - 1;
    while (end >= 0 && s[end] == ' ')
        end--;
    return s.substr(0, end + 1);
}

/************************************************************
 * Approach: (Optimized / Cleaner)
 * - Trim leading and trailing spaces
 * - Use stringstream to extract words efficiently
 * - Reverse the order of extracted words
 *
 * This approach is more readable and robust.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 ************************************************************/

string reverseWordsOptimized(string s)
{
    // Trim unnecessary spaces
    s = prefixTrim(s);
    s = suffixTrim(s);

    vector<string> words;
    string word;
    stringstream ss(s);

    // Extract words (automatically handles multiple spaces)
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Build reversed string
    string result;
    for (int i = words.size() - 1; i >= 0; i--)
    {
        result += words[i];
        if (i != 0)
            result += " ";
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    // cout << reverseWords(s) << "\n";
    cout << reverseWordsOptimized(s) << "\n";

    return 0;
}

/************************************************************
 * Sample Input:
 *   "  hello   world   from  codechef  "
 *
 * Sample Output:
 *   "codechef from world hello"
 ************************************************************/
