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
    int maxDepth(TreeNode* root) {
        /*
        if(root== NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return max(lh,rh)+1;
        */

        if(root== NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth =0;
        while(q.size()>0)
        {
            int n= q.size();
            depth++;
            for(int i=0; i<n; i++)
            {
                TreeNode* curr =q.front();
                q.pop();

                if(curr->left != NULL)
                {
                    q.push(curr->left);
                    
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                    
                }
            }

        }
        return depth;

        
    }
};