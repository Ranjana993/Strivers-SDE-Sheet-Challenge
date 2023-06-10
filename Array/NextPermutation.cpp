// NEXT PERMUTATION
// You have been given a permuatation of N integer . A sequence of N integer is  called a permuation if it contains all integers from 1 to N exactly once  .Your task is to rearrange the nunver ans generate the lexicpgraphically next greater permutation .

// Sample Input 1:
// 2

// 3 // ts 1
// 1 2 3
// 5 // ts 2
// 2 3 1 4 5
// Sample Output 1:
// 1 3 2
// 2 3 1 5 4
// Explanation Of Sample Input 1:
// In the first test case, the lexicographically next greater permutation is [1, 3, 2].

// In the second test case, the lexicographically next greater permutation is [2, 3, 1, 4, 5].

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    for (int i = n - 1; i > index; i--)
    {
        if (permutation[i] > permutation[index])
        {
            swap(permutation[i], permutation[index]);
            break;
        }
    }
    reverse(permutation.begin() + index + 1, permutation.end());
    return permutation;
}