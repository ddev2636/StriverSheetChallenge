Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *dummyNode1 = firstHead;
    Node *dummyNode2 = secondHead;
    while (dummyNode1 != dummyNode2)
    {
        if (dummyNode1 == NULL)
            dummyNode1 = secondHead;
        if (dummyNode2 == NULL)
            dummyNode2 = firstHead;
        dummyNode1 = dummyNode1->next;
        dummyNode2 = dummyNode2->next;
    }
    return dummyNode1;
}