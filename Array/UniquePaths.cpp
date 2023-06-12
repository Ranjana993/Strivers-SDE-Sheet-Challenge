// Problem Statement 
// You are present at point 'A' which is the top left cell of an MxN matrix , your destination is at point 'B' , which is at the bottom right cell of the same matrix . Your task is to find the total nuber of unique paths from point 'A' to point 'B' . In other words , you will be given the dimension of the matrix as integers 'M' and 'N', your task is to find the total nunber of unique paths from the cell MATRIX[0][0]  to MATRIX[M-1] [N-1].

// Sample Input 1:
2 2 2 1 1
// Sample Output 1:
// 2
// 1
// Explanation Of Sample Output 1:
// In test case 1, we are given a 2 x 2 matrix, to move from matrix[0][0] to matrix[1][1] we have the following possible paths.

// Path 1 = (0, 0) -> (0, 1) -> (1, 1)
// Path 2 = (0, 0) -> (1, 0) -> (1, 1)

// Hence a total of 2 paths are available, so the output is 2.

// In test case 2, we are given a 1 x 1 matrix, hence we just have a single cell which is both the starting and ending point. Hence the output is 1.

// SOLUTION
#include <bits/stdc++.h>
    int
    uniquePaths(int m, int n)
{
    int Nn = m + n - 2;
    int R = m - 1;
    double res = 1;
    for (int i = 1; i <= R; i++)
    {
        res = res * (Nn - R + i) / i;
    }
    return (int)res;
}