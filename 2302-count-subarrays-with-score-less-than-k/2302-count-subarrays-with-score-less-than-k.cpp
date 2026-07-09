class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n= nums.size();
        int l =0;
        int r=0;
        long long sum =0;
        long long score;
        long long count=0;
        while(r<n)
        {
            sum+=nums[r];
            score = sum*(r-l+1);
            while(l<=r && sum*(r-l+1)>=k)
            {
                
                sum-=nums[l];
                l++;
            }
            
            count+=(r-l+1);
            r++;

        }
        return count;
        
    }
};