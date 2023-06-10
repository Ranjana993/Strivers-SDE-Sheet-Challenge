// PROBLEM  STATEMENT
// You are given an integer 'N' . For a given 'N'x'M' chessboard , find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
// A queen can be killed when it lies in the same row or same column , or the same diagonal of any of the other queens ,You have to print all such configuration.

// Sample Output 1:
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0
// Explanation For Sample Input 1:
// Output depicts two possible configurations of the chessboard for 4 queens.

// The Chessboard matrix for the first configuration looks as follows:-

// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.

bool isSafe(int i, int j, vector<vector<int>> &chessBoard, int n)
{
    int tempI = i;
    int tempJ = j;
    while (tempI >= 0)
    {
        if (chessBoard[tempI][j] == 1)
            return false;
        tempI--;
    }
    tempI = i;
    tempJ = j;
    while (tempI >= 0 && tempJ <= n - 1)
    {
        if (chessBoard[tempI][tempJ] == 1)
            return false;
        tempI--;
        tempJ++;
    }
    tempI = i;
    tempJ = j;
    while (tempI >= 0 && tempJ >= 0)
    {
        if (chessBoard[tempI][tempJ] == 1)
            return false;
        tempI--;
        tempJ--;
    }
    return true;
}

void help(int i, int n, vector<vector<int>> &chessBoard, vector<vector<int>> &ans)
{

    if (i == n)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp.push_back(chessBoard[j][k]);
            }
        }
        ans.push_back(temp);
        return;
    }

    for (int j = 0; j < n; j++)
    {

        if (isSafe(i, j, chessBoard, n))
        {
            chessBoard[i][j] = 1;
            help(i + 1, n, chessBoard, ans);
            chessBoard[i][j] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    help(0, n, chessBoard, ans);
    return ans;
}
