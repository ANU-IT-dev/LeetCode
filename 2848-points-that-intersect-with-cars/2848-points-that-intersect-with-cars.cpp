class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> visited(101,false);
        for(auto &car:nums)
        {
            int start =car[0];
            int end = car[1];
        
        for(int i= start; i<= end;i++)
        {
            visited[i]= true;

        }
        }
        int count =0;
        for(int i=0; i<=100;i++)
        {
            if(visited[i])
             count++;

        }
        return count;
        
    }
};