// Problem Statement
// Given a singly list of 'N' nodes . The objective is to determine the middle node of a singly linked list .Howeven , if the list has an even number of nodes , we return the second middle node .

// Sample Input 1 :
// 5
// 1 2 3 4 5
// Sample Output 1 :
// 3 4 5
// Explanation Of Sample Input 1 :
// 1->2->3->4->5->NULL
// We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.

// SOLUTION 
#include <bits/stdc++.h>
#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

    class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
            this->data = data;
            this->next = NULL;
            }
        };

*****************************************************************/
Node *getMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node *findMiddle(Node *head)
{
    return getMiddle(head);
    // Write your code here
}