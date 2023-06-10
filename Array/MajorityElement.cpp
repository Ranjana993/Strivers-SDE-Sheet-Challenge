// Problem statement 
// You have been given an array/list 'ARR'consisting of 'N' integer . Your task is to find the majority element in the array . If there is no majority element present print -1 .


// NOTE :: A majority element is an element that occurs more than floor (N/2)times in the array.

// Sample Input 1:
// 2
// 5
// 2 3 9 2 2
// 4
// 8 5 1 9 
// Sample Output 1:
// 2
// -1
// Explanation of Sample Output 1:
// In test case 1, frequencies of occurrences of different elements are:

// 2 → 3 times
// 3 → 1 time
// 9 → 1 time

// As 2 occurs more than floor(5/2) (i.e. floor(2.5) = 2) times, it is the majority element.

// In test case 2, frequencies of occurrences of different elements are:



// Brute force solution
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > (n / 2))
        {
            return arr[i];
        }
    }
    return -1;
}


// Better solution

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// OPTIMAL SOLUTION
int findMajorityElement(int arr[], int n)
{
    int count = 0, el;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            c1++;
        }
    }
    if (c1 > (n / 2))
    {
        return el;
    }
    return -1;

}