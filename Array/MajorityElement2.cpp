// Problem statement 
// You are given an array / list 'ARR' of integer of length 'N' .You are supposed to find all the elements that occur strictly more than floor (N/3) times in the given array /list 
// Sample Input 2:
// 2
// 6
// 1 2 4 4 3 4
// 4
// 6 6 6 7
// Sample Output 2:
// 4
// 6
// Explanation Of Sample Input 2:
// In the first test case, floor(N/3) = floor(6/3) is equal to 2, and 4 occurs 3 times which is strictly more than N/3. No other element occurs more than 2 times.

// In the second test case, floor(N/3) = floor(4/3) is equal to 1, and 6 occurs 3 times. No other element occurs more than once.


// SOLUTION

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ls;
    int n = arr.size();
    map<int, int> mpp;
    int mini = (int)(n / 3) + 1;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (mpp[arr[i]] == mini)
        {
            ls.push_back(arr[i]);
        }
        if (ls.size() == 2)
            break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}