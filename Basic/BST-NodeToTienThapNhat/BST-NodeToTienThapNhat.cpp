if (root == NULL) return NULL;

if (v1 < root->data && v2 < root->data)
    return lca(root->left, v1, v2);

if (v1 > root->data && v2 > root->data)
    return lca(root->right, v1, v2);

return root;
