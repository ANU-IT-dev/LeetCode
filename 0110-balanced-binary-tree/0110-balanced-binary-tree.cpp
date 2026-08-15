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
  int height(TreeNode*root)
  {
    if(root==NULL) return true;
     int leftht = height( root->left);
      if(leftht==-1) return -1;
     int rightht = height( root->right);
      if(rightht == -1) return -1;

      if( abs(leftht-rightht)>1) return -1;
      return max(leftht,rightht)+1;

  }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
        

    }
};