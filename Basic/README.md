# DSA Basic-Assignment3

Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 245202825

## 	Kiểm tra biểu thức toán học (Latex)
Bài này để kiểm tra dãy ngoặc hợp lệ chúng ta dùng stack
```C++
stack<char> st;

rep(i, 0, n - 1) {
    char c = s[i];
    if (c == '(' || c == '[' || c == '{') {
        st.push(c);
    }
    else if (c == ')' || c == ']' || c == '}') {
        if (st.empty()) {
            // Nếu có ngoặc đóng mà trước đó không tồn tại ngoặc mở -> SAI  
            cout << 0;
            return;
        }
        char op = st.top();
        if ((c == ')' && op != '(') || (c == ']' && op != '[') || (c == '}' && op != '{')) {
            // Nếu dãy ngoặc đóng hiện tại không khớp với cái ngoặc mở gần nhất -> SAI  
            cout << 0;
            return;
        }
        st.pop();
    }
}

// Dãy hợp lệ khi dãy ngoặc đóng = Dãy ngoặc mở nên size st = 00
if (st.size()) cout << 0;
else cout << 1;
```
## LinkedList-Insertion	
```C++
SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);

// Nếu phần tử đầu tiên < x và khác rỗng thì chèn vàovào
if (head == NULL || head->data >= x) { 
    newNode->next = head;
    head = newNode;
    return head;
}

// Tìm phần tử node có giá trị < x và chèn vào 
SinglyLinkedListNode* cur = head;
while (cur->next != NULL && cur->next->data < x) cur = cur->next;

newNode->next = cur->next;
cur->next = newNode;
return head;
```
## LinkedList-NhapDaThuc	

Bài toán này đơn giản là viết hàm Nhap, TinhDaThuc, Xuat dựa trên template. 

## LinkedList-Reverse

```C++
// Thêm node 
void insert_node(SinglyLinkedList* llist, int llist_item) { 
    SinglyLinkedListNode* node = new SinglyLinkedListNode(llist_item);

    if (llist->head == nullptr) llist->head = node;
    else llist->tail->next = node;

    llist->tail = node;
}

// Reverse 
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
```

## Dec to Bin	

Bài toán đơn giản là chia 2 và lưu lại số dư khi chia 2 cho đến khi chia 2 không được nữa.

```C++
cin >> n;
while (n) {
    int t = n % 2;
    res.push_back(t);
    n /= 2;
}

repd(i, sz(res) - 1, 0) cout << res[i];
```

## LinkedList: MergetwoSortedLinkedList	
```C++ 
// Tạo T để quản lý danh sách mới
SinglyLinkedListNode T(0);
SinglyLinkedListNode* tail = &T;

// So sánh cái nào nhỏ hơn thì đưa vào danh sách mới
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

// merge phần dư còn lại của danh sách
if (head_list1 != nullptr) tail->next = head_list1;
else tail->next = head_list2;

// Lúc này node đầu của ds là T.next 
return T.next;
```

## Tree: Preorder Traversal (NLR) - Duyệt cây BST theo NLR	

```C++
// Nếu node hiện tại là NULL thì return 
if (root == NULL) return;

cout << root->data << " ";

// Duyệt trái 
preOrder(root->left);

// Duyệt phải 
preOrder(root->right);
```
## Tree: Preorder Traversal (NLR) II - Duyệt cây BST theo NLR không đệ quy	
Về cơ bản ý tưởng vẫn sẽ là duyệt trái và duyệt phải của cây, nhưng ở đây chúng ta sử dụng stack.
```C++
// Cây rỗng thì return
if (root == nullptr) return;

stack<Node*> st;
st.push(root); // Đẩy root vào stack

while (st.size()) {
    Node* cur = st.top();
    st.pop();

    cout << cur->data << " ";

    // Duyệt phải
    if (cur->right != nullptr) st.push(cur->right);

    // Duyệt trái 
    if (cur->left != nullptr) st.push(cur->left);
}
```
## LinkedList: Tìm nút chung của 2 danh sách liên kết đơn	
Ý tưởng giống như tìm LCA, ở đây gọi len1, len2 lần lượt là size của 2 LinkedList xong rồi xét các trường hợp len1 > len2, len1 < len2. Sau đó nhảy đến 2 node ở cùng size với nhau.  Tiếp theo là nhảy cùng nhau cho đến khi 2 con trỏ chạm nhau thì đó là cha chung.

```C++
int len1 = 0, len2 = 0;
SinglyLinkedListNode *p1 = head1, *p2 = head2;

// Tính size của 2 LinkedListLinkedList
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

// TH1: len1 > len2
if (len1 > len2) {
    for (int i = 0; i < len1 - len2; i++) {
        p1 = p1->next;
    }
} else { // TH2: len1 <= len2
    for (int i = 0; i < len2 - len1; i++) {
        p2 = p2->next;
    }
}

// Nhảy cùng nhau cho đến khi 2 con trỏ chạm nhaunhau
while (p1 != nullptr && p2 != nullptr && p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
}

return p1;
```
## Binary Search Tree: Nút tổ tiên thấp nhất (tiếng Việt)	
Node x là lca của v1, v2 khi và chỉ khi x là root của cây con thấp nhất chứa v1, v2. 
```C++
if (root == NULL) return NULL;

// Nếu root->data đều lớn hơn cả v1 và v2
if (v1 < root->data && v2 < root->data)
    return lca(root->left, v1, v2);

// Nếu root->data đều bé hơn cả v1 và v2
if (v1 > root->data && v2 > root->data)
    return lca(root->right, v1, v2);

return root;
```