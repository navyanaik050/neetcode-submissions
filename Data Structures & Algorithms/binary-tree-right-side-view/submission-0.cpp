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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        if(root == nullptr){
            return result;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            int level = nodeQueue.size();
            for(int i=0; i<level; i++){
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                if(i == level-1){
                    result.push_back(currentNode->val);
                }

                if(currentNode->left){
                    nodeQueue.push(currentNode->left);
                }

                if(currentNode->right){
                    nodeQueue.push(currentNode->right);
                }
            }
        }
        return result;
    }
};
