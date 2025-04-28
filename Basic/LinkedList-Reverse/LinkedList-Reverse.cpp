void insert_node(SinglyLinkedList* llist, int llist_item) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(llist_item);

    if (llist->head == nullptr) llist->head = node;
    else llist->tail->next = node;

    llist->tail = node;
}

void reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* cur = llist->head;
    SinglyLinkedListNode* next = nullptr;

    llist->tail = llist->head;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    llist->head = prev;
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* cur = llist->head;
    while (cur != nullptr) {
        cout << cur->data << ' ';
        cur = cur->next;
    }
}
