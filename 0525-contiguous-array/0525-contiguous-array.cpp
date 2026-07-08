class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mp;
        int currsum=0;
        mp[0]= -1;
        int length=0;
        for(int i=0; i<n;i++)
        {
            currsum+= (nums[i]==1)?1:-1;
            if(mp.find(currsum)!= mp.end())
            {
                length = max( length,i- mp[currsum]);
            }
            else
            {
                mp[currsum]=i;
            }
        }
        return length;
       
        
    }
};