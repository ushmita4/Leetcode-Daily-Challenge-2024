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

    void deleteNode(TreeNode* &root, unordered_set<int> &st)
    {
        if(root==NULL)
        return;
        if(st.count(root->val))
        {
            root = NULL;
            return;
        }
    }

    void traverse(TreeNode* &root, unordered_set<int> &st, vector<TreeNode*> &res)
    {
        if(root==NULL) return;

        traverse(root->left, st, res);
        traverse(root->right, st, res);

        if(st.count(root->val))
        {
            if(root->left and !st.count(root->left->val))
            {
                res.push_back(root->left);
            }
            if(root->right and !st.count(root->right->val))
            {
                res.push_back(root->right);
            }
            deleteNode(root, st);
        }
    }

public:

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> st(to_delete.begin(), to_delete.end()); 
        vector<TreeNode*> res;

        traverse(root, st, res);
        deleteNode(root, st); 

        if(root)
        res.push_back(root); 

        return res;
    }

};
