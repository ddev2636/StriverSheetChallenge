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

LinkedListNode<int> *reverseLL(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *front = head;

    while (curr != NULL)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{

    // base case
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // find middle node of LL
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *middle = NULL;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    middle = slow;

    // reverse 2nd half
    middle->next = reverseLL(middle->next);

    // compare each half
    while (middle->next != NULL)
    {
        if (middle->next->data != head->data)
        {
            return false;
        }
        head = head->next;
        middle->next = middle->next->next;
    }

    // undo the chnages in LL by reversing the 2nd half again
    middle->next = reverseLL(middle->next);

    return true;
}