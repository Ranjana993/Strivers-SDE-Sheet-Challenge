// Problem Statement 
// You are given a linked list conyaining 'n' 'head' nodes , where every node in the linked list contains two pointers .
// 1:: 'next' which pointes to the next node in the list 
// 2:: 'child' pointer to a linked list where the current node is the head .
// Each of these child linked list is t=in the sorted order and connected by 'child' pointer .
// Your task is to flatten this linked such that all nodes appear in a single layer or leve; in a 'sorted order'.

// Sample Input 1 :
// 4
// 3
// 1 2 3
// 3
// 8 10 15
// 2
// 18 22
// 1
// 29


// Sample Output 1 :
// 1 2 3 8 10 15 18 22 29

// SOLUTION
Node *mergeLL(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if (a)
    {
        temp->child = a;
    }
    else
    {
        temp->child = b;
    }
    return res->child;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *down = head;
    Node *right = head->next;
    right = flattenLinkedList(right);
    down->next = NULL;
    Node *ans = mergeLL(down, right);

    return ans;
}
