#include <bits/stdc++.h>
// PROBLEM STATEMENT 

// You have been given an  integer array / list of size N . It only contain 0s , 1s and 2s . Write a solution to sort this array / list ;

// Sample Input 1 :
// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2
// Sample Output 1 :
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2

// BRUTE FORCE SOLUTION IS to sort array by using sorting methond

// BETTER SOLUTION .
void sort012(int *arr, int n)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c0++;
        }
        else if (arr[i] == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    for (int i = 0; i < c0; i++)
    {
        arr[i] = 0;
    }

    for (int i = c0; i < c0 + c1; i++)
    {
        arr[i] = 1;
    }
    for (int i = c0 + c1; i < n; i++)
    {
        arr[i] = 2;
    }
}


// Optimal Solution
void sort012(int *arr, int n)
{
    int s = 0, m = 0, e = n - 1;
    while (m <= e)
    {
        if (arr[m] == 0)
        {
            swap(arr[m], arr[s]);
            s++, m++;
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else
        {
            swap(arr[m], arr[e]);
            e--;
        }
    }
}