struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return NULL;
  if (root == p || root == q) return root;
  struct TreeNode *L = lowestCommonAncestor(root->left, p, q);
  struct TreeNode *R = lowestCommonAncestor(root->right, p, q);
  if (L && R) return root;  // if p and q are on both sides
  return L ? L : R;  // either one of p,q is on one side OR p,q is not in L&R subtrees
}
