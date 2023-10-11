class Solution {
public:
    unordered_map<Node *, int> height;

    bool isBalanced(Node *root) {
        if (!root)
            return true;

        bool ok = isBalanced(root->left) && isBalanced(root->right);
        int left = height[root->left];
        int right = height[root->right];

        ok = ok && (abs(left - right) <= 1);
        height[root] = max(left, right) + 1;

        return ok;
    }
};
