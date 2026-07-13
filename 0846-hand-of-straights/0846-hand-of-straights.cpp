class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(auto h: hand)
        {
            mp[h]++;
        }
        if((hand.size()% groupSize) !=0) return false;
        for(auto[h,freq]:mp)
        {
            if(freq==0) continue;
            while(freq--)
            {
                for(int curr=h; curr< h+groupSize;curr++)
                {
                    if(mp[curr]==0)
                    {
                        return false;
                    }
                    mp[curr]--;
                }
            }
        }
        return true;
        
    }
};