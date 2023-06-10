// PROBLEM STATEMENT;
// You are given an integer aray "ARR " of size "N" and an integer "S" . Your task is to return the list of all pair of elemets such that each sum of elements of each pair equal "S".



// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3
// Explaination For Sample Output 1:
// Here, 1 + 4 = 5
//       2 + 3 = 5
// Hence the output will be, (1,4) , (2,3).


// Solution

#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> res;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                res.push_back(temp);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}