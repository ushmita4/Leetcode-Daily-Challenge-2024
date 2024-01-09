class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string seq1 = "";
        string seq2 = "";

        buildSeq(root1, seq1);
        buildSeq(root2, seq2);

        return seq1 == seq2;
    }
private:
    void buildSeq(TreeNode * root, string & seq){
         if(root == NULL)return;
         if(root->left == NULL && root->right == NULL){
             seq += (to_string(root->val) + " ");
             return;
         }
         buildSeq(root->left, seq);
         buildSeq(root->right, seq);
    }
};
