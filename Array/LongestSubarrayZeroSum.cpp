// Problem Statement 
// Ninja loves playing with numbers . So his friend gives him an array on his birthday . The array consists of positive and negative integers . Now Ninja is interested in finding the length of the longest subarray whose sum is zero .

// Sample Input 1:
// 2 
// 5
// 1 3 -1 4 -4
// 4
// 1 -1 2 -2 
// Sample Output 1:
// 2
// 4 
// Explanation For Sample Output 1:
// In the first test case, the given array is (1, 3, -1, 4, -4). The sub-arrays we can create are (1), (3), (-1), (4), (-4), (1, 3), (3, -1), (-1, 4), (4, -4), (1, 3, -1), (3, -1, 4), (-1, 4, -4), (1, 3, -1, 4), (3, -1, 4, -4), (1, 3, -1, 4, -4). Out of them only (4, -4) is the sub array whose sum is zero.Length of this sub array is 2 and hence we return 2 as the final answer.

// In the second test case, the given array is (1, -1, 2, -2). The sub-arrays we can create are (1), (-1), (2), (-2), (1, -1), (-1, 2), (2, -2), (1, -1, 2), (-1, 2, -2), (1, -1, 2, -2). Out of them sub arrays with zer sum are (1, -1), (2, -2), (1, -1, 2, -2). Out of them only (1, -1, 2, -2) has the longest length of 4. Hence we return 4 as the final answer.

// SOLUTION

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{
    unordered_map<int, int> mp;
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] += arr[i - 1];
    }

    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            maxi = i + 1;
        }
        else if (mp.find(arr[i]) != mp.end())
        {
            maxi = max(maxi, i - mp[arr[i]]);
        }
        else
        {
            mp[arr[i]] = i;
        }
    }

    return maxi;
}