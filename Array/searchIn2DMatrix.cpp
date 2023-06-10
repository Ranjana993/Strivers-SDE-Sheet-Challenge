// Problem statement 
// You have been given a 2-D array "MAT" of size MxN where 'M' and 'N' denote the number of rows and columns , respectively .The elements of each rows are sorted in non decreasing order Moreover , the first element of a row is greater than the last element of the previous row (if exists)
// You are given an integer 'TARGET' and your task is to find if it exist in the given 'MAT' or not

// Sample Input 2 :
// 3 3 78
// 1 2 4 
// 6 7 8
// 9 10 34
// Sample Output 2 :
// false
// Explanation For Sample Input 2 :
// The 'TARGET' = 78 does not exist in the 'MAT'. Therefore in the output, we see 'false'.

// SOLUTION
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    if (!mat.size())
        return false;
    int n = mat.size(), m = mat[0].size();
    int start = 0, end = (n * m) - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mat[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (mat[mid / m][mid % m] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}