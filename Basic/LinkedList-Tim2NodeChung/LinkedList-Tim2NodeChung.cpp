int len1 = 0, len2 = 0;
SinglyLinkedListNode *p1 = head1, *p2 = head2;

while (p1 != nullptr) {
    len1++;
    p1 = p1->next;
}

while (p2 != nullptr) {
    len2++;
    p2 = p2->next;
}

p1 = head1;
p2 = head2;

if (len1 > len2) {
    for (int i = 0; i < len1 - len2; i++) {
        p1 = p1->next;
    }
} else {
    for (int i = 0; i < len2 - len1; i++) {
        p2 = p2->next;
    }
}

while (p1 != nullptr && p2 != nullptr && p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
}

return p1;
