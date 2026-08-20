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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // column -> (row, value)
        map<int, vector<pair<int, int>>> mp;
        
        // node, row, column
        queue<tuple<TreeNode*, int, int>> q;
        
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            
            auto [node, row, col] = q.front();
            q.pop();
            
            if (node == nullptr)
                continue;
            
            // Store row and value for this column
            mp[col].push_back({row, node->val});
            
            // Left child: row + 1, col - 1
            q.push({node->left, row + 1, col - 1});
            
            // Right child: row + 1, col + 1
            q.push({node->right, row + 1, col + 1});
        }
        
        vector<vector<int>> ans;
        
        for (auto &it : mp) {
            
            // First sort by row
            // If row is same, sort by value
            sort(it.second.begin(), it.second.end());
            
            vector<int> column;
            
            for (auto &[row, value] : it.second) {
                column.push_back(value);
            }
            
            ans.push_back(column);
        }
        
        return ans;
    }
};