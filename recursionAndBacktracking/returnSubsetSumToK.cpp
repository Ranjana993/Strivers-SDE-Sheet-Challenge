// Problem statement
// Given an integer array of 'ARR' of size 'N' and an integer 'K' return all the subset of 'ARR' which sum to 'K' .
// Subser of an array 'ARR' is a tuple that can be obained from 'ARR' by removing some (possibly all )elements of 'ARR'.
// NOTE ::
// The order of subset is not importtant .
// The order of element in a particular subset be in increasing order of the inbox .



// Sample Input 1:
// 3
// 2 4 6
// 6
// Sample Output 1:
// 2 4
// 6
// Explanation Of The Sample Input 1:
// For the array'ARR' = {2, 4, 6}, we can have subsets {}, {2}, {4}, {6}, {2, 4}, {2, 6}, {4, 6}, {2, 4, 6}. Out of these 8 subsets, {2, 4} and {6} sum to the given 'K' i.e. 6.

// SOLUTION 
void findCombination(int i, int target, int sum, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (i == arr.size())
    {
        if (sum == target)
        {
            ans.push_back(ds);
        }
        return;
    }
    findCombination(i + 1, target, sum, arr, ans, ds);
    ds.push_back(arr[i]);
    findCombination(i + 1, target, sum + arr[i], arr, ans, ds);
    ds.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, k, 0, arr, ans, ds);
    return ans;
}