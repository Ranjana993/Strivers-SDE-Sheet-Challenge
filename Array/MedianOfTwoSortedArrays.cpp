// Problem Statement
// Given two sorted array 'a' and 'b' of size 'n' and 'm' respectively .
// Find the median of the two sorted arrays .

// Sample Input 1:
// 3 3
// 2 4 6
// 1 3 5
// Sample Output 1:
// 3.5
// Explanation Of Sample Input 1 :
// The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. 
// Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.


// SOLUTION ::
double median(vector<int> &a, vector<int> &b)
{
    if (a.size() > b.size())
        median(b, a);

    int n1 = a.size();
    int n2 = b.size();
    int l = 0, r = n1;

    while (l <= r)
    {
        int m1 = l + (r - l) / 2;
        int m2 = (n1 + n2 + 1) / 2 - m1;
        int l1 = m1 == 0 ? INT_MIN : a[m1 - 1];
        int l2 = m2 == 0 ? INT_MIN : b[m2 - 1];
        int r1 = m1 == n1 ? INT_MAX : a[m1];
        int r2 = m2 == n2 ? INT_MAX : b[m2];

        if (l1 <= r2 and l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return ((max(l1, l2)) + (min(r1, r2))) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            r = m1 - 1;
        }
        else
        {
            l = m1 + 1;
        }
    }
}