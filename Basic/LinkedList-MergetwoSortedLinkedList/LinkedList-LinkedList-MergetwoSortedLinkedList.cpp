SinglyLinkedListNode T(0);
SinglyLinkedListNode* tail = &T;

while (head_list1 != nullptr && head_list2 != nullptr) {
    if (head_list1->data <= head_list2->data) {
        tail->next = head_list1;
        head_list1 = head_list1->next;
    } else {
        tail->next = head_list2;
        head_list2 = head_list2->next;
    }
    tail = tail->next;
}

if (head_list1 != nullptr) tail->next = head_list1;
else tail->next = head_list2;

return T.next;
