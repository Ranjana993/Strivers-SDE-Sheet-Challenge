// Problem Statement 
// You have been given two integers 'N' and 'K' . Your task is to find the k-th permuatation sequence of number from 1 to 'N' . The k-th ppermutation is the K-th permutation in the set of all sorted permutation of string 1 to N.

// For Example ::
// If 'N' = 3 and 'K' = 4 . Then all permutation for 'N'= 3 are "123 " , "132" , "213" , "231" , "312", "321" . So the 4-th permuatation is "231".


// Sample Input 1:
// 2
// 2 1
// 3 6
// Sample Output 1:
// 12
// 321
// Explanation For Sample Output 1:
// For the first test case, ‘N’ = 2. So all permutations are “12”, “21”. Now ‘K’ = 1, so the 1st permutation is “12”.

// For the second test case, ‘N’ = 3. So all permutations are  “123”, “132”, “213”, “231”, “312”, “321”. Now ‘K’ = 6, so the 6th permutation is “321”.

string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true)
    {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
