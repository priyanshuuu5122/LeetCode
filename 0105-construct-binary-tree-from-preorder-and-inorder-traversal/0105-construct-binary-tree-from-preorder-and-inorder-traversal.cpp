/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int left, int right) {

        // Base Case
        if (left > right)
            return NULL;

        // Current root from preorder
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = mp[rootValue];

        // Build left subtree
        root->left = solve(preorder, inorder, left, mid - 1);

        // Build right subtree
        root->right = solve(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};