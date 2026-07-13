class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i: nums)
        {
            mp[i]++;
        }
        if((nums.size()%k)!=0) return false;
        for(auto [i,freq]: mp)
        {
            while(freq--)
            {
                if(mp[i]==0) continue;
                for( int curr=i;curr < i+k;curr++)
                {
                    if(mp[curr]==0) return false;
                     mp[curr]--;
                }
            }
        }
        return true;
    }
};