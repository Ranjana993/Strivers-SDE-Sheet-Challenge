
// Maximum Subarray sum
// You are given an array of length N consisting of integer .You have to find the sum of the subarray (including empty subarray ) having maximum sum among all subarray .


#include <bits/stdc++.h>

long long maxSubarraySum(int arr[], int n)
{
    long long int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        long long int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// Optimal
long long maxSubarraySum(int arr[], int n)
{
    long long int maxi = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}