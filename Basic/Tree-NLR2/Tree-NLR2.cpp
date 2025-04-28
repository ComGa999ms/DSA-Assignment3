if (root == nullptr) return;

stack<Node*> st;
st.push(root);

while (st.size()) {
    Node* cur = st.top();
    st.pop();

    cout << cur->data << " ";

    if (cur->right != nullptr) st.push(cur->right);
    if (cur->left != nullptr) st.push(cur->left);
}
