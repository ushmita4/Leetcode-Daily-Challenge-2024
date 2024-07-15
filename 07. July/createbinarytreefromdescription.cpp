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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp;
        unordered_map<int ,bool> hasParent;

        for(auto it: descriptions)
        {
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];

            TreeNode* parentNode =NULL;
            TreeNode* childNode =NULL;

            if(mp.find(parent) == mp.end())
            {
                parentNode = new TreeNode(parent);
                mp[parent] = parentNode;
            }else
            {
                parentNode = mp[parent];
            }


             if(mp.find(child) == mp.end())
            {
                childNode = new TreeNode(child);
                mp[child] = childNode;
            }else
            {
                childNode = mp[child];
            }

            if(isLeft == 1)
            {
                parentNode->left = childNode;
            }else
            {
                parentNode->right = childNode;
            }

            hasParent[child] = true;

        }

        TreeNode* root = NULL;

        for(auto it:mp)
        {
            if(hasParent.find(it.first) == hasParent.end())
            {
                root = it.second;
            }
        }


        return root;

    }
};
