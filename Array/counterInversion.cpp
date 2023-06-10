// Problem Statment ;
// For given integer array/list "ARR"  of size 'N' containing all distinct values , find the total number of 'Inverrsion' that mayu exist .

// Sample Input 1 :
// 3
// 3 2 1
// Sample Output 1 :
// 3
// Explanation Of Sample Output 1:
// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).

#include <bits/stdc++.h>
long long getInversions(long long *arr, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                counter++;
            }
        }
    }
    return counter;
}