/*
    Time Complexity : O(n)
    Space Complexity: O(1)

    Where n denotes the size of the linked list.
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{

    // Base condition.
    if (head == NULL)
    {
        return head;
    }

    int len = 1;
    Node *temp = head;

    // Calculate length of the linked list.
    while (temp->next != NULL)
    {
        temp = temp->next;
        len += 1;
    }

    // If k is greater than k bring it in range of 0 - len.
    if (len < k)
    {
        k = k % len;
    }

    k = len - k;

    // Number of rotations are same as len so no change in LL.
    if (k == len || k == 0)
    {
        return head;
    }

    int count = 1;
    Node *current = head;

    while (count < k && current != NULL)
    {
        current = current->next;
        count += 1;
    }

    if (current == NULL)
    {
        return head;
    }

    // Changing pointers.
    temp->next = head;
    head = current->next;
    current->next = NULL;

    return head;
}
