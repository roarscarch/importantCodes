vector<int> getPath(TreeNode* root, int value) {
    vector<int> path;
    bool isFound = getPathHelper(root, value, path);
    if (!isFound) path.clear();
    return path;
}

bool getPathHelper(TreeNode* root, int value, vector<int> &path) {
    if (!root) return false;
    path.push_back(root->val);
    if (root->val == value) return true;
    if (getPathHelper(root->left, value, path) || getPathHelper(root->right, value, path))
        return true;
    path.pop_back();
    return false;
}
