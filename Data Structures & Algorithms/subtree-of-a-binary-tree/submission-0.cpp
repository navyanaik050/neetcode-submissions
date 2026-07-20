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
    bool isSameTree(TreeNode* tree1, TreeNode* tree2){
        if(!tree1 || !tree2){
            return tree1 == tree2;
        }

        return tree1->val == tree2->val &&
                isSameTree(tree1->left , tree2->left) &&
                isSameTree(tree1->right , tree2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        return isSameTree(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
        
    }


};
