    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);

    if (head == NULL || head->data >= x) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    SinglyLinkedListNode* cur = head;
    while (cur->next != NULL && cur->next->data < x) cur = cur->next;

    newNode->next = cur->next;
    cur->next = newNode;
    return head;
