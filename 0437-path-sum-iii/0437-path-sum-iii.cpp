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
    
    int countfromnode( TreeNode* root, long long targetSum)
    {
        int count =0;
        if(root== NULL) return 0;
         if(root->val== targetSum)
         {
             count++;

         }
         count+=countfromnode(root->left, targetSum- root->val);
         count+=countfromnode(root->right , targetSum- root->val);
         return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root== NULL) return 0;
        int count = countfromnode(root, targetSum);
        count+= pathSum(root->left, targetSum);
        count+= pathSum(root->right , targetSum);

        return count;
    }
};