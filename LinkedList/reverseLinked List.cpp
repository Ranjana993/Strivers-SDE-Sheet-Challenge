// Problem Statement 
// Given a singly linkedlist of integer .Your task is to return the head of the reversed linked list 
// For Example 
// The given linked list is 1 -> 2->3->4 ->NULL .Then the reverse linked list is 4->3->2->1 ->NULL and the head of the linked list would be 4 .


// Sample Input 1 :
// 1
// 1 2 3 4 5 6 -1
// Sample Output 1 :
// 6 5 4 3 2 1 -1
// Explanation For Sample Input 1 :
// For the first test case,  After changing the next pointer of each node to the previous node, The given linked list is reversed.

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
LinkedListNode<int> *reverseNode(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *head1 = reverseNode(head->next);
    head->next->next = head;
    head->next = NULL;
    return head1;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    return reverseNode(head);
}