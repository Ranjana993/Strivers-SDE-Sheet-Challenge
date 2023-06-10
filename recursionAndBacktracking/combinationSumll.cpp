// Problem statement
// You are given an array 'ARR' of 'N' positive integers .You are also gievn a positive integer 'target'
// Your task is to find all unique combination of the array 'ARR' whose sum is equal to 'target' . Each number in 'ARR' may only be used once in the combination .
// Elements in each combination must be in non decreasing order and you neend to print all unique combination in lexicographical order .

// NOTE :: 
// In lexicographical order , combination / array 'A' comes before array 'B'' if 'A' is the prefix of array 'B' or if none of them is a prefix of the other and at the first position where they differ integer in 'A' is smaller than the integer in 'B'.

// Sample Input 1:
// 2
// 7 8
// 10 1 2 7 6 1 5
// 5 2
// 1 1 1 1 1
// Sample Output 1:
// 1 1 6
// 1 2 5
// 1 7
// 2 6

// 1 1
// Explanation For Sample Input 1:
// Test Case 1:

// Here ‘N’ = 7, Arr = [10, 1, 2, 7, 6, 1 , 5], and ‘target’ = 8
// All unique combinations whose sum of elements is 8 are -:     

// (1, 1, 6)  because, 1 + 1 + 6 = 8
// (1, 2, 5)  because,  1 + 2 + 5 = 8
// (1, 7)  because, 1 + 7 = 8                                                                                                               
// (2, 6)  because,  2 + 6 = 8

// Note, elements in each combination are in non-decreasing order and all unique combinations are arranged in lexicographical order. 

// Test Case 2:

// All elements are 1 in a given array and ‘target’ = 2,  so the only possible combination is (1, 1) as 1 + 1 = 2



// SOLUTION

#include <bits/stdc++.h>

void solve(int ind, int n, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        solve(i + 1, n, target - arr[i], arr, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, n, target, arr, ds, ans);
    return ans;
}