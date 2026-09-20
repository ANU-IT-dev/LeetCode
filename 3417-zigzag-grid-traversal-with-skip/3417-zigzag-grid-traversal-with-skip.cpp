class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        bool take =true;
        for(int i=0; i< grid.size();i++)
        {
            if(i%2==0)
            {
                for(int j=0; j< grid[i].size();j++)
            {
                if(take)
            {
                ans.push_back(grid[i][j]);
            }
            take = !take;
            }

            }
            else
            {
                for(int j=grid[i].size()-1; j>=0;j--)
            {
                if(take)
               {
                ans.push_back(grid[i][j]);
               }
               take =!take;

            }
            

            }
            
        }
        return ans;
        
    }
};