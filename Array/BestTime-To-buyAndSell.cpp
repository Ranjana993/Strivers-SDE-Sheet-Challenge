// Problem Statement
// You are given an array/list 'price' where the elements of the array represent the prices of the stocks as they were yesterday and indices of the array represent minutes . Your task is to find ans return the maximum profit you can make by buying and selling the stock . You can buy and sell the stock only once 

// NOTE : You can't sell whitout buying first .

// Sample Input 1:
// 2
// 4
// 1 2 3 4
// 4
// 2 2 2 2
// Sample Output 1:
// 3
// 0
// ........................
// Explanation For Sample Output 1:
// For the first test case, it’s optimal to buy the stock at minute 0 and sell it at minute 3 to get a maximum profit of 3.

// For the second test case, the maximum profit will be 0 for all possible ways of buying and selling stock.

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int mini = prices[0];
    int maxProfit = 0, n = prices.size();

    for (int i = 0; i < n; i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(prices[i], mini);
    }
    return maxProfit;
}
