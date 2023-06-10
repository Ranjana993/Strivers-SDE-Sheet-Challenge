// Problem statemnet 
// You are given a three integers "X" ,"N" and "M" . Your task is to find ("X"^ "N")%M . A^B is defined as A raised to power B and A%C is the remainder when A is divied by C .

// Sample Input 2 :
// 2
// 5 2 10 
// 2 5 4
// Sample Output 2 :
// 5
// 0
// Explanation For Sample Output 2:
// In test case 1, 
// X = 5, N = 2, and M = 10 
// X^N = 5^2 = 25 
// X^N %M = 25 % 10 = 5. 
// So the answer will be 5.

// In test case 2,
// X = 2, N = 5, and M = 4 
// X^N = 2^5 = 32 
// X^N %M = 32 % 4 = 0. 
// So the answer will be 0.



// Solution
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m)
{
    int result = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            result = (1ll * (result * (x) % m)) % m;
        }
        x = (1ll * (x) % m * (x) % m) % m;
        n = n >> 1;
    }
    return result;
}