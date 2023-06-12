// Problem statement 
// You are given an array /list 'ARR' of 'N' integers and an integers value 'TARGET'. You need to check whether there exist four numbers (ARR[i], ARR[j],ARR[k] , ARR[l]) such that (0<= i < j < k < l < N) and ARR[i]+ARR[j]+ARR[k]+ ARR[l] = 'TARGET'


// Sample Output 1:
// Yes
// No
// Explanation For Sample Input 1:
// Test case 1:
// The elements at indices (0, 1, 2, 4) gives sum 9 i.e, ARR[0] + ARR[1] + ARR[2] + ARR[4] = 9. Hence the answer is Yes.

// Test case 2:
// None of the combinations of 4 numbers gives 20 as 'TARGET'. Hence the answer is No. 



// SOLUTION
#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int k = j + 1, m = n - 1;
            while (k < m)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[m];
                if (sum == target)
                    return "Yes";
                else if (sum < target)
                    k++;
                else
                    m--;
            }
        }
    }
    return "No";
}