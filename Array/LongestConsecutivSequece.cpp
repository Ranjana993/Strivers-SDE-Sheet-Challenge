// Problem Statement 
// You are given an unsorted array/list 'ARR' of 'N' integers . Your task is to return the length of the longest consecutive sequence .
// The consecutive sequence is int he form ['NUM','NUM'+1,'NUM'+2,...'NUM'+L]
// where 'NUM' is the starting integer of the sequence and 'L'+1 is the lenght of the sequence .
// NOTE:: 
// If there are any duplicate in the given array we will count only one of them in the consecutive sequence .


// Sample Input 1 :
// 1 
// 5
// 33 20 34 30 35
// Sample Output 1 :
// 3
// Explanation To Sample Input 1 :
// The longest consecutive sequence is [33, 34, 35].



// SOLUTION
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int maxLength = 0;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            continue;
        else if (arr[i] == arr[i - 1] + 1)
            count++;
        else
        {
            maxLength = max(maxLength, count);
            count = 1;
        }
    }
    maxLength = max(maxLength, count);
    return maxLength;
}