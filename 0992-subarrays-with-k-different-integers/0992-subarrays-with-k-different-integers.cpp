class Solution {
public:
    int func(vector<int>& nums, int k)
    {
        int l=0; int r =0;
        int count =0;
        unordered_map<int, int>mpp;
        int n =nums.size();
        while(r<n)
        {
            mpp[nums[r]]++;
            while(mpp.size()>k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size()<=k)
            {
                count+=(r-l+1);
            }
            r++;

        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return (func(nums,k)- func(nums,k-1) );
    }
};