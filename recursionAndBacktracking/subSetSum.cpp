// Problem statement 
// You are given an array of 'N' integers . You have to find the sum of all the subset in the non decreasing order of the given array 
//  N = 3 and array elements are [1 ,2 ]
// Following are the subset sum :: 
// 0 (by considering empty subset)
// 1
// 2
// 1+2 = 3 
// So , the subset sum are [0 , 1 , 2 , 3];


// Solution
#include <bits/stdc++.h> 


void fn(int i , int sum , vector<int>&arr , int n , vector<int>&ds){
    if(i == n){
        ds.push_back(sum);
        return ;
    }
    fn(i+1 , sum+arr[i] , arr, n , ds);
    fn(i+1 , sum, arr, n , ds);
}

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int>ds ;
    fn(0 , 0 , num , n , ds);
    sort(ds.begin() , ds.end());
    return ds;
}