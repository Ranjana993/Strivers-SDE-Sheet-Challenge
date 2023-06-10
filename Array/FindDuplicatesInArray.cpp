// Problem statement 
// You are given an array of integer 'ARR' containing N element . Each integer is in the range [1 ,N-1 ] , with exactly one element repeated in the array .
// Your task is to find the duplicate element . The duplicate may be repeated more than twice in the array , nut there will be exactly one element that is repeated in the array
// NOTE :
// All the integer in the array appear only once except for preciseely one integer which appear two or more times .

// Sample Input 1:
// 1
// 3
// 1 1 2
// Sample Output 1:
// 1
// Explanation of Sample Input 1:
// 1 is repeated in the array, hence function returns 1.


// Better solution
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {

        int index = abs(arr[i]);

        if (arr[index] < 0)
        {
            return index;
        }

        arr[index] *= -1;
    }
    return ans;
;
}

// Optimal solution

int findDuplicate(vector<int> &arr, int n)
{
while (arr[0] != arr[arr[0]])
{
        swap(arr[0], arr[arr[0]]);
}
return arr[0];
}