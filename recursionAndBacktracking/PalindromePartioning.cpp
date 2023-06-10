// Problem Statement 
// You are given a stringg 'S' . Your task is to partition 'S' such that every substring of the partition is a palindrome . You need to retrun all possible palindrome partitioning of 'S'.

// NOTE :
// A substring is a contigious segment of a string .

// Sample Input 1:
// aaC
// Sample Output 1:
// ["C", "a", "a"]
// ["C", "aa"]
// Explanation For Input 1:
// For the given string "aaC" there are two partitions in which all substring of partition is a palindrome.

#include <bits/stdc++.h>

bool isPalindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(int idx, string &s, vector<string> &path, vector<vector<string>> &ans)
{
    if (idx == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            path.push_back(s.substr(idx, i - idx + 1));
            solve(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> path;
    solve(0, s, path, ans);
    return ans;
}