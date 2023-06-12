// Problem Statement 
// You are given an array of integers 'ARR' and an integers 'X' , you are supposed to find the element equal to 'X' 
// NOTE:: 
// An array 'B' is a subarray of an array 'A' if 'B' that can be obtained by deletion of several elements from the end of 'A' and several element from the end of 'A'

// Sample Input 1 :
// 2
// 5 8
// 5 3 8 3 10
// 3 7
// 5 2 9
// Sample Output 1 :
// 2
// 1
// Explanation Of Sample Input 1 :
// In the first test case, the subarray from index 1 to index 3 i.e. {3,8,3} and the subarray from index 2 to index 2 i.e. {8} have bitwise XOR equal to 8.

// In the second test case, the subarray from index 0 to index 1 i.e. {5,2} has bitwise XOR equal to 7.

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mp;
    int count = 0;
    int temp = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        temp ^= arr[i];

        if (temp == x)
            count++;

        int k = temp ^ x;
        if (mp.find(k) != mp.end())
            count += mp[k];

        mp[temp]++;
    }
    return count;
}