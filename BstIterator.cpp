class BSTIterator {
public:
    vector<int>inorder;
    int idx;
    BSTIterator(TreeNode* root) {
        getInorder(root);
        this->idx=0;
    }
    
    int next() {
        int ans= inorder[idx];
        idx++;
        return ans;
    }
    
    bool hasNext() {
        if(idx!=inorder.size()) return true;
        return false;
    }
    void getInorder(TreeNode*root){
        if(root==nullptr) return;
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
    }
};
