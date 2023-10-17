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
class Solution1 {
public:
    int csum;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        csum+=root->val;
        if(csum==targetSum&&root->left==NULL&&root->right==NULL) return true;
        if(hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum)) return true;
        csum-=root->val;
        return false;
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        if(!root->left&&!root->right&&root->val==targetSum) return true;
        int ans=false;
        if(root->left){
            ans=hasPathSum(root->left,targetSum-root->val);
        }
        if(root->right){
            ans=ans||hasPathSum(root->right,targetSum-root->val);
        }
        return ans;
    }
};
