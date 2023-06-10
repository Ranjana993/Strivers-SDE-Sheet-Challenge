// problem Statement 
// You have been given  a singly linked list of 'N' nodes with integer data and an integer 'K'.
// Your task is to remove the 'Kth' node deom the end of the given Linked list and return the head of the modified linked list 

// Example ::
// Inpout : 1 ->2 ->3 ->4 -> NULL and 'K' = 2 ;
// After removing the second node from the end , the linekd list become 1 -> 2 -> 4 -> NULL;

// Sample Input 1 :
// 6 3
// 1 2 3 4 5 6 
// Sample Output 1 :
// 1 2 3 5 6
// Explanation For Sample Input 1:
// In the given linked list the node with data ‘4’ will be removed as this is the 3rd node from the end of the Linked List.

Node *removeKthNode(Node *head, int K)
{
    Node *start = new Node();
    start->next = head;
    Node *fast = start;
    Node *slow = start;

    for (int i = 1; i <= K; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}
