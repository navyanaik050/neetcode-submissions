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
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MAX, LONG_MIN);
    }

    bool valid (TreeNode *node, long right, long left){
        if (!node) return true;

        if (!(left < node-> val && right > node->val)){
            return false;
        }

        return valid (node->left, node->val, left) &&
                valid (node->right, right, node->val);
    }

};
