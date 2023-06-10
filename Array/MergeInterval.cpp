#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

// Problem statement 
// You are given N number of interval , where each interval contains two integers denoting the start time ans the end time for the interval .
// the task  is to merge all tge overlapping intervals ans return the list of merged intervals sorted by increasing order of their start time .
// Two inervals[A, B ] ans [C , D ] are said to be overlapping with each other if there is at least one integer that is covered by both of them 

// Sample Input 1:
// 2
// 1 3
// 3 5
// Sample Output 1:
// 1 5  
// Explanation For Sample Input 1
// Since these two intervals overlap at point 3 so we merge them and the new interval becomes (1,5)



vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// Optimal solution
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}