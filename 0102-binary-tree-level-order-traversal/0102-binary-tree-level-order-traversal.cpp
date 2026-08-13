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
   vector<vector<int>>ans;
   void levelorder(TreeNode* root)
   {
    if(root== NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()>0)
    {
        int n =q.size();
        vector<int>level;
        for(int i=0; i<n; i++)
        {
            TreeNode* curr= q.front();
            q.pop();
         
          level.push_back(curr->val);
        
        if(curr->left !=NULL)
         {
            q.push(curr->left);
         }
         if(curr->right != NULL)
         {
            q.push( curr->right);
         }

        }
        
         ans.push_back(level);
    }
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelorder(root);
        return ans;

        
    }
};