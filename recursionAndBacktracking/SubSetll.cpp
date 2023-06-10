// Problem  Statment 
// Ninja is observing an array of 'N' numbers and wants as possible . Can you help the Ninjas to find all the unique subset?

// NOTE:: Two subset are called same if they have set of element . For examle {3  ,4 ,1} and {1 ,4 ,3 }are not uniuqe subsets

// FOR EXAMPLE ::
// For the givern if arr ={1 ,1 ,3} the answer will be [] , [1] , [1,1] , [1,3] , [3],[1 ,1,3];

// Sample Input 1:
// 2
// 3
// 1 1 3
// 4
// 1 3 3 3
// Sample Output 1:
// 1
// 1 1
// 1 3
// 3
// 1 1 3

// 1
// 1 3
// 1 3 3
// 1 3 3 3 
// 3 
// 3 3
// 3 3 3
// Explanation Of Sample Input 1:
// For the first test case,
// The unique subsets will be  [ ],[1],[1,1],[1,3],[3],[1,1,3]. 

// For the second test case:
// The unique subsets will be  [ ],[1,3],[1,3,3],[1,3,3,3],[3],[3,3],[3,3,3].


// SOLUTION .....
#include <bits/stdc++.h>
#include<vector>
void findSub(int ind, int n, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    if (ind == n)
        return;

    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        findSub(i + 1, n, arr, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    findSub(0, n, arr, ds, ans);
    return ans;
}
