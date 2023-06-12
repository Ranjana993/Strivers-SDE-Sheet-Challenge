// Problem Statement
// Given a linked list having two pointers in each node . The first one pointes to the next Node of the list . However the other pointer is random and can point to any node of the list or null . The task is to create a deep copy of the given liked list and return its  head . We validate whether the lined list is a copy of the original linked lis t or not .

// NOTE::
// A deep copy of a linked list means we do not copy the reference of the nodes of the original linked list ratger for each node in the original linked list , a new node is created .

// Sample Input 1:
// 1
// 1 2 2 0 3 4 4 4 5 1 -1
// Sample Output 1:
// true
// Explanation Of Sample Input 1:
// For the first test case, “true” will be printed if the linked list is successfully cloned.

// SOLUTION
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head;
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> mpp;
    while (curr != NULL)
    {
        LinkedListNode<int> *temp = new LinkedListNode<int>(curr->data);
        mpp[curr] = temp;
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL)
    {
        LinkedListNode<int> *temp = mpp[curr];
        temp->next = mpp[curr->next];
        temp->random = mpp[curr->random];
        curr = curr->next;
    }
    return mpp[head];
}