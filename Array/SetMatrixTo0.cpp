#include <bits/stdc++.h>
#include <vector>
// PROBLEM STATEMENT =>
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// BRUTE FORCE SOLUTION

void setZerosrow(int row, vector<vector<int>> &matrix)
{
    int m = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        if (matrix[row][i] != 0)
        {
            matrix[row][i] = -1;
        }
    }
}
void setZeroscol(int col, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1;
        }
    }
}

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                setZerosrow(i, matrix);
                setZeroscol(j, matrix);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// BETTER SOLUTION

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int row[n] = {0}, col[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}







