class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        bstToGstHelper(root, nodeSum);
        return root;
    }

private:
    void bstToGstHelper(TreeNode* root, int& nodeSum) {
        if (!root) {
            return;
        }

        bstToGstHelper(root->right, nodeSum);
        nodeSum += root->val;
        root->val = nodeSum;
        bstToGstHelper(root->left, nodeSum);
    }
};
