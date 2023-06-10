// Problem statement 
// You are given an array of size 'N' . The elements of the array are in the range from 1 to "N" .
// Idealy the array should contain elements from 1 to "N" , But due to some miscalculation there is a number R in the range [1 to N] which appear in the array twice and another numnber M in the range [1 to N] which is missing from the array .
// Your task is to find the missing number (M) and the repeating number (R).

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    int missing = -1, repeating = -1;

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
        {
            repeating = i;
        }
        else if (hash[i] == 0)
        {
            missing = i;
        }
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {missing, repeating};
}


// Better solution
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long  Sn = (n *(n+1))/2;
	long long  Sn2 = (n* (n+1)* (2*n + 1))/6;

	long long  s1 =0 ,s2 = 0 ;

	for(int i = 0 ; i< n ; i++){
		s1 += arr[i];
		s2 += (long long)arr[i]* (long long)arr[i];
	}
	
	long long val1 = s1 - Sn;
	long long val2 = s2 - Sn2;
	val2 = val2 / val1 ;
	long long x = (val1+val2)/2;
	long long y = x- val1;

	return { (int)y , (int)x};
}