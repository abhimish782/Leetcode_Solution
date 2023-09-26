/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        helper(original,cloned,target);
        return ans;
    }
    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==nullptr||target==nullptr) return;
        helper(original->left,cloned->left,target);
        if(original==target) {
            ans=cloned;
            return;
        }
        helper(original->right,cloned->right,target);
    }
};
