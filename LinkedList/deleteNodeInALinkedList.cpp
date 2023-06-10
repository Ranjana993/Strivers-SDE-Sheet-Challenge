// Problem statement
// You are given a Singly linked list of integers and a reference to the coed to be deleted . Every node of the linked list has a unique value written on it .Your task is to delete that node from the linked list

// Sample Input 1:
// 2
// 2 5 7 10 -1
// 7
// -8 3 4 -2 1 -1
// 4
// Sample Output 1:
// 2 5 10 -1
// -8 3 -2 1 -1
// Explanation For Sample Input 1:
// For the first test case, the given Linked List is

// 2->5->7->10->NULL

// So, after deleting the node 7, the Linked List becomes 2 → 5 → 10 → NULL, which is shown in the below figure.



// SOLUTION
#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> *node)
{
    LinkedListNode<int> *nextNode = node->next;
    swap(nextNode->data, node->data);
    node->next = nextNode->next;
    delete nextNode;
}