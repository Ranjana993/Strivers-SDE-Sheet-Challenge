// Problem Statement 
// You are given a non empty String S containng no space and a dictionary of non empty string (say the list of word ) . You are supposed to construct and retrun all possible sentences after adding space in the original given string 'S' . such that each word in a sentence exist in the given dictionary.
// NOTE :: 
// The same word in the dictionary can be used multiple times tp make sentences 
// Assume that the dictionary does not contain duplicate word .

// Sample Input 1:
// 1
// 6
// god is now no where here
// godisnowherenowhere
// Sample Output 1:
// god is no where no where
// god is no where now here
// god is now here no where
// god is now here now here
// Explanation To Sample Input 1:
// One way to make sentences is to take “god” and append a space, then take “is”  and append space, take “now” from the dictionary and take “here” as well. 
// Similarly, for other sentences also, we can add space to get other possible sentences. Note that we can reuse dictionary words as “no” and “now” are used two times in the same sentence.



// SOLUTION RECURSIVE
#include <bits/stdc++.h>

void solve(int in, string ds, string &s, map<string, int> &m, vector<string> &ans)
{

    if (in == s.size())
    {

        ans.push_back(ds);

        return;
    }

    for (int i = in; i < s.size(); i++)
    {

        string tmp = s.substr(in, i - in + 1);

        if (m[tmp] >= 1)
        {

            int n = ds.size();

            ds += tmp + " ";

            solve(i + 1, ds, s, m, ans);

            ds.erase(n);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    map<string, int> mpp;
    for (int i = 0; i < dictionary.size(); i++)
    {
        mpp[dictionary[i]]++;
    }
    solve(0, "", s, mpp, ans);
    return ans;
}