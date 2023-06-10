#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            for(int k = j+1 ; k < n ; k++){
                for(int l = k+1 ; l < n ; l++){
                    long long sum = arr[i]+arr[j];
                    sum+= arr[k];
                    sum+= arr[l];
                    if(sum == target ){
                        return "Yes";
                    }
                }
            }
        }
    }
    return "No" ;
}