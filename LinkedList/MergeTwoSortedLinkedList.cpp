// Problem Statement 
// You are given two sorted linked list . You have to merge them to produce combined sorted linked list . You need to return the head of the final linekd list ;

// For Example 
// If the first list is :: 1 -> 4 ->5 -> NULL and the second list is :: 2 -> 3 -> 5 -> NULL
// the final list would be :: 1 -> 2 -> 3 -> 4 -> 5 -> NULL


// Sample Input 1:
// 2
// 1 4 5 -1
// 2 3 5 -1
// 7 8 -1
// 1 3 4 6 -1
// Sample Output 1:
// 1 2 3 4 5 5 -1
// 1 3 4 6 7 8 -1
// Explanation Of Input 1:
// The first test case is already explained in the problem statement.

// The second test case, the first list is: 7 -> 8 -> NULL
// The second list is: 1 -> 3 -> 4 -> 6 -> NULL
// The final list would be: 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> NULL



// SOLUTION .......................
#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data > second->data)
    {
        swap(first, second);
    }
    Node<int> *res = first;

    while (first != NULL && second != NULL)
    {
        Node<int> *temp = NULL;
        while (first != NULL && first->data <= second->data)
        {
            temp = first;
            first = first->next;
        }
        temp->next = second;
        swap(first, second);
    }
    return res;